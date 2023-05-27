#include "matriz.c"

int main()
{
    // Teste da função mat_cria
    Matriz *mat = mat_cria(3, 3);
    // Teste da função mat_atribui
    mat_atribui(mat, 0, 0, 1.5);
    mat_atribui(mat, 1, 2, 3.7);
    // Teste da função mat_acessa
    float valor1 = mat_acessa(mat, 0, 0);
    float valor2 = mat_acessa(mat, 1, 2);
    printf("Valor na posição (0, 0): %.1f\n", valor1);
    printf("Valor na posição (1, 2): %.1f\n", valor2);
    // Teste das funções mat_linhas e mat_colunas
    int linhas = mat_linhas(mat);
    int colunas = mat_colunas(mat);
    printf("Número de linhas: %d\n", linhas);
    printf("Número de colunas: %d\n", colunas);
    // Teste da função mat_libera
    mat_libera(mat);
    return 0;
}
