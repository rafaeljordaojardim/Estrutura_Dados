#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED


struct AB_no
{
    struct no *esquerda;
    int AB_cpf;
    int AB_registro;
    struct no *direita;
};

struct AB_no *AB_inicio;
struct AB_no *AB_anterior;
struct AB_no *AB_aux;


void AB_adicionar(struct AB_no *AB_posicao, struct AB_no *AB_novo);
struct AB_no *AB_novo_no(int cpf, int registro);
void AB_inicializar();
void AB_finalizar(struct AB_no *AB_posicao);
struct AB_no *AB_localizar(struct AB_no *AB_posicao, int cpf);
void AB_excluir(int cpf);

#endif // ARVOREBINARIA_H_INCLUDED
