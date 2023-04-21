/*TAD: pilha com listas */
typedef struct pilha Pilha;

// Função para criar uma nova pilha vazia
Pilha *pilha_cria();

// Função para empilhar um elemento na pilha
void pilha_push(Pilha *p, float v);

// Função para desempilhar um elemento da pilha
float pilha_pop(Pilha *p);

// Função para verificar se a pilha está vazia
int pilha_vazia(Pilha *p);

// Função para liberar a memória utilizada pela pilha
void pilha_libera(Pilha *p);

// Função para imprimir os elementos da pilha
void pilha_imprime(Pilha *p);