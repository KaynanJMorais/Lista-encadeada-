#include <stdlib.h>
#include <stdio.h>

typedef struct nolista{
    int info;
    struct nolista *prox;
}NoLista;

typedef struct descritor{
    NoLista *prim;
    NoLista *ult;
    int n;
}Descritor;

void criarlista(Descritor *l){
    l->prim=l->ult=NULL;
    l->n=0;
}

int estavazia(Descritor *l){
    if(l->n==0){
        return 1;
    }
    else{
        return 0;
    }
}

void insererelementoinicio(Descritor *l, int v){
    NoLista *novo = malloc(sizeof(NoLista));
    if(novo!=NULL){
        novo->info=v;
        novo->prox=l->prim;
        l->prim=novo;
        if(l->n==0){
            l->ult=novo;
        }
        l->n++;
    }
    else{
        printf("N foi possivel alocar ispass");
    }
}

void imprimelista(Descritor *l){
    if(!estavazia(l)){
        NoLista *p;
        for(NoLista *p=l->prim;p!=NULL;p=p->prox){
            printf("%d\n",p->info);
        }
        printf("\n");
    }
    else{
        printf("Empty List\n");
    }
}

void insereirnofim(Descritor *l, int v){
    NoLista *novo=(NoLista*)malloc(sizeof(NoLista));
    if(novo!=NULL){
        novo->info=v;
        novo->prox=NULL;
        if(!estavazia(l)){
            l->ult->prox=novo;
            l->ult=novo;
        }
        else{
            l->ult=novo;
            l->prim=novo;
        }
        l->n++;
    }
    else{
        printf("Memory cant be allocated");
    }
}


void removeelemento(Descritor *l, int v){
    NoLista *ant=NULL;
    NoLista *p;
    for(p=l->prim; p!=NULL&&p->info!=v; p=p->prox){ /*Tenta char o valor que quero remover e deixa p como o anterior*/
        ant = p;
    }
    if(p==NULL){
        printf("Cant find the element");
    }
    else{
        if(ant==NULL){
            l->prim=p->prox;
            if(l->prim==NULL){
                l->ult = NULL;
            }
        }
        else{
            ant->prox=p->prox;
            if(ant->prox==NULL){
                l->ult = ant;
            }
        }
        free(p);
        l->n--;
    }
}

void liberarlista(Descritor *l){
    NoLista *p;
    NoLista *temp;
    for(p=l->prim; p!=NULL; p=temp){
        temp=p->prox;
        free(p);
    }
    l->prim = l->ult = NULL;
    l->n=0;
}

NoLista* busca(Descritor *l, int v){
    for(NoLista *p=l->prim; p!=NULL; p=p->prox){
        if(p->info==v){
            return p;
        }
    }
    return NULL;
}

int main(){
    Descritor lista;
    criarlista(&lista);
    insererelementoinicio(&lista, 5);
    insererelementoinicio(&lista, 6);
    insererelementoinicio(&lista, 9);
    imprimelista(&lista);
    insereirnofim(&lista, 3);
    insereirnofim(&lista, 4);
    imprimelista(&lista);
    removeelemento(&lista, 9);
    imprimelista(&lista);
    NoLista *p = busca(&lista, 5);
    liberarlista(&lista);
    imprimelista(&lista);
    if(p!=NULL){
        printf("Found it\n");
    }
    else{
        printf("not Found\n");
    }
}