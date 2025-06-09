#include <stdlib.h>
#include <stdio.h>

void trocar(int *x, int *y){
    int a;
    a = *x;
    *x = *y;
    *y = a;
}

int main(){
    int x,y;
    printf("X:\n");
    scanf("%d", &x);
    printf("Y:\n");
    scanf("%d", &y);

    trocar(&x, &y);
    printf("%d %d", x,y);
}
