/*Escreva um programa que aloque dinamicamente uma matriz de inteiros de 0 a 250.
As dimensões da matriz deverão ser lidas do usuário. Em seguida, escreva uma função
que receba um valor e retorne 1, caso o valor esteja na matriz, ou retorne 0, no
caso contrário. */

#include <stdio.h>
#include <stdlib.h>

int procuravalor(int numero, int **matriz, int linhas, int colunas)
{
    for (size_t i = 0; i < linhas; i++)
    {
        for (size_t j = 0; j < colunas; j++)
        {
            if (matriz[i][j] == numero)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main(void)
{
    int linhas, colunas, numero, cnt;
    printf("insira as linhas da matriz: ");
    scanf("%d", &linhas);
    printf("\ninsira as colunas da matriz: ");
    scanf("%d", &colunas);
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    for (size_t i = 0; i < linhas; i++)
    {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }
    printf("\nPreenchendo matriz com numeros aleatorios de 0 a 250...\n");
    for (size_t i = 0; i < linhas; i++)
    {
        for (size_t j = 0; j < colunas; j++)
        {
            matriz[i][j] = rand() % 250;
        }
    }
    do
    {
        printf("\nDigite um numero de 0 a 250 para saber se ele existe ou nao na matriz: ");
        scanf("%d", &numero);
        if (procuravalor(numero, matriz, linhas, colunas) == 1)
        {
            printf("\nO valor %d Esta contido na matriz!\n", numero);
        }
        else if (procuravalor(numero, matriz, linhas, colunas) == 0)
        {
            printf("\nO valor %d nao Esta contido na matriz!\n", numero);
        }
        printf("\nDeseja procurar outro valor?\n1-sim\n2-nao\n");
        scanf("%d", &cnt);
    } while (cnt != 2);
    printf("\n--------EXIBINDO MATRIZ---------\n\n");
    for (size_t i = 0; i < linhas; i++)
    {
        for (size_t j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n-------PROGRAMA ENCERRADO-------");
    for (size_t i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}