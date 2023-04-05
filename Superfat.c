#include <stdio.h>
#include <stdlib.h>
int SuperFat(int fat){
    int fat1= 1, i;
    for(i = 1 ; i<=fat; i++){
        fat1= fat1 * i;

    }

    return fat1;
}

int main()
{
 int fat;
 int r = 1;
 printf("Digite o fatorial que voce deseja saber o Super fatorial: ");
 scanf("%d", &fat);
 while (fat != 0){
    r = r * SuperFat(fat);
    fat--;
 }


 printf("%d",r );


}
