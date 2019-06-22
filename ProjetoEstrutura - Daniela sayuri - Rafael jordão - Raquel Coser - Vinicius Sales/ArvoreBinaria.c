#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DuplamenteLigada.h"
#include "ListaDinamica.h"
#include "ArvoreBinaria.h"

char AB_ultimo_movimento = ' ';
void AB_inicializar()
{
    AB_inicio = 0;
}

void AB_adicionar(struct AB_no *AB_posicao, struct AB_no *AB_novo)
{
    if(AB_inicio == 0){
        AB_inicio = AB_novo;
    }else{
        if(AB_novo->AB_cpf > AB_posicao->AB_cpf){
            if(AB_posicao->direita == 0){
                AB_posicao->direita = AB_novo;

            }else{
                AB_adicionar(AB_posicao->direita, AB_novo);
            }
        }else{
            if(AB_posicao->esquerda == 0 ){
                AB_posicao->esquerda = AB_novo;
            }else{
                AB_adicionar(AB_posicao->esquerda, AB_novo);
            }
        }

    }

}

struct AB_no *AB_novo_no(int cpf, int registro)
{
    struct AB_no *AB_novo;

    AB_novo = malloc(sizeof(struct AB_no));
    if(!AB_novo)
    {
        printf("Nao consegui alocar memoria!\n");
        exit(-1);
    }
    AB_novo->esquerda = 0;
    AB_novo->AB_cpf = cpf;
    AB_novo->AB_registro = registro;
    AB_novo->direita = 0;

    return AB_novo;
}

void AB_finalizar(struct AB_no *AB_posicao)
{
    if(AB_posicao == 0){
        return 0;
    }else{
        if(AB_posicao->esquerda != 0){
            AB_finalizar(AB_posicao->esquerda);
            free(AB_posicao);
        }
        if(AB_posicao->direita != 0){
            AB_finalizar(AB_posicao->direita);
            free(AB_posicao);
        }
        free(AB_posicao);
    }
}

struct AB_no *AB_localizar(struct AB_no *AB_posicao, int cpf)
{
    if(AB_inicio == AB_posicao){
        AB_anterior = AB_inicio;
    }
    if(AB_posicao == 0)
        return 0;
    if(AB_posicao->AB_cpf == cpf)
        return AB_posicao;
    else
    {
        if(cpf > AB_posicao->AB_cpf && AB_posicao->direita != 0)
        {
            AB_anterior = AB_posicao;
            AB_ultimo_movimento = 'D';
            return AB_localizar(AB_posicao->direita, cpf);
        }
        if(cpf < AB_posicao->AB_cpf && AB_posicao->esquerda != 0)
        {
            AB_anterior = AB_posicao;
            AB_ultimo_movimento = 'E';
            return AB_localizar(AB_posicao->esquerda, cpf);
        }
    }
    return 0;
}


void AB_excluir(int cpf)
{
    if(AB_aux == AB_inicio)
        {
            AB_inicio = 0;
            if(AB_aux->esquerda != 0)
                AB_adicionar(AB_inicio, AB_aux->esquerda);
            if(AB_aux->direita != 0)
                AB_adicionar(AB_inicio, AB_aux->direita);
            free(AB_aux);
    }else{
            AB_aux = AB_localizar(AB_inicio, cpf);
            if(AB_aux == 0){
                printf("\nImpossivel excluir\n");
            }else{
                if(AB_ultimo_movimento == 'D')
                    AB_anterior->direita = 0;
                else{
                    AB_ultimo_movimento == 'E';
                    AB_anterior->esquerda = 0;
                }


                if(AB_aux->esquerda != 0){
                    AB_adicionar(AB_inicio, AB_aux->esquerda);
            }
                if(AB_aux->direita != 0){
                    AB_adicionar(AB_inicio, AB_aux->direita);
            }
            free(AB_aux);

        }
    }
}
