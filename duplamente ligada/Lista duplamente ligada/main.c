#include <stdio.h>

struct no
{
    int dado;
    struct no *proximo;
    struct no *anterior;
};

struct no *inicio;
struct no *novo;
struct no *aux;
struct no *anterior;
struct no *proximo;

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
void listarD();
void listar();
struct no *novo_no(int dado);
void menu();

int opcao = 0;
int numero = 0;

int main()
{
    inicializar();
    while(opcao != 5)
    {
        menu();
        switch(opcao)
        {
            case 1:
                printf("Digite um numero: ");
                scanf("%d", &numero);
                adicionar_no(numero);///passa o numero a ser adicionado
                break;
            case 2:
                printf("Digite um numero: ");
                scanf("%d", &numero);
                excluir_no(numero);///passa o numero a ser excluido
                break;
            case 3:
                listar();
                break;
            case 4:
                listarD();
                break;

        }
    }

    finalizar();
}

void menu()
{
    printf("\n");
    printf("Menu\n");
    printf("1 - inserir\n");
    printf("2 - excluir\n");
    printf("3 - listar Crescente\n");
    printf("4 - listar Decrescente\n");
    printf("5 - sair\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
}

void inicializar()
{
    inicio = 0;
}

struct no * novo_no(int dado) ///retornará um ponteiro
{
    struct no *n;
    n = malloc(sizeof(struct no)); ///Aloca memoria do tamanho da struct
    if(!n)
    {
        printf("Nao consegui alocar memoria!\n");///da a mensagem caso não haja memoria disponivel
        exit(-1);
    }

    n->proximo = 0; /// seta o proximo pra 0
    n->anterior = 0;///seta o anterior pra 0
    n->dado = dado;/// dado recebe o dado que é o numero

    return n;///retona pra função que chamou
}

void adicionar_no(int dado)///como parametro está recebendo um numero para ser adicionado
{
    novo = novo_no(dado); ///Recebe em um ponteiro o  numero alocado em algum lugar da menmoria
    if((inicio == 0)||(novo->dado < inicio->dado)){
    ///Vertificando se inicio for igual a 0 ou se o novo dado é menos que o dado
    ///que esta no inicio
        adicionar_no_inicio();///chama a fução adicionar no inicio
    }else{
        aux = inicio;///variavel aux para percorrer a lista dp ligada
        while((novo->dado > aux->dado)&&(aux->proximo != 0)){
        ///faz o while enquanto novo dado for maior que aux dado e aux proximo for diferente de 0
                if((novo->dado > aux->dado)&&(aux->proximo != 0)){
               ///se for ele continua caminhando ate que um deles seja falso
                    aux = aux->proximo;
                }
         }
    ///depois que sair do while tem que verificar se ele vai no ultimp ou entre algum
         if(novo->dado > aux->dado){
        ///se o novo dado for maior que o aux dado, ele é adicionado no final
            adicionar_no_final();
         }else{
        ///senão quer dizer que ele parou no medio, entre dois numeros
            adicionar_no_meio();
         }
    }
}

void adicionar_no_final()
{
    aux->proximo = novo;///amarra o aux proximo no novo dado
    novo->anterior = aux;///amarra o novo anterior no aux que ficara atras
}

void adicionar_no_inicio()
{
    if(inicio == 0){
        inicio = novo; /// se o inicio for igual a 0 quer dizer que não tem ninguem na lista
        ///adiciona o novo dado no começo
    }else{
        if(novo->dado < inicio->dado){ ///agr se ele for menor que o dado do inicio
            novo->proximo = inicio; ///novo proximo recebe inicio que ficará atras dele
            inicio->anterior = novo;///inicio anterior irá receber novo pq ficará na frente dele
            inicio = novo;///agr o inicio é o novo dado (menor dado)
        }
    }
}

void adicionar_no_meio()
{
    proximo = aux;///pronteiro proximo recebe aux só por questoes de entendimento
    anterior = aux->anterior;///so para questoes de entendimento
    anterior->proximo = novo;///anterior proximo recebe novo dado pois ficara no meio
    novo->anterior = anterior;///novo anterior se amarra ao anteior pois ficará na frente
    novo->proximo = proximo;///novo proximo se amarra no proximo  pois ficará atras
    proximo->anterior = novo;///proximo anterior se amarra no novo pois ficará na frente
}

void excluir_no(int dado)
{
    if(inicio == 0){
       printf("\nLista vazia!!\n");///se incio for igual a 0 lista esta vazia
    }else{
        if((dado == inicio->dado)&&(inicio->proximo == 0)){
        ///se o dado que contem no inicio for igual ao dado e se nao tiver ninguem na frente
            free(inicio);///libera o incio
            inicio = 0;///inicio recebe 0
        }else if((inicio->dado == dado)&&(inicio->proximo != 0)){
        ///se inicio dado for igual ao dado mas tiver alguem na frente
        ///chama o excluir no inicio
            excluir_no_inicio();
        }else{
            anterior = inicio;///anterior recebe inicio, andará defasado
            aux = inicio;///andara na frente do anterior
            while((aux->dado != dado)&&(aux->proximo != 0)){
            ///faz enquanto aux dado for diferente de dado e aux proximo diferente de 0
                anterior = aux;///anterior recebe aux atual
                aux = aux->proximo;///aux recebe aux proximo
            }if(aux->dado != dado){/// se chegar até no fim e não encontrou da a mensagem
                printf("\nDado nao encontrado!\n");///mensagem
            }else
                if((aux->dado == dado)&&(aux->proximo == 0)){
                ///se aux dado for igual ao dado e aux proximo for igual a 0
                    excluir_no_final();//chama
            }else{
                excluir_no_meio();///senao chama excluir no meio
            }
        }
    }


}

void excluir_no_final()
{
    anterior = aux->anterior; ///anterior recebe aux anterior que seria o numero atras do ultimo
    anterior->proximo = 0;///anterior proximo recebe 0 pois nao tera mais ninguem na frente dele
    free(aux); ///libera o aux
}

void excluir_no_inicio()
{
    aux = inicio;///recebe inicio em uma variavel aux
    inicio = inicio->proximo;///inicio recebe inicio proximo
    inicio->anterior = 0;///inicio anterior recebe 0
    free(aux);///libera o numero que estava pra tras

}

void excluir_no_meio()
{
    proximo = aux->proximo;///Proximo recebe aux proximo
    anterior = aux->anterior;///anterior recebe aux anterior
    anterior->proximo = proximo;///anterior proximo recebe o proximo
    proximo->anterior = anterior;///proximo anterior recebe anterior
    ///tirando o aux do meio
    free(aux);///libera aux
}

void listar()///listando normal crescente
{
    if(inicio != 0)///ve se o inicio é diferente de 0 para listar
    {
        aux = inicio; ///aux recebe inicio
        while(aux->proximo != 0)///faz enquanto aux proximo for 0 ou seja até que nao tenha proximo na lista
        {
            printf("%d -> ", aux->dado);///imprimindo aux dado
            aux = aux->proximo;///aux recebe aux proximo
        }
        printf("%d\n", aux->dado);///se nao colocar ele nao imprime o ultimo dado da lista
    }
    else
        printf("Lista vazia!\n");
}
void listarD(){
    if(inicio != 0)
    {
        aux = inicio;
        while(aux->proximo != 0)
        {
            aux = aux->proximo;///simplismente caminha até o final
        }
        while(aux->anterior != 0){///faz enquanto aux anterior for diferente de 0 ou seja até chegar no começo
            printf("%d -> ", aux->dado);///imprimindo
            aux = aux->anterior;///aux anda um pra tras
        }
        printf("%d",aux->dado);///se nao colocar ele nao imprime o primeiro dado
    }
    else
        printf("Lista vazia!\n");///senao da listab vazia

}
void finalizar()
{
    if(inicio != 0)///finalizando a lista
    {
        finalizar_elemento(inicio);///finalizando elemento começando do inicio
        inicio = 0;
    }
}

void finalizar_elemento(struct no *elemento)
{
    if(elemento->proximo != 0)///se tiver alguem na frente
        finalizar_elemento(elemento->proximo);///ele manda finalizar o elemento proximo
    free(elemento);///da o free em elemento
}
