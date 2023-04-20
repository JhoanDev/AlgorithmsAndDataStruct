/* TAD: pilha de valores reais */
typedef struct pilha Pilha;

// cria a pilha
Pilha *pilha_cria(void);

// adiciona um item no topo da piha
void pilha_push(Pilha *p, float v);

// remove um item do topo da pilha
float pilha_pop(Pilha *p);

// verifica se a pilha esta vazia
int pilha_vazia(Pilha *p);

// libera  a pilha
void pilha_libera(Pilha *p);

//imprime os valores da lista
void pilha_imprime(Pilha *p);