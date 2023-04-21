// TAD: lista encadeada + circular
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
Lista *list_retira(Lista *l, int v);

// função para liberar elementos
void list_libera(Lista *l);

// imprimir a informação
void listc_imprime(Lista *l);

// inserindo no inicio
Lista *listc_adc(Lista *l, int i);

// função para buscar um elemento da lista circular
Lista *listc_busca(Lista *l, int v);

// função para retirar um elemento
Lista *listc_retira(Lista *l, int v);