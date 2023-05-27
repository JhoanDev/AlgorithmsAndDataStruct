// TAD: matriz
typedef struct matriz Matriz;

// cria uma matriz
Matriz *mat_cria(int i, int j);

// libera uma matriz;
void mat_libera(Matriz *mat);

// operação que acessa o elemento da linha i e da coluna j da matriz
float mat_acessa(Matriz *mat, int i, int j);

// operação que atribui o elemento da linha i e da coluna j da matriz
void mat_atribui(Matriz *mat, int i, int j, float v);

// retorna as linhas da matriz
int mat_linhas(Matriz *mat);

// retorna as colunas da matriz
int mat_colunas(Matriz *mat);