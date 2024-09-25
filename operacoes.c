#include <stdio.h> 
#include <stdlib.h> 
#include "operacoes.h" 


//Implementação do algoritmo guloso
void alg_guloso(ITEM *items, int qntd_items, int peso_limite) {

    ITEM *items_aux = (ITEM*) malloc(sizeof(ITEM)*qntd_items); 
    int soma_valores = 0; 
    int soma_pesos = 0; 
    int cont = 0; 


    //Copiando os items para o items_aux e calculando a razão valor/peso
    for(int i =0; i<qntd_items; i++) {
        items_aux[i] = items[i]; 
        items_aux[i].razao = (float)items_aux[i].valor/items_aux[i].peso; 

    }
        
    //Ordenando em ordem decrescente 
    quick_sort(items_aux, 0, qntd_items-1); 

    //Calculando a soma total dos items na mochila     
    for(int i =0; i<qntd_items; i++) {
        if(items_aux[i].peso <= peso_limite) {
            soma_valores += items_aux[i].valor; 
            soma_pesos += items_aux[i].peso; 
            peso_limite -= items_aux[i].peso; 

        } else 
            break; 
    }


    printf("Valor máximo na mochila: %d\n", soma_valores); 
    printf("Peso total: %d\n", soma_pesos); 

    free(items_aux); 

    
    

}


//Algoritmo de ordenação quick_sort
void quick_sort(ITEM *items, int inicio, int fim) {
    
    if(inicio < fim) {
        float pivo = items[(inicio+fim)/2].razao; 
        int i, j; 
        ITEM tmp; 

        i = inicio; 
        j = fim; 


        do{
            while(items[i].razao > pivo) 
                i++; 
            while(items[j].razao < pivo) 
                j--; 
            
            if(j>=i) {
                tmp = items[i]; 
                items[i] = items[j]; 
                items[j] = tmp; 
                i++; 
                j--; 

            }

        }while(i<j); 

        quick_sort(items, inicio, j); 
        quick_sort(items, i, fim); 
    }


}
