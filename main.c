#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "operacoes.h"

int main(void) {

    int qntd_itens;
    int peso_limite;

    scanf("%d %d", &qntd_itens, &peso_limite);

    // Criando vetor de itens
    ITEM **itens = (ITEM **) malloc(qntd_itens * sizeof(ITEM *));

    // Inicializando o vetor de itens com TAD
    for (int i = 0; i < qntd_itens; i++) {

        int valor, peso;
        scanf("%d %d", &valor, &peso);
        itens[i] = item_criar(valor, peso);
    }

    // Calculando e imprimindo os resultados
    printf("Resultado da força bruta: %d\n\n", forca_bruta(itens, qntd_itens, peso_limite));
   
    printf("Resultado do algoritmo guloso: %d\n\n", alg_guloso(itens, qntd_itens, peso_limite));
    
    printf("Resultado da programacao dinamica: %d\n", prog_dinamica(itens, qntd_itens, peso_limite));

    // Limpando memória
    for (int i = 0; i < qntd_itens; i++) {

        item_apagar(&itens[i]);
    }
    free(itens);

    return(0); 
}