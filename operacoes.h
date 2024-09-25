typedef struct {
	int valor;
	int peso;
    float razao; 
} ITEM;

void alg_guloso(ITEM *items, int qntd_items, int peso_limite); 
void quick_sort(ITEM *items, int inicio, int fim); 
