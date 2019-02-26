#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 5
//na filha simples � adicionado ao final da fila, e � retirado do come�o
//lembrando que na fila simples n�o tem sobreposi��o de lugar, se � s� 5 � so 5 nada mais
//n�o pode ser adicionado mais, caso for sendo retirado
void adionar(int num);
void retirar();
void imprimir();
void menu();
int inicio = 0, fim = 0, i, op = 0, fila[TAMANHO], numero;

void menu(){
    printf("\n\nPROGRAMA DE FILA SIMPLES\n\n");
    printf("1 - Adicionar\n");
    printf("2 - Retirar\n");
    printf("3 - Sair\n");
    printf("Opcao: ");
    scanf("%d",&op);
}
void adicionar(int num){
    if(fim == TAMANHO){
        printf("\n\nA pilha esta cheia!\n\n\a");

    }else{
        fila[fim] = num;
        fim++;
    }
}
void retirar(){
    int num;
    if(inicio == fim)
    {
        printf("\n\nA PILHA ESTA VAZIA\n\n\a");
    }else{
        num = fila[inicio];
        inicio++;
        return num;
    }
}
void imprimir(){
    for(i=inicio;i<fim;i++){
        printf(" %d  ",fila[i]);
    }
}


int main()
{
    while(op != 3){
        menu();
        switch(op){
                case 1:
                printf("Digite um numero para adicionar : ");
                scanf("%d", &numero);
                adicionar(numero);
                imprimir();
            break;
                case 2:
                retirar();
                imprimir();
            break;
        }

    }
    return 0;
}
