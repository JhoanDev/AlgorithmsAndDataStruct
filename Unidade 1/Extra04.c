/* Questão 1) Escreva um programa que calcula a soma de duas matrizes MxN, considerando matrizes quadradas.
As dimensões deve ser fornecidas pelo o usuário. Use alocação dinâmica e escreva uma função que somará as matrizes;*/

#include <stdio.h>
#include <stdlib.h>

int somamatriz(int **matrizA, int **matrizB, int n)
{
    int **matrizC = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrizC[i] = (int *)malloc(n * sizeof(int));
    }
    if (matrizB == NULL) // verificando estouro de memoria
    {
        printf("ERRO");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j]; // somando as duas matrizes na matriz c
        }
    }
    return matrizC; //retornando a matriz somada
}

int main(void)
{
    int n, i, j; // variaveis de controle
    printf("insira o lado das matrizes quadradas: ");
    scanf("%d", &n);
    // fazendo a alocação dinamica
    int **matrizA = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        matrizA[i] = (int *)malloc(n * sizeof(int));
    }
    int **matrizB = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        matrizB[i] = (int *)malloc(n * sizeof(int));
    }
    int **matrizC = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        matrizC[i] = (int *)malloc(n * sizeof(int));
    }
    if (matrizC == NULL) // verificando estouro de memoria
    {
        printf("ERRO");
        exit(1);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            matrizA[i][j] = rand() % 100; // preenchendo a matriz com numeros aleatorios
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            matrizB[i][j] = rand() % 100;
        }
    }
    printf("\n----------Exibindo a matriz A----------\n"); 
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ",matrizA[i][j]);
        }
        printf("\n");
    }
    printf("\n----------Exibindo a matriz B----------\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ",matrizB[i][j]);
        }
        printf("\n");
    }
    printf("\n----------Exibindo a soma das matrizes----------\n");
    matrizC = somamatriz(matrizA,matrizB,n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ",matrizC[i][j]);
        }
        printf("\n");
    }
    return 0;
}