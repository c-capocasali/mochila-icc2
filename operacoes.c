#include "operacoes.h" 

struct item_ {
    int valor;
    int peso;
    float razao; 
};

ITEM *item_criar(int valor, int peso)
{
    ITEM *item = (ITEM *) malloc(sizeof(ITEM));

    item->valor = valor;
    item->peso = peso;

    return(item);
}

void item_apagar(ITEM **item)
{
    free(*item);
}

void item_set_valor(ITEM *item, int valor)
{
    item->valor = valor;
}

void item_set_peso(ITEM *item, int peso)
{
    item->peso = peso;
}

void quick_sort(ITEM **itens, int inicio, int fim);

//Implementação do algoritmo guloso
void alg_guloso(ITEM **itens, int qntd_itens, int peso_limite) {

    ITEM **itens_aux = (ITEM **) malloc(sizeof(ITEM *) * qntd_itens); 
    int soma_valores = 0; 
    int soma_pesos = 0; 
    int cont = 0; 

    // Copiando os items para o items_aux e calculando a razão valor/peso
    for(int i = 0; i < qntd_itens; i++) {
        itens_aux[i] = itens[i];
        itens_aux[i]->razao = (float)itens_aux[i]->valor/itens_aux[i]->peso;
    }
        
    // Ordenando em ordem decrescente 
    quick_sort(itens_aux, 0, qntd_itens - 1); 

    // Calculando a soma total dos items na mochila     
    for(int i = 0; i < qntd_itens; i++) {
        if(itens_aux[i]->peso <= peso_limite) {
            soma_valores += itens_aux[i]->valor; 
            soma_pesos += itens_aux[i]->peso; 
            peso_limite -= itens_aux[i]->peso; 
        } 
        else 
            break; 
    }

    printf("Valor máximo na mochila: %d\n", soma_valores); 
    printf("Peso total: %d\n", soma_pesos); 

    free(itens_aux);
}

// Algoritmo de ordenação quick_sort
void quick_sort(ITEM **itens, int inicio, int fim) {
    
    if(inicio < fim) {
        float pivo = itens[(inicio+fim)/2]->razao; 
        int i, j; 
        ITEM* tmp = (ITEM *) malloc(sizeof(ITEM));

        i = inicio; 
        j = fim; 

        do {
            while(itens[i]->razao > pivo) 
                i++; 
            while(itens[j]->razao < pivo) 
                j--; 
            
            if(j>=i) {
                tmp = itens[i]; 
                itens[i] = itens[j]; 
                itens[j] = tmp; 
                i++; 
                j--; 
            }

        } while(i<j); 

        quick_sort(itens, inicio, j); 
        quick_sort(itens, i, fim); 
    }
}

void forca_bruta(ITEM **itens, int qntd_itens, int peso_limite)
{
    int peso_total = 0;
    int valor_total = 0;

    int maior_valor = 0;
    int peso_do_maior_valor = 0;

    // 2^n combinações
    int total_combinacoes = 1 << qntd_itens;

    for (int i = 1; i < total_combinacoes; i++)
    {
        valor_total = 0;
        peso_total = 0;

        for (int j = 0; j < qntd_itens; j++) 
        {
            if (i & 1 << j) 
            {
                valor_total += itens[j]->valor;
                peso_total += itens[j]->peso;
            }
        }

        // verificar se está na condição (cabe na mochila?)
        if (peso_total <= peso_limite)
        {
            if (valor_total > maior_valor)
            {
                maior_valor = valor_total;
                peso_do_maior_valor = peso_total;
            }
        }
    }

    printf("Valor máximo na mochila: %d\n", maior_valor); 
    printf("Peso total: %d\n", peso_do_maior_valor); 
}
