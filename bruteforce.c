#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struct que define um item da mochila
typedef struct {
	int valor;
	int peso;
} ITEM;

int main(void)
{
	int peso_maximo = 15;
	int maior_encontrado = 0;
	int maior_indice = 0;
	int peso_total = 0;
	int valor_total = 0;

	int quantidade_itens = 0;

	scanf("%d", &quantidade_itens);

	ITEM *itens = (ITEM *) malloc(quantidade_itens * sizeof(ITEM));

	for (int i = 0; i < quantidade_itens; i++)
		scanf("%d %d", &itens[i].valor, &itens[i].peso);

	// 2^n combinações
    int total_combinacoes = 1 << quantidade_itens;

    for (int i = 1; i < total_combinacoes; i++)
    {
        valor_total = 0;
        peso_total = 0;

        printf("%d. { ", i);
        for (int j = 0; j < quantidade_itens; j++) 
        {
            if (i & 1 << j) 
            {
                printf("%d(%d %d), ", j + 1, itens[j].valor, itens[j].peso);
                valor_total += itens[j].valor;
                peso_total += itens[j].peso;
	    }
        }
        printf("} -> %d - %d/%d", valor_total, peso_total, peso_maximo);

        // verificar se está na condição (cabe na mochila?)
        if (peso_total <= peso_maximo)
        {
        	if (valor_total > maior_encontrado)
        	{
        		maior_encontrado = valor_total;
        		maior_indice = i;
        	}
            printf(" cabe");
        }
        else
            printf(" não cabe");

        printf("\n");
    }

    printf("O maior valor possível é %d. Ocorreu na combinação %d\n", maior_encontrado, maior_indice);
	free(itens);

	return(1);
}
