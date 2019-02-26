#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 5
int vetor[TAMANHO],posicao = 0;
//Programa de PILHA, O PRIMEIRO A SER COLOCADO, É O ULTIMO A SER TIRADO


//Este bloco tem a unica função de exibir os elementos da PILHA
void exibir(){
    int i;
    if(posicao > 0)//caso haja algo na pilha ele imprime
        printf("\n+---+---+\n");
    for(i=posicao-1;i >= 0;i--){//ele começa em posicao menos um, pq a posicao sempre para um na frente
            //ele imprime do ultimo para o primeiro, afim de fazer uma pilha mesmo
        printf("| %d | %d |\n",i,vetor[i]);
        printf("+---+---+\n");

    }

}
void push(int num){//o push coloca um elemento no começo da pilha
        if(posicao >= TAMANHO){
            printf("\nSTACK OVERFLOW!\n");
        }else{
            vetor[posicao++] = num;
        }
}
void pop(){//o pop tira um elemento do final da pilha
    int i;
    if(posicao <= 0){
        printf("\n\nPILHA VAZIA! \n\n");
    }else{
        for(i=0;i<posicao;i++){
            if(posicao - 1 == i){
                posicao = i;
                return vetor[i];
            }
        }
    }

}
int main()
{
    int op=0,num;
    while(op != 3){
        printf("Programa de pilha\n");
        printf("1 - Push\n");
        printf("2 - Pop\n");
        printf("3 - Sair\n");
        printf("opcao: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("\nDigite o numero a ser colocado na pilha:");
                scanf("%d",&num);
                push(num);
                exibir();
        break;
            case 2:
                //chama a função pop e exibir
                pop();
                exibir();
        break;
            default:
                printf("\nTCHAU!\n");
        break;
        }
    }
    return 0;
}
