#include <stdio.h>

struct no
{
    int dado;
    struct no *proximo;
};

struct no *inicio;
struct no *novo;
struct no *aux;
struct no *anterior;

void inicializar();
void finalizar();
void finalizar_elemento(struct no *elemento);
void adicionar_no(int dado);
void adicionar_no_final();
void adicionar_no_inicio();
void adicionar_no_meio();
void excluir_no(int dado);
void excluir_no_inicio();
void excluir_no_final();
void excluir_no_meio();
void listar();
struct no *novo_no(int dado);
void menu();

int opcao = 0;
int numero = 0;

int main()
{
    inicializar();
    while(opcao != 4)
    {
        menu();
        switch(opcao)
        {
            case 1:
                printf("Digite um numero: ");
                scanf("%d", &numero);
                adicionar_no(numero);
                break;
            case 2:
                printf("Digite um numero: ");
                scanf("%d", &numero);
                excluir_no(numero);
                break;
            case 3:
                listar();
                break;
        }
    }

    finalizar();
}

void menu()
{
    printf("Menu\n");
    printf("1 - inserir\n");
    printf("2 - excluir\n");
    printf("3 - listar\n");
    printf("4 - sair\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
}

void inicializar()
{
    inicio = 0;
}

struct no * novo_no(int dado)
{
    struct no *n;
    n = malloc(sizeof(struct no));
    if(!n)
    {
        printf("Nao consegui alocar memoria!\n");
        exit(-1);
    }

    n->proximo = 0;
    n->dado = dado;

    return n;
}

void adicionar_no(int dado)
{
    novo = novo_no(dado);
    if((inicio == 0)||(novo->dado < inicio->dado)){
        adicionar_no_inicio();
    }else{
        aux = inicio;
        anterior = inicio;
        while((novo->dado > aux->dado)&&(aux->proximo != 0)){
                if((novo->dado > aux->dado)&&(aux->proximo != 0)){
                    anterior = aux;
                    aux = aux->proximo;
                }
         }
         if(novo->dado > aux->dado){
            adicionar_no_final();
         }else{
            adicionar_no_meio();
         }
    }
}

void adicionar_no_final()
{
    aux->proximo = novo;
}

void adicionar_no_inicio()
{
    if(inicio == 0){
        inicio = novo;
    }else{
        if(novo->dado < inicio->dado){
            novo->proximo = inicio;
            inicio = novo;
        }
    }
}

void adicionar_no_meio()
{
    novo->proximo = aux;
    anterior->proximo = novo;
}

void excluir_no(int dado)
{
    if(inicio == 0){
       printf("\nLista vazia!!\n");
    }else{
        if((dado == inicio->dado)&&(inicio->proximo == 0)){
            free(inicio);
            inicio = 0;
        }else if((inicio->dado == dado)&&(inicio->proximo != 0)){
            excluir_no_inicio();
        }else{
            anterior = inicio;
            aux = inicio;
            while((aux->dado != dado)&&(aux->proximo != 0)){
                anterior = aux;
                aux = aux->proximo;
            }if(aux->dado != dado){
                printf("\nDado nao encontrado!\n");
            }else
                if((aux->dado == dado)&&(aux->proximo == 0)){
                    excluir_no_final();
            }else{
                excluir_no_meio();
            }
        }
    }




void excluir_no_final()
{
    anterior->proximo = 0;
    free(aux);
}

void excluir_no_inicio()
{
    aux = inicio;
    inicio = inicio->proximo;
    free(aux);

}

void excluir_no_meio()
{
    struct no *proximo;
    proximo = aux->proximo;
    anterior->proximo = proximo;
    free(aux);
}

void listar()
{
    if(inicio != 0)
    {
        aux = inicio;
        while(aux->proximo != 0)
        {
            printf("%d -> ", aux->dado);
            aux = aux->proximo;
        }
        printf("%d\n", aux->dado);
    }
    else
        printf("Lista vazia!\n");
}

void finalizar()
{
    if(inicio != 0)
    {
        finalizar_elemento(inicio);
        inicio = 0;
    }
}

void finalizar_elemento(struct no *elemento)
{
    if(elemento->proximo != 0)
        finalizar_elemento(elemento->proximo);
    free(elemento);
}
