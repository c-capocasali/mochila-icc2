#include "operacoes.h" 

struct item_ {
    int valor;
    int peso;
    float razao; 
};

void quick_sort(ITEM **itens, int inicio, int fim);

ITEM *item_criar(int valor, int peso) {

    ITEM *item = (ITEM *) malloc(sizeof(ITEM));

    if (item != NULL) {
        item->valor = valor;
        item->peso = peso;
        return(item);
    }
    return(NULL);
}

void item_apagar(ITEM **item) {

    if (*item != NULL) {
        free (*item);
        *item = NULL; 
    }
}

int max(int x, int y) {
    
    return (x > y) ? x : y;
}

// Implementação do algoritmo forca bruta
int forca_bruta(ITEM **itens, int qntd_itens, int peso_limite) {

    int maior_valor = 0;

    // Para n itens sao (2^n)-1 combinações
    int total_combinacoes = 1 << qntd_itens;

    for (int i = 1; i < total_combinacoes; i++) {
        int valor_total = 0;
        int peso_total = 0;

        for (int j = 0; j < qntd_itens; j++) {
            if (i & 1 << j) {
                valor_total += itens[j]->valor;
                peso_total += itens[j]->peso;
            }
        }

        // Verificar se combinacao coube na mochila e atualizar variavel maior valor
        // caso o valor dessa combinacao for maior que o maior encontrado ate agora
        if (peso_total <= peso_limite)
            maior_valor = max(valor_total, maior_valor);
    }

    return(maior_valor); 
}

// Implementação do algoritmo guloso
int alg_guloso(ITEM **itens, int qntd_itens, int peso_limite) {

    ITEM **itens_aux = (ITEM **) malloc(sizeof(ITEM *) * qntd_itens); 
    int maior_valor = 0; 

    // Copiando os items para o items_aux e calculando a razão valor/peso
    for (int i = 0; i < qntd_itens; i++) {
        itens_aux[i] = itens[i];
        itens_aux[i]->razao = (float)itens_aux[i]->valor / itens_aux[i]->peso;
    }
        
    // Ordenando em ordem decrescente 
    quick_sort(itens_aux, 0, qntd_itens - 1); 

    // Calculando a soma total dos items na mochila     
    for (int i = 0; i < qntd_itens; i++) {
        if (itens_aux[i]->peso <= peso_limite) {
            maior_valor += itens_aux[i]->valor; 
            peso_limite -= itens_aux[i]->peso; 
        } 
        else 
            break; 
    }

    free(itens_aux);

    return(maior_valor);
}

// Algoritmo de ordenação quick_sort
void quick_sort(ITEM **itens, int inicio, int fim) {
    
    if (inicio < fim) {
        float pivo = itens[(inicio+fim)/2]->razao; 
        int i, j; 
        ITEM* tmp = (ITEM *) malloc(sizeof(ITEM));

        i = inicio; 
        j = fim; 

        do {
            while (itens[i]->razao > pivo) 
                i++; 
            while (itens[j]->razao < pivo) 
                j--; 
            
            if (j >= i) {
                tmp = itens[i]; 
                itens[i] = itens[j]; 
                itens[j] = tmp; 
                i++; 
                j--; 
            }

        } while (i < j); 

        quick_sort(itens, inicio, j); 
        quick_sort(itens, i, fim); 
    }
}

// Implementação do algoritmo programacao dinamica
int prog_dinamica(ITEM **itens, int qntd_itens, int peso_limite) {

    // Criar a matriz (qntd_itens+1) x (peso_limite+1)
    int mat[qntd_itens + 1][peso_limite + 1];
    
    int maior_valor = 0;

    for (int i = 0; i <= qntd_itens; i++) {
        for (int j = 0; j <= peso_limite; j++) {
            if (i == 0 || j == 0) {
                // Caso base
                mat[i][j] = 0;
            } 
            else {
                // Usa o valor da linha anterior
                mat[i][j] = mat[i-1][j];

                // Se o item atual cabe na mochila, atualiza o valor máximo
                if (j >= itens[i-1]->peso)
                    mat[i][j] = max(mat[i][j], mat[i-1][j-itens[i-1]->peso] + itens[i-1]->valor);
            }

            // Atualiza maior valor encontrado
            maior_valor = max(maior_valor, mat[i][j]); 
        }
    }

    return(maior_valor); 
}
