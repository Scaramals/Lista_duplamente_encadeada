#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criarLista() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;
    return l;
}

void inserirInicio(Lista *l, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->info = valor;
    novo->prev = NULL;
    novo->next = l->inicio;

    if (l->inicio != NULL)
        l->inicio->prev = novo;
    else
        l->fim = novo;

    l->inicio = novo;
    l->tamanho++;
}

void inserirFim(Lista *l, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->info = valor;
    novo->next = NULL;
    novo->prev = l->fim;

    if (l->fim != NULL)
        l->fim->next = novo;
    else
        l->inicio = novo;

    l->fim = novo;
    l->tamanho++;
}

int removerInicio(Lista *l) {
    if (l->inicio == NULL) return -1;

    No *temp = l->inicio;
    int valor = temp->info;

    l->inicio = temp->next;
    if (l->inicio)
        l->inicio->prev = NULL;
    else
        l->fim = NULL;

    free(temp);
    l->tamanho--;
    return valor;
}

int removerFim(Lista *l) {
    if (l->fim == NULL) return -1;

    No *temp = l->fim;
    int valor = temp->info;

    l->fim = temp->prev;
    if (l->fim)
        l->fim->next = NULL;
    else
        l->inicio = NULL;

    free(temp);
    l->tamanho--;
    return valor;
}

No* buscarPorValor(Lista *l, int valor) {
    No *p = l->inicio;
    while (p != NULL) {
        if (p->info == valor)
            return p;
        p = p->next;
    }
    return NULL;
}

No* buscarPorPosicao(Lista *l, int pos) {
    if (pos < 0 || pos >= l->tamanho)
        return NULL;

    No *p = l->inicio;
    for (int i = 0; i < pos; i++)
        p = p->next;

    return p;
}

void destruirLista(Lista *l) {
    No *p = l->inicio;
    while (p != NULL) {
        No *temp = p;
        p = p->next;
        free(temp);
    }
    free(l);
}
