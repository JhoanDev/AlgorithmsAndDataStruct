// TAD: Pilha
typedef struct pilha Pilha;

// Cria a pilha
Pilha *pilha_cria(void);

void pilha_push(Pilha *p, float v);
float pilha_pop(Pilha *p);
int pilha_vazia(Pilha *p);
void pilha_libera(Pilha *p);
