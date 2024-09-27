#ifndef OPERACOES_H
	#define OPERACOES_H

	#include <stdio.h> 
	#include <stdlib.h> 

	typedef struct item_ ITEM;

	ITEM *item_criar(int valor, int peso);
	void item_apagar(ITEM **item);

	int forca_bruta(ITEM **itens, int qntd_itens, int peso_limite);
	int alg_guloso(ITEM **itens, int qntd_itens, int peso_limite);
	int prog_dinamica(ITEM **itens, int qntd_itens, int peso_limite);
#endif