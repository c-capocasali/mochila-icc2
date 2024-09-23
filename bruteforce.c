// testar todas as combinações
// verificar se está na condição (cabe na mochila?)
// W (total mochila) - w (peso item)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definido uma struct para os itens da mochila
typedef struct {
	int valor;
	int peso;
} ITEM;

int main(void)
{
	int peso_maximo = 10;
	int peso_total = 0;
	int valor_total = 0;

	int quantidade_itens = 0;

	scanf("%d", &quantidade_itens);

	ITEM *itens = (ITEM *) malloc(quantidade_itens * sizeof(ITEM));

	for (int i = 0; i < quantidade_itens; i++)
		scanf("%d %d", &itens[i].valor, &itens[i].peso);

	free(itens);

	return(1);
}