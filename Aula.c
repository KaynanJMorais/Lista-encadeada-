#include <stdlib.h>
#include <stdio.h>
#include <string.h>

float media(float *v, float n){
    float soma=0;
    for(int i=0; i<n;i++){
        soma += v[i];
    }

    return soma/n   ;
}

int main(){
    float *v;
    float test;
    int n;
    printf("Digite quantos num deseja calcular:\n");
    scanf("%d", &n);
    printf("Digite 10 numeros:\n");
    v = (float*) malloc(n*sizeof(float));

    if(v != NULL){
        for(int i=0; i<n;i++){
            scanf("%f", &v[i]);
        }
        test = media(v, n);
        printf("Resultado %.2f", test);

        free(v);
    }
    else{
        printf("ERRO AO ALOCAR NA MEMORIA");
    }


}