#include <stdio.h>
#include <stdlib.h>

void Conta(int *a, int *b){
    int soma, A;
    soma = *a + *b;
    A = *a;
    *a = soma;
    if(A > *b){
        *b = A;
    }
    else{
        *b = *b;
    }



}



int main()
{
    int a;
    int b;
    printf("Digite o valor a: ");
    scanf("%d",&a);
    printf("Digite o valor b: ");
    scanf("%d",&b);
    Conta(&a,&b);
    printf("%d, %d", a, b);

}
