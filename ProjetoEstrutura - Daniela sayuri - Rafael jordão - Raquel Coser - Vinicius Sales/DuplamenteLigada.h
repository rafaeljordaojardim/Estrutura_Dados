#ifndef DUPLAMENTELIGADA_H_INCLUDED
#define DUPLAMENTELIGADA_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct DL_no
{
    char DL_nome[15];
    int DL_registro;
    struct no *DL_proximo;
    struct no *DL_anterior;
};

struct DL_no *DL_inicio;
struct DL_no *DL_novo;
struct DL_no *DL_aux;
struct DL_no *DL_anterior;
struct DL_no *DL_proximo;

void DL_inicializar();
void DL_finalizar();
void DL_finalizar_elemento(struct DL_no *elemento);
void DL_adicionar_no(char *nome, int registro);
void DL_adicionar_no_final();
void DL_adicionar_no_inicio();
void DL_adicionar_no_meio();
void DL_excluir_no(int dado);
void DL_excluir_no_inicio();
void DL_excluir_no_final();
void DL_excluir_no_meio();
void DL_listarD();
void DL_listar();
struct DL_no * DL_novo_no(char *nome, int registro);

#endif // DUPLAMENTELIGADA_H_INCLUDED
