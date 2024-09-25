#ifndef OPERACOES_H
	#define OPERACOES_H

	#include <stdio.h> 
	#include <stdlib.h> 

	typedef struct item_ ITEM;

	ITEM *item_criar(int valor, int peso);
	void item_apagar(ITEM **item);
	void item_set_valor(ITEM *item, int valor);
	void item_set_peso(ITEM *item, int peso);
	void alg_guloso(ITEM **itens, int qntd_itens, int peso_limite);
	void forca_bruta(ITEM **itens, int qntd_itens, int peso_limite);
#endif