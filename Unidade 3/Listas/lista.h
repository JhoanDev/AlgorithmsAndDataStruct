// TAD: lista de inteiros

typedef struct lista Lista;

// criando lista
Lista *list_cria(void);

// inserindo no inicio
Lista *list_adc(Lista *l, int i);

// imprimir a informação
void list_imprime(Lista *l);

// verifica se a lista está vazia
int list_vazia(Lista *l);

// função para buscar um elemento da lista
Lista *list_busca(Lista *l, int v);

// função para retirar um elemento
Lista *lita_retira(Lista *l, int v);

// função para liberar elementos
void list_libera(Lista *l);