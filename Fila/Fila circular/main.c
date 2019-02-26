#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 5

void adicionar(int num);
void retirar();
void imprimir();
void menu();
int inicio=0,fim=0,op=0,vazio=1, numero, fila[TAMANHO];

void menu(){
    system("cls");
    printf("\n\nPILHA CIRCULAR\n\n");
    printf("1 - Adicionar\n");
    printf("2 - Retirar\n");
    printf("3 - Sair\n");
    printf("Opcao: ");
    scanf("%d",&op);
}
void adicionar(int n){
    /*Existe duas variaveis chamada inicio e fim.
    se estiver vazia, vazio é igual a 1*/
    if(vazio == 1){
        fila[fim] = n;//ele ve que esta vazio e adciona no fim da fila um numero
        fim++;
        vazio = 0;//vazio passa pra 0, pois nao esta mais vazio
    }else{
         if(inicio == fim){//se o inicio for igual a fim na hora que esta advionando é pq esta cheia
            printf("\n\nPilha cheia!\n\n\a");
        }else{
            fila[fim] = n;//se não ele pode adcionar normalmente.
            fim++;
        }
    }
   if(fim == TAMANHO){//se o tamanho que é 5 for igual a fim é pq ele tem que dar a volta,
                    //fim volta a receber 0
        fim = 0;
    }
}
retirar(){
    int n;//na hora de tirar da fila, é tirado do inicio da fila,
        //ela circula, sempre sendo adcionado no fim da fila
    if(vazio == 1){
        printf("\n\n Pilha vazia\n\n\a");
    }else{
        n = fila[inicio];//recebe o fila na posicao inicio para retornar ele
        fila[inicio] = 0;//só para visualizar a retirada
        inicio++;//o inicio anda 1 que foi retirado
            if(inicio == TAMANHO){//se o inicio for igual a tamanho é pq a fila tem que dar a volta
                inicio = 0;//volta no começo
            }
            if(inicio == fim){//se inicio for igual a fim, é pq a fila ta vazia
                vazio = 1;
            }
        return n;//retorna o numero
    }
}
//apenas imprime os valores do vetor
void imprimir(){
    int i;
    for(i=0;i<5;i++){
        printf(" %d ",fila[i]);
    }
    printf("\n");
    system("pause");
}


int main()
{
    while(op != 3){
        menu();

        switch(op){
                case 1:
                   printf("Digite o numero a ser inserido: ");
                   scanf("%d",&numero);
                   adicionar(numero);
                   imprimir();
            break;
                case 2:
                   retirar();
                   imprimir();
            break;
                case 3:system("cls");
            break;
        }
    }


    return 0;
}
