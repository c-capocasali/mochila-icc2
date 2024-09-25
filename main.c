#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "operacoes.h"

int main(void) {
    srand(time(NULL));

    int qntd_itens = 5;
    int peso_limite = 5;

    // Criando vetor de itens
    ITEM **itens = (ITEM **) malloc(qntd_itens * sizeof(ITEM *));
    itens[0] = item_criar(3, 1);
    itens[1] = item_criar(6, 12);
    itens[2] = item_criar(1, 5);
    itens[3] = item_criar(7, 3);
    itens[4] = item_criar(9, 2);
    /*
    for (int i = 0; i < qntd_itens; i++)
    {
        itens[i] = item_criar(rand() % 10 + 1, rand() % 10 + 1);
    }*/

    printf("Resultado da força bruta:\n");
    forca_bruta(itens, qntd_itens, peso_limite);

    printf("\n");

    printf("Resultado do algoritmo guloso:\n");
    alg_guloso(itens, qntd_itens, peso_limite);   

    // Limpando memória
    for (int i = 0; i < qntd_itens; i++) {
        item_apagar(&itens[i]);
    }
    free(itens);

    return(0); 
}