#include <stdio.h>
#include "lista.h"

int main() {
    Lista *l = criarLista();

    inserirInicio(l, 10);
    inserirInicio(l, 20);
    inserirFim(l, 30);

    No *n = buscarPorValor(l, 20);
    if (n) printf("Encontrado: %d\n", n->info);

    n = buscarPorPosicao(l, 1);
    if (n) printf("Posição 1: %d\n", n->info);

    printf("Removido início: %d\n", removerInicio(l));
    printf("Removido fim: %d\n", removerFim(l));

    destruirLista(l);

    return 0;
}
