// TAD: fila de lista de valores reais
typedef struct fila Fila;
typedef struct lista Lista;

// inicia a fila
Fila *fila_cria(void);

// insere valor
void fila_insere(Fila *f, float v);

// retira valor
float fila_retira(Fila *f);

// verifica se a fila esta vazia
int fila_vazia(Fila *f);

// imprime a fila
void fila_imprime(Fila *f);

// libera a memoria
void fila_libera(Fila *f);