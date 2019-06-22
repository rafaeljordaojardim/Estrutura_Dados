#ifndef LISTADINAMICA_H_INCLUDED
#define LISTADINAMICA_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct LD_dados{
    int cpf;
    char nome[15];
    int telefone;
};
void menu();
void LD_inicia();
void LD_finaliza();
int LD_adicionar(int local,int cpf, char *nome, int telefone);
void LD_listar(int local);
struct LD_dados *LD_lista;

#endif // LISTADINAMICA_H_INCLUDED
