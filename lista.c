#include <stdlib.h>
#include <stdio.h>
#define MAX 10

typedef struct lista{
    int n;
    int itens[MAX];
}Lista;

Lista* criarlista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));
    if(l!=NULL){
        l->n = 0;
        return l;
    }
    else{
        printf("NAO FOI POSSIVEL ALOCAR ESPAÇO");
    }
}

int estaVazia(Lista *l){
    if(l->n == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int estaCheia(Lista *l){
    if(l->n == MAX){
        return 1;
    }
    else{
        return 0;
    }
}

void inserirElemento(Lista *l, int v){
    if(!estaCheia(l)==1){
        l->itens[l->n]=v;
        l->n++;
    }
}

void imprime(Lista *l){
    if(!estaVazia(l)){
        for(int i=0;i<l->n;i++){
            printf("%d\n", l->itens[i]);
        }
        printf("\n");
    }
}

void removerElemento(Lista *l, int i){
    if(i>=1 && i<=l->n){
        for(int x=1; x<l->n;x++){
            l->itens[x-1] = l->itens[x];
        }
        l->n--;
    }
}