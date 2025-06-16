#include <stdlib.h>
#include <stdio.h>

typedef struct nolista {
    int info;
    struct nolista *prox;
    struct nolista *ant;
} NoLista;

int estaVazia(NoLista **L) {
    return (*L == NULL);
}

NoLista *ultimoElemento(NoLista **l) {
    if (!estaVazia(l)) {
        NoLista *p;
        for (p = *l; p->prox != NULL; p = p->prox);
        return p;
    } else {
        return NULL;
    }
}

void removerElemento(NoLista **L, int v) {
    if (!estaVazia(L)) {
        NoLista *p = *L;
        while (p != NULL && p->info != v)
            p = p->prox;

        if (p == NULL) {
            printf("Elemento nao encontrado\n");
            return;
        }

        if (p->ant == NULL && p->prox == NULL) {
            // único elemento
            *L = NULL;
        } else if (p->ant == NULL) {
            // primeiro
            *L = p->prox;
            p->prox->ant = NULL;
        } else if (p->prox == NULL) {
            // último
            p->ant->prox = NULL;
        } else {
            // meio
            p->ant->prox = p->prox;
            p->prox->ant = p->ant;
        }
        free(p);
    } else {
        printf("Lista vazia\n");
    }
}

void imprimeOrdemInversa(NoLista **l) {
    if (!estaVazia(l)) {
        for (NoLista *p = ultimoElemento(l); p != NULL; p = p->ant)
            printf("%d ", p->info);
        printf("\n");
    } else {
        printf("Lista vazia!\n");
    }
}

void criarlista(NoLista **L) {
    *L = NULL;
}

void insereElementos(NoLista **L, int v) {
    NoLista *novo = malloc(sizeof(NoLista));
    if (novo != NULL) {
        novo->info = v;
        novo->prox = *L;
        novo->ant = NULL;
        if (*L != NULL) (*L)->ant = novo;
        *L = novo;
    } else {
        printf("Nao foi possivel alocar espaco\n");
    }
}

void quantidadeElementos(NoLista **L) {
    if (!estaVazia(L)) {
        int n = 0;
        for (NoLista *p = *L; p != NULL; p = p->prox)
            n++;
        printf("Quantidade de elementos: %d\n", n);
    } else {
        printf("Lista vazia\n");
    }
}

void imprimir(NoLista **L) {
    printf("LISTA:\n");
    if (!estaVazia(L)) {
        for (NoLista *p = *L; p != NULL; p = p->prox)
            printf("%d\n", p->info);
        printf("\n");
    } else {
        printf("Lista vazia\n");
    }
}

NoLista* busca(NoLista **L, int v) {
    for (NoLista *p = *L; p != NULL; p = p->prox) {
        if (p->info == v)
            return p;
    }
    return NULL;
}

void liberarLista(NoLista **L) {
    NoLista *p, *temp;
    for (p = *L; p != NULL; p = temp) {
        temp = p->prox;
        free(p);
    }
    *L = NULL;
}

void insereOrdenado(NoLista **L, int v) {
    NoLista *p, *ant = NULL;
    for (p = *L; p != NULL && p->info < v; p = p->prox)
        ant = p;

    NoLista *novo = (NoLista*)malloc(sizeof(NoLista));
    if (novo != NULL) {
        novo->info = v;
        novo->ant = ant;
        novo->prox = p;

        if (p != NULL)
            p->ant = novo;

        if (ant == NULL) {
            *L = novo;
        } else {
            ant->prox = novo;
        }
    } else {
        printf("Nao foi possivel alocar espaco\n");
    }
}

int main() {
    NoLista *lista;
    criarlista(&lista);

    insereElementos(&lista, 3);
    insereElementos(&lista, 2);
    insereElementos(&lista, 1);
    insereElementos(&lista, 6);

    imprimir(&lista);
    quantidadeElementos(&lista);

    if (busca(&lista, 3) != NULL)
        printf("ELEMENTO ENCONTRADO:\n");
    else
        printf("O ELEMENTO NAO ESTA NA LISTA\n");

    removerElemento(&lista, 2);
    imprimir(&lista);

    liberarLista(&lista);
    imprimir(&lista);

    insereOrdenado(&lista, 3);
    insereOrdenado(&lista, 5);
    insereOrdenado(&lista, 8);
    imprimir(&lista);

    NoLista* ult = ultimoElemento(&lista);
    if (ult != NULL)
        printf("Ultimo elemento: %d\n", ult->info);
    else
        printf("Lista vazia\n");

    printf("Impressão inversa:\n");
    imprimeOrdemInversa(&lista);

    liberarLista(&lista);
    return 0;
}