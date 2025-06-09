#include <stdlib.h>
#include <stdio.h>

typedef struct nome{
    char nome[30];
}Nome;

int main(){
Nome a;
printf("Digite seu nome:\n");
scanf("%[^\n]", a.nome);
printf("Nome: %s", a⟶nome);
return 0;
}

