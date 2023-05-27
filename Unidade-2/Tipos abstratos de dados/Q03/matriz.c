#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz
{
    int lin;
    int col;
    float **v;
};

Matriz *mat_cria(int i, int j)
{
    Matriz *mat = (Matriz *)malloc(sizeof(Matriz));
    if (mat == NULL)
    {
        printf("[ERRO]\n");
        exit(1);
    }
    mat->lin = i;
    mat->col = j;
    mat->v = (float **)malloc(mat->lin * sizeof(float *));
    int x;
    if (mat->v == NULL)
    {
        printf("[ERRO]\n");
        exit(1);
    }
    for (x = 0; x < mat->col; x++)
    {
        mat->v[x] = (float *)malloc(sizeof(float));
        if (mat->v[x] == NULL)
        {
            printf("[ERRO]\n");
            exit(1);
        }
    }
    printf("Matriz criada com sucesso!\n");
    return mat;
}

void mat_libera(Matriz *mat)
{
    int i;
    for (i = 0; i < mat->col; i++)
    {
        free(mat->v[i]);
    }
    free(mat->v);
    free(mat);
    printf("Matriz liberada com sucesso!");
}

float mat_acessa(Matriz *mat, int i, int j)
{
    if (mat != NULL && i >= 0 && i < mat->lin && j >= 0 && j < mat->col)
    {
        return mat->v[i][j];
    }
    printf("Operacao invalida!\n");
    return 0.0;
}

void mat_atribui(Matriz *mat, int i, int j, float v)
{
    if (mat != NULL && i >= 0 && i < mat->lin && j >= 0 && j < mat->col)
    {
        mat->v[i][j] = v;
        printf("Valor %.1f atribuido com sucesso a linha %d e coluna %d\n", v, i, j);
    }
    else
        printf("Operacao invalida!\n");
}

int mat_linhas(Matriz *mat)
{
    if (mat != NULL && mat->lin > 0)
    {
        return mat->lin;
    }
    printf("Operacao invalida!\n");
    return 0;
}

int mat_colunas(Matriz *mat)
{
    if (mat != NULL && mat->col > 0)
    {
        return mat->col;
    }
    printf("Operacao invalida!\n");
    return 0;
}