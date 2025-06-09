#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#define MAX 10

int main(){
    Lista *lista = criarlista();

    inserirElemento(lista, 5);
    inserirElemento(lista, 6);
    imprime(lista);
    removerElemento(lista, 1);
    imprime(lista);
}
