#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 5
//nessa lista na hora de adcionar, é adcionado na onde esta o indicador posicao que sempre esta no fim da lista
// porem pode-se excluir quakquer elemento, em qualquer posicao
void menu();
void adcionar(int valor);
int quantidadeElemento();
int buscarIndice(int valorIndice);
int buscarValor(int valor);
void excluir(int valor);
void ordenar();
void imprimir();
int posicao = 0, op=9, numero, lista[TAMANHO],retorno;
void menu(){
    system("cls");
    printf("\nPrograma de Lista\n\n");
    printf("1 - Adicionar na Lista\n");
    printf("2 - Quantidade Elemento\n");
    printf("3 - Buscar por Indice\n");
    printf("4 - Buscar por Valor\n");
    printf("5 - Excluir\n");
    printf("6 - Ordenar\n");
    printf("7 - imprimir\n");
    printf("8 - SAIR\n");
    printf("OPCAO: ");
    scanf("%d",&op);
}
void adicionar(int valor){
    if(posicao == 5){//se a posição for igual a 5 é pq a fila ja esta cheia
        printf("\nA lista esta cheia!!\n");
        system("pause");
    }else{
       lista[posicao++] = valor;//lista recebe o valor na posicao, depois adiciona 1 a posicao
    }
}
int quantidadeElemento(){
    if(posicao == 0)
    {
        return -1;//se ele retorna -1 é pq nao tem elementos na lista
    }else{
        return posicao;//senao ele retorna o proprio numero da posicao
    }
}
int buscarIndice(int valorIndice){
    int verifica = 0,i;
        if(posicao == 0){
            return -1;//retorna se nao houver valores
        }else{
            for(i=0;i<posicao;i++){
                if(valorIndice == i){//ve se tem o valor do indice
                    verifica = 1;//se tiver, verifica recebe 1
                }
            }
            if(verifica == 1){
                return lista[valorIndice];//se o verifica recebeu 1, é pq achou o valor do indice
            }else{
                return -2;//senao ele retorna -2, caso não haja o indice que o usuario digitou
            }
        }
}
int buscarValor(int valor){//ve se tem o valor que foi digitado no vetor e retorna o indice ou retorna que esta vazio
    int verifica = 0,i, num;
        if(posicao == 0){
            return -1;//retorna -1 caso vazia
        }else{
            for(i=0;i<posicao;i++){
                if(valor == lista[i]){//vai veirifcando o valor de cada posicao do vetor
                    verifica = 1;//verifica recebe 1, pois achou
                    num = i;//num recebe o indice onde esta o numero
                }
            }
            if(verifica == 1){
                return num;//se caso achou ele retorna o indice
            }else{
                return -2;//se não achar o numero, ele retorna que não há o numero
            }
     }
}
void excluir(int valor){
    int i;
    if(posicao == 0){
        printf("\nNAO HA ELEMENTOS NA LISTA\n");//se posicao for igual a 0 nao ha elementos na lista
        system("pause");
    }else{
        if(valor >= posicao){
            printf("\nINDICE NAO EXISTENTE\n");//se o indice que ele digitou for mais ou igual a posicao é pq ainda nao tem
            system("pause");
        }else{
            for(i=valor;i<posicao;i++){
                lista[i] = lista[i+1];/*senao, ele vai fazer um for comecando no indice digitado
                                       e vai terminar em menor que posicao, e vai sobrescrever os valores trazendo todos
                                       trasendo todos uma posicao pra tras a partir do indice digitado*/
            }
            posicao--;//tira um valor da posicao, pois foi tirado um valor da lista
        }
    }
}
void imprimir(){
   int i;
   for(i=0;i<posicao;i++){
      printf(" %d ",lista[i]);
   }
   printf("\n");
   system("pause");
}

void ordenar(){//ordena fixando o valor do começo, e indo comparando com todos os outros
                //o primeiro comeca em 0 e termina no antepenultimo
                //o segundo começa no 2 e termina no ultimo
    int i,j,sub;
    if(posicao == 0){
        printf("\nLISTA VAZIA\n");
    }else{
        for(i=0;i<posicao-1;i++){
            for(j=i+1;j<posicao;j++){
                if(lista[i] > lista[j]){//se o primeiro for maior que o segundo, o segundo vem no lugar dele, pois é menor
                    sub = lista[i];
                    lista[i] = lista[j];
                    lista[j] = sub;
                }
            }
        }
    }
}
int main()
{
    while(op != 8){
      menu();
        switch(op){
            case 1:
                  printf("\n\nDigite um numero :");
                  scanf("%d",&numero);//digitado o nuemro para adicionar
                  adicionar(numero);//chama a função adicionar
                break;
            case 2:
                  retorno = quantidadeElemento();//uma varivel retorno recebe a função
                if(retorno == -1){
                    printf("\nNao ha elementos na lista\n");//se retornou -1 é pq nao tem elementos
                    system("pause");
                }else{
                    printf("\nha %d elementos na lista\n",retorno);//senao ele exibe quantos elementos
                    system("pause");
                }
                break;
            case 3:
                    printf("Digite o indice para buscar :");//É digitado o indice para busca
                    scanf("%d",&numero);
                    retorno=buscarIndice(numero);//variavel recebe a função buscar indice
                    if(retorno == -1){//se retornar -1 é pq esta vazia
                        printf("\n LISTA VAZIA!!\n");
                        system("pause");

                    }else{
                        if(retorno == -2){//se retornar -2 é pq nao tem o indice na lista
                            printf("\nNAO HA ESTE INDICE NA LISTA\n");
                            system("pause");
                        }else{
                            printf("\nO numero do indice %d eh %d\n",numero,retorno);//se nao ele mostra o indice
                                                                                    //com o numero correspondente
                            system("pause");
                        }
                    }
                break;
            case 4:
                   printf("\nDigite o valor a ser buscado: ");
                   scanf("%d",&numero);
                   retorno = buscarValor(numero);//chama a função buscar valor
                   if(retorno == -1){
                        printf("\n LISTA VAZIA!!\n");//lista vazia
                        system("pause");

                    }else{
                        if(retorno == -2){//se for -2 é pq nao ha valor na lista
                            printf("\nNAO HA ESTE VALOR NA LISTA\n");
                            system("pause");
                        }else{
                            printf("\nO valor %d esta no indice %d\n",numero,retorno);//mostra o valor e no indice que esta
                            system("pause");
                        }
                    }
                break;
            case 5:
                   printf("Digite o indice para ser excluido: ");
                   scanf("%d", &numero);//pergunta o indice que quer excluir
                   excluir(numero);
                break;
            case 6:
                ordenar();
                imprimir();
                break;
            case 7:
                  imprimir();
                break;
            case 8:
                system("cls");
                printf("ATE MAIS");
                break;

        }
 }

    return 0;
}
