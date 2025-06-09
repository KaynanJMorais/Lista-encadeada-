#include <stdlib.h>
#include <stdio.h>

typedef struct nolista{
    int info;
    struct nolista *prox;
}NoLista;

void criarlista(NoLista **L){
    *L=NULL;
}

int estaVazia(NoLista **L){
    return(*L==NULL);
}

void insereElementos(NoLista **L, int v){
    NoLista *novo = malloc(sizeof(NoLista));
    if(novo!=NULL){
        novo->info=v;
        novo->prox=*L;
        *L=novo;
    }
    else{
        printf("No foi possivel alocar espaço");
        }
    
}


void quantidadeElementos(NoLista **L){
    if(!estaVazia(L)){
        int n=0;
        for(NoLista *p=*L;p!=NULL;p=p->prox){
            n++;
        }
        printf("%d\n", n);
    }
}

void removerElemento(NoLista **L, int v){
    NoLista *ant=NULL;
    NoLista *p;
    for(p = *L; p!=NULL&&p->info!=v; p=p->prox){
        ant = p;
    }
        if(p==NULL){
            printf("N ESTA NA LISTA");
        }
        else{
            if(ant==NULL){
                *L=p->prox;
            }
            else{
            ant->prox = p->prox;
            }
            free(p);
        }
}

void imprimir(NoLista **L){
    printf("LISTA:\n");
    if(!estaVazia(L)){
        for(NoLista *p=*L;p!=NULL;p=p->prox){
            printf("%d\n", p->info);
        }
        printf("\n");
    }
    else{
        printf("Lista vazia\n");
    }
}

NoLista* busca(NoLista **L, int v){
    for(NoLista *p = *L;p!=NULL;p=p->prox){
        if(p->info==v){
            return p;
        }
    }
    return NULL;
}

void liberarLista(NoLista **L){
    NoLista *p, *temp;
    for(p=*L; p!=NULL; p=temp){
        temp=p->prox;
        free(p);
    }
    *L = NULL;
}

void insereOrdenado(NoLista **L, int v){
    NoLista *p,*ant=NULL;
    for(p=*L; p!=NULL && p->info<v;p=p->prox){
        ant=p;
    }
    NoLista *novo=(NoLista*)malloc(sizeof(NoLista));
    if(novo!=NULL){
        novo->info=v;
        if(ant==NULL){
            novo->prox=*L;
            *L=novo;
        }
        else{
            novo->prox=p;
            ant->prox=novo;
        }
    }
    else{
        printf("N foi possivel alocar espasso");
    }
}

NoLista* ultimo(NoLista **L){
    if(!estaVazia(L)){
        NoLista *p;
        for(p=*L;p->prox!=NULL;p=p->prox){
            return p;
        }
    }
    return NULL;
}

int main(){
   NoLista *lista;
   criarlista(&lista);
   insereElementos(&lista, 3);
   insereElementos(&lista, 2);
   insereElementos(&lista, 1);
   insereElementos(&lista, 6);
   imprimir(&lista);
   quantidadeElementos(&lista);
   if(busca(&lista, 3)!=NULL){
    printf("ELEMENTO ENCONTRADO:\n");
   }
   else{
    printf("O ELEMENTO NAO ESTA NA LISTA\n");
   }
   removerElemento(&lista, 2);
   imprimir(&lista);
   liberarLista(&lista);
   imprimir(&lista);
   insereOrdenado(&lista,3);
   insereOrdenado(&lista,5);
   insereOrdenado(&lista,8);
   imprimir(&lista);
   NoLista *q=ultimo(&lista);
   printf("%d\n", q->info);
}