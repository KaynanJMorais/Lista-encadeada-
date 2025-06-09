#include <stdlib.h>
#include <stdio.h>
char transf(char digite){
    return digite-32;
}
int main(){
    char digite;
    char inv;
    printf("Digite uma letra:\n");
    scanf("%c", &digite);

    inv = transf(digite);
    printf("A letra em Mai: %c", inv);
}