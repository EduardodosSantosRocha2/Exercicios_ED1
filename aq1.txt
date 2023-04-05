#include <stdio.h>
#include <stdlib.h>

void Uniao(int *vet1, int *vet2, int n, int *uniao){
    int i, j;
    for(i=0; i<n; i++){
       uniao[i] = vet1[i];
       uniao[i+n] = vet2[i];

    }


}



int main()
{
   int vet1[2];
   int vet2[2];
   int uniao[4];
   int i;
   for(i = 0; i<2;i++){
    printf("Digite o valor %d do primeiro vetor: ", i+1);
    scanf("%d",&vet1[i]);
   }
   for (i = 0; i<2; i++){
        printf("Digite o valor %d do segundo vetor: ", i+1);
        scanf("%d",&vet2[i]);
   }
   Uniao(vet1, vet2, 2, uniao);
   for(i= 0; i< 4; i++){
    printf("%d\n",uniao[i]);
   }



}
