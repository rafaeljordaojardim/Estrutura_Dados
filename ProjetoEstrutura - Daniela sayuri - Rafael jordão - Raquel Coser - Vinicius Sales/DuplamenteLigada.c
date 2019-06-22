#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DuplamenteLigada.h"
#include "ListaDinamica.h"


void DL_inicializar()
{
    DL_inicio = 0;
}

struct DL_no * DL_novo_no(char *nome, int registro)
{
    struct DL_no *n;
    n = malloc(sizeof(struct DL_no));
    if(!n)
    {
        printf("Nao consegui alocar memoria!\n");
        exit(-1);
    }

    n->DL_proximo = 0;
    n->DL_anterior = 0;
    strcpy(n->DL_nome, nome);
    n->DL_registro = registro;

    return n;
}

void DL_adicionar_no(char *nome, int registro)
{
    DL_novo = DL_novo_no(nome, registro);
    if((DL_inicio == 0)||(strcmp(DL_novo->DL_nome, DL_inicio->DL_nome) <= 0)){
        DL_adicionar_no_inicio();
    }else{
        DL_aux = DL_inicio;
        while((strcmp(DL_novo->DL_nome, DL_aux->DL_nome) > 0)&&(DL_aux->DL_proximo != 0)){
                if((strcmp(DL_novo->DL_nome, DL_aux->DL_nome) > 0)&&(DL_aux->DL_proximo != 0)){
                    DL_aux = DL_aux->DL_proximo;
                }
         }
         if(strcmp(DL_novo->DL_nome, DL_aux->DL_nome) > 0){
            DL_adicionar_no_final();
         }else{
            DL_adicionar_no_meio();
         }
    }
}

void DL_adicionar_no_final()
{
    DL_aux->DL_proximo = DL_novo;
    DL_novo->DL_anterior = DL_aux;
}

void DL_adicionar_no_inicio()
{
    if(DL_inicio == 0){
        DL_inicio = DL_novo;
    }else{
        if(strcmp(DL_novo->DL_nome, DL_inicio->DL_nome) <= 0){
            DL_novo->DL_proximo = DL_inicio;
            DL_inicio->DL_anterior = DL_novo;
            DL_inicio = DL_novo;
        }
    }
}

void DL_adicionar_no_meio()
{
    DL_proximo = DL_aux;
    DL_anterior = DL_aux->DL_anterior;
    DL_anterior->DL_proximo = DL_novo;
    DL_novo->DL_anterior = DL_anterior;
    DL_novo->DL_proximo = DL_proximo;
    DL_proximo->DL_anterior = DL_novo;
}

void DL_excluir_no(int dado)
{
    if(DL_inicio == 0){
       printf("\nLista vazia!!\n");
    }else{
        if((dado == DL_inicio->DL_registro)&&(DL_inicio->DL_proximo == 0)){
            free(DL_inicio);
            DL_inicio = 0;
        }else if((DL_inicio->DL_registro == dado)&&(DL_inicio->DL_proximo != 0)){
            DL_excluir_no_inicio();
        }else{
            DL_anterior = DL_inicio;
            DL_aux = DL_inicio;
            while((DL_aux->DL_registro != dado)&&(DL_aux->DL_proximo != 0)){
                DL_anterior = DL_aux;
                DL_aux = DL_aux->DL_proximo;
            }if(DL_aux->DL_registro != dado){
                printf("\nDado nao encontrado!\n");
            }else
                if((DL_aux->DL_registro== dado)&&(DL_aux->DL_proximo == 0)){
                    DL_excluir_no_final();
            }else{
                DL_excluir_no_meio();
            }
        }
    }


}

void DL_excluir_no_final()
{
    DL_anterior = DL_aux->DL_anterior;
    DL_anterior->DL_proximo = 0;
    free(DL_aux);
}

void DL_excluir_no_inicio()
{
    DL_aux = DL_inicio;
    DL_inicio = DL_inicio->DL_proximo;
    DL_inicio->DL_anterior = 0;
    free(DL_aux);

}

void DL_excluir_no_meio()
{
    DL_proximo = DL_aux->DL_proximo;
    DL_anterior = DL_aux->DL_anterior;
    DL_anterior->DL_proximo = DL_proximo;
    DL_proximo->DL_anterior = DL_anterior;
    free(DL_aux);
}

void DL_listar()
{

    if(DL_inicio != 0)
    {
        DL_aux = DL_inicio;
        printf(" ___________________________________________\n");
        printf("+                                           +\n");
        printf("|                                           |\n");
        printf("|  NOME                CPF           FONE   |\n");
        while(DL_aux->DL_proximo != 0)
        {
            printf("|___________________________________________|\n");
            printf("|                                           |\n");
            printf("|%14s        %4d          %4d   |\n", LD_lista[DL_aux->DL_registro].nome, LD_lista[DL_aux->DL_registro].cpf, LD_lista[DL_aux->DL_registro].telefone);
            DL_aux = DL_aux->DL_proximo;
        }

        printf("|                                           |\n");
        printf("|___________________________________________|\n");
        printf("|                                           |\n");
        printf("|%14s        %4d          %4d   |\n", LD_lista[DL_aux->DL_registro].nome, LD_lista[DL_aux->DL_registro].cpf, LD_lista[DL_aux->DL_registro].telefone);
        printf("|                                           |\n");
        printf("+___________________________________________+\n");
    }
    else
        printf("Lista vazia!\n");
}

void DL_listarD(){
    if(DL_inicio != 0)
    {
        DL_aux = DL_inicio;
        while(DL_aux->DL_proximo != 0)
        {
           DL_aux = DL_aux->DL_proximo;
        }
        printf(" ___________________________________________\n");
        printf("+                                           +\n");
        printf("|                                           |\n");
        printf("|  NOME                CPF           FONE   |\n");
        while(DL_aux->DL_anterior != 0){
            printf("|___________________________________________|\n");
            printf("|                                           |\n");
            printf("|%14s        %4d          %4d   |\n", LD_lista[DL_aux->DL_registro].nome, LD_lista[DL_aux->DL_registro].cpf, LD_lista[DL_aux->DL_registro].telefone);
            DL_aux = DL_aux->DL_anterior;
        }
        printf("|                                           |\n");
        printf("|___________________________________________|\n");
        printf("|                                           |\n");
        printf("|%14s        %4d          %4d   |\n", LD_lista[DL_aux->DL_registro].nome, LD_lista[DL_aux->DL_registro].cpf, LD_lista[DL_aux->DL_registro].telefone);
        printf("|                                           |\n");
        printf("+___________________________________________+\n");
    }
    else
        printf("Lista vazia!\n");

}

void DL_finalizar()
{
    if(DL_inicio != 0)
    {
        DL_finalizar_elemento(DL_inicio);
        DL_inicio = 0;
    }
}

void DL_finalizar_elemento(struct DL_no *elemento)
{
    if(elemento->DL_proximo != 0)
        DL_finalizar_elemento(elemento->DL_proximo);
    free(elemento);
}
