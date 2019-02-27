#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int main()
{
 int vet[MAX],i,j,sub;
    for(i=0;i<MAX;i++){
        printf("\nDigite o numero: ");
        scanf("%d",&vet[i]);
        system("cls");
    }

    for(i=0;i<MAX;i++)
        printf(" %d ",vet[i]);

    for(i=0;i<MAX-1;i++){
        for(j=i+1;j<MAX;j++){
            if(vet[j] < vet[i]){
                sub = vet[i];
                vet[i] = vet[j];
                vet[j] = sub;
            }
        }
    }

    printf("\n");
     for(i=0;i<MAX;i++)
        printf(" %d ",vet[i]);
    return 0;
}
