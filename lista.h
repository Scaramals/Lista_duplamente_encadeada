#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int info;
    struct No *prev;
    struct No *next;
} No;

typedef struct Lista {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

Lista* criarLista();
void inserirInicio(Lista *l, int valor);
void inserirFim(Lista *l, int valor);
int removerInicio(Lista *l);
int removerFim(Lista *l);
No* buscarPorValor(Lista *l, int valor);
No* buscarPorPosicao(Lista *l, int pos);
void destruirLista(Lista *l);

#endif
