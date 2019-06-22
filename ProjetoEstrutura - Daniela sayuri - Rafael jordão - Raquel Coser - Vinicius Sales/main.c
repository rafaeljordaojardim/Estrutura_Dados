#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include "ArvoreBinaria.h"
#include "ListaDinamica.h"
#include "DuplamenteLigada.h"
int posicao = 0, op;
int op_listar = 0;
char confirm = ' ';
void GerarRelatorio();
void FIM(char *nome, int tam);
void menu();
void menu(){
    system("cls");
    printf("\nPrograma de Banco\n\n");
    printf("1 - Adicionar Pessoa\n");
    printf("2 - Localizar\n");
    printf("3 - Excluir\n");
    printf("4 - Listar \n");
    printf("5 - Gerar Relatorio\n");
    printf("6 - Sair\n");
    printf("OPCAO: ");
    scanf("%d",&op);
}
int main()
{
    LD_inicia();
    AB_inicializar();
    DL_inicializar();
    int CPF_INTERNO, TELEFONE_INTERNO, REGISTRO;
    char NOME_INTERNO[15];
    while(op != 6){
      menu();
        switch(op){
            case 1:
                  fflush(stdin);
                  printf("\nDigite o nome -> ");
                  gets(NOME_INTERNO);
                  fflush(stdin);
                  printf("\nDigite o CPF -> ");
                  scanf("%d", &CPF_INTERNO);
                  fflush(stdin);
                  printf("\nDigite o telefone -> ");
                  scanf("%d", &TELEFONE_INTERNO);
                  posicao = LD_adicionar(posicao, CPF_INTERNO, NOME_INTERNO, TELEFONE_INTERNO);
                  REGISTRO = posicao - 1;
                  DL_adicionar_no(NOME_INTERNO, REGISTRO);
                  AB_adicionar(AB_inicio, AB_novo_no(CPF_INTERNO, REGISTRO));
                break;
            case 2:
                   printf("\nDigite o CPF para localizar -> ");
                   scanf("%d", &CPF_INTERNO);
                   AB_aux =  AB_localizar(AB_inicio, CPF_INTERNO);

                   if(AB_aux){
                        printf(" ___________________________________________\n");
                        printf("+                                           +\n");
                        printf("|                                           |\n");
                        printf("|  NOME                CPF           FONE   |\n");
                        printf("|___________________________________________|\n");
                        printf("|                                           |\n");
                        printf("|%14s        %4d          %4d   |\n", LD_lista[AB_aux->AB_registro].nome, LD_lista[AB_aux->AB_registro].cpf, LD_lista[AB_aux->AB_registro].telefone);
                        printf("|                                           |\n");
                        printf("+___________________________________________+\n");
                        system("pause");
                   }else{
                        printf("\nDADO NAO ENCONTRADO!\n");
                        system("pause");
                   }
                    break;
            case 3:
                   printf("\nDigite o CPF para Excluir -> ");
                   scanf("%d", &CPF_INTERNO);
                    AB_aux = AB_aux =  AB_localizar(AB_inicio, CPF_INTERNO);
                    if(AB_aux){
                        printf(" ___________________________________________\n");
                        printf("+                                           +\n");
                        printf("|                                           |\n");
                        printf("|  NOME                CPF           FONE   |\n");
                        printf("|___________________________________________|\n");
                        printf("|                                           |\n");
                        printf("|                                           |\n");
                        printf("|%14s        %4d          %4d   |\n", LD_lista[AB_aux->AB_registro].nome, LD_lista[AB_aux->AB_registro].cpf, LD_lista[AB_aux->AB_registro].telefone);
                        printf("|                                           |\n");
                        printf("+___________________________________________+\n");
                        fflush(stdin);
                        printf("\nDeseja realmente excluir ? S/N -> ");
                        confirm = getchar();

                        if((confirm == 'S')||(confirm == 's')){
                            DL_excluir_no(AB_aux->AB_registro);
                            AB_excluir(CPF_INTERNO);
                            printf("\n<- DADO EXCLUIDO COM SUCESSO ->\n");
                            system("pause");
                        }else{
                            printf("\n<- DADO NAO EXCLUIDO ->");
                            system("pause");
                        }
                   }else{
                        printf("\n<- DADO NAO ENCONTRADO ->\n");
                        system("pause");
                   }
                break;
            case 4:
                    printf("\n 1 - Listar Crescente \n");
                    printf("\n 2 - Listar decrescente \n");
                    printf("Opcao -> ");
                    scanf("%d", &op_listar);
                    if(op_listar == 1){
                            DL_listar();
                            system("pause");
                    }else if(op_listar == 2){
                            DL_listarD();
                            system("pause");
                    }else{
                        printf("\n <- OPCAO INVALIDA ->\n");
                        system("pause");
                    }
                break;
            case 5:
                    GerarRelatorio();
                    system("pause");
                break;
            case 6:
                    system("cls");
                    printf("        DESENVOLVIDO POR:\n\n");
                    FIM("RAFAEL", 6);
                    FIM("DANI-CHAN", 9);
                    FIM("PII", 3);
                    FIM("TIA QUEL", 8);
                    printf("\n       ATE MAIS NAVA!\n\n");

                break;

        }
    }
    LD_finaliza();
    AB_finalizar(AB_inicio);
    DL_finalizar();
    return 0;
}

void FIM(char *nome, int tam){
   int i, j;
    printf("               ");
    for(i = 0; i < tam; i++){
            printf("%c", nome[i]);
    for(j = 0; j < 39000000; j++);
    }
    printf("\n");
}
void GerarRelatorio(){

  if(DL_inicio != 0)
    {
        FILE *file;
        file = fopen("RELATORIO.txt","w");
        DL_aux = DL_inicio;
        fprintf(file, "RELATORIO DE PESSOAS CADASTRADAS -> Data :%s Hora:%s\n\n",__DATE__,__TIME__);
        fprintf(file, " ___________________________________________\n");
        fprintf(file, "+                                           +\n");
        fprintf(file, "|                                           |\n");
        fprintf(file, "|  NOME                CPF           FONE   |\n");
        while(DL_aux->DL_proximo != 0)
        {
            fprintf(file, "|___________________________________________|\n");
            fprintf(file, "|                                           |\n");
            fprintf(file, "|%14s        %4d          %4d   |\n", LD_lista[DL_aux->DL_registro].nome, LD_lista[DL_aux->DL_registro].cpf, LD_lista[DL_aux->DL_registro].telefone);
            DL_aux = DL_aux->DL_proximo;
        }

        fprintf(file, "|                                           |\n");
        fprintf(file, "|___________________________________________|\n");
        fprintf(file, "|                                           |\n");
        fprintf(file, "|%14s        %4d          %4d   |\n", LD_lista[DL_aux->DL_registro].nome, LD_lista[DL_aux->DL_registro].cpf, LD_lista[DL_aux->DL_registro].telefone);
        fprintf(file, "|                                           |\n");
        fprintf(file, "+___________________________________________+\n");
        printf("\nRELATORIO GERADO COM SUCESSO!\n");
        fclose(file);
    }
    else{
        printf("\nIMPOSSIVEL GERAR RELATORIO!\n");
        printf("NAO HA NINGUEM CADASTRADO!\n\n");
    }

}
