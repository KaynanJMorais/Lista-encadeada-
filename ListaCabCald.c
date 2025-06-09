#include <stdlib.h>
#include <stdio.h>

typedef struct nolista{
    int info;
    struct nolista *prox;
}NoLista;

typedef struct lista{
    NoLista *cab;
    NoLista *cau;
}Lista;

void criarlista(Lista *l){
    l->cab=(NoLista*)malloc(sizeof(NoLista));
    l->cau=(NoLista*)malloc(sizeof(NoLista));
    l->cab->prox=l->cau;
    l->cau->prox=NULL;
}

int estavazia(Lista *l){
    if(l->cab->prox==l->cau){
        return 1;
    }
    return 0;
}

void inseririnicio(Lista *l, int v){
    NoLista *novo=(NoLista*)malloc(sizeof(NoLista));
    if(novo!=NULL){
        novo->info=v;
        novo->prox=l->cab->prox;
        l->cab->prox=novo;
    }
    else{
        printf("Memory cant be allocated");
    }
}

void imprime(Lista *l){
    printf("Lista:\n");
    if(!estavazia(l)){
        NoLista *p;
        for(p=l->cab->prox; p!=l->cau;p=p->prox){
            printf("%d ", p->info);
        }
        printf("\n");
    }
    else{
        printf("Lista vazia\n");
    }
}

void inserirfim(Lista *l, int v){
    NoLista *novo=(NoLista*)malloc(sizeof(NoLista));
    if(novo!=NULL){
        novo->prox=NULL;
        l->cau->info=v;
        l->cau->prox=novo;
        l->cau=novo;
    }
    else{
        printf("Memory cant be allocated");
    }
}

void imprimenova(Lista *l){
    if(!estavazia(l)){
    printf("Lista Atualizada:\n");
        NoLista *p;
        for(p=l->cab->prox; p!=l->cau;p=p->prox){
            printf("%d ", p->info);
        }
        printf("\n");
    }
    else{
        printf("Lista vazia\n");
    }
}

void removerelemento(Lista *l, int v){
    NoLista *ant = NULL;
    NoLista *p;
    for(p=l->cab->prox; p!=l->cau&&p->info!=v;p=p->prox){
        ant = p;
    }
    if(p==l->cau){
        printf("Cant found the element");
        }
    else{
        ant->prox=p->prox;
        free(p);
    }
}

void liberarlista(Lista *l){
    NoLista *p;
    NoLista *temp;
    for(p=l->cab->prox; p!=l->cau; p=temp){
        temp=p->prox;
        free(p);
    }
    l->cab->prox = l->cau = NULL;
    l->cau=0;
}

void liberarlista2(Lista *l){
    if(!estavazia(l)){
        for(NoLista *p=l->cab->prox; p!=l->cau;p=l->cab->prox){
            l->cab->prox=p->prox;
            free(p);
        }
    }
}

int main(){
    Lista lista;
    criarlista(&lista);
    inseririnicio(&lista, 9);
    inseririnicio(&lista, 7);
    inseririnicio(&lista, 12);
    inseririnicio(&lista, 3);
    imprime(&lista);
    inserirfim(&lista, 5);
    inserirfim(&lista, 7);
    imprimenova(&lista);
    removerelemento(&lista, 5);
    imprimenova(&lista);
    liberarlista2(&lista);
    imprimenova(&lista);
}