#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int fib(int n){
    if(n == 1){
       return 0;
    }
    else if(n == 2){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}
int fabio(int n){
    int a,b,c;
        if(n<=1){
            return 0;
        }
        if(n==2){
            return 1;
        }
        else{
            a=0;
            b=1;
        }
    for(int i=0; i<n-2; i++){
        c = a+b;
        a=b;
        b=c;
    }
    return b;
}

int main(){
    int n,resultado,j;
    printf("Digite um numero:\n");
    scanf("%d", &n);

    resultado = fib(n);
    printf("resultado: %dzn", resultado);
    j = fabio(n);
    printf("resultado: %d", j);
}
