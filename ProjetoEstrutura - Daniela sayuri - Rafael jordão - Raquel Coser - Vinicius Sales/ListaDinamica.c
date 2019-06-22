#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DuplamenteLigada.h"
#include "ListaDinamica.h"


int LD_tamanho = 5;
void LD_expandir(){
    struct LD_dados *aux;
    aux = malloc((LD_tamanho + (LD_tamanho / 2)) * sizeof(struct LD_dados));
    if(!aux)
    {
        printf("Erro de alocacao!");
        exit(-1);
    }else{
    int i=0;
    for(i=0;i<LD_tamanho;i++){
        aux[i] = LD_lista[i];
    }
    free(LD_lista);
    LD_lista = aux;
    LD_tamanho = LD_tamanho + (LD_tamanho / 2);
}
}
void LD_listar(int local){
    int i=0;
    for(;i<local;i++){
        printf("Registro: %4d  Nome: %15s    CPF: %5d   Telefone: %5d\n", i,LD_lista[i].nome, LD_lista[i].cpf, LD_lista[i].telefone);
    }
}
void LD_inicia(){
    LD_lista = malloc(LD_tamanho * sizeof(struct LD_dados));
    if(!LD_lista)
    {
        printf("Erro de alocacao!");
        exit(-1);
    }
}
void LD_finaliza(){
    free(LD_lista);
}
int LD_adicionar(int local,int cpf, char *nome, int telefone){
    if(local == (LD_tamanho - 1)){
        LD_expandir();
        LD_lista[local].cpf = cpf;
        strcpy(LD_lista[local].nome, nome);
        LD_lista[local].telefone = telefone;
        local++;
       return local;
    }else{
        LD_lista[local].cpf = cpf;
        strcpy(LD_lista[local].nome, nome);
        LD_lista[local].telefone = telefone;
        local++;
       return local;
    }
}


