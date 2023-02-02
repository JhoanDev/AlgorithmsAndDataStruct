#include <stdio.h>
#include <stdlib.h>

int main (void){
    int i,j;
    int **matriz = (int **) malloc(3 * sizeof(int *));
    for ( i = 0; i < 3; i++)
    {
        matriz[i] = (int *) malloc(3 * sizeof(int));
    }
    if (matriz == NULL)
    {
        printf("ERRO");
        exit(1);
    }
    
    for (i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            matriz[i][j] = i*3 + j;
        }
    }
    printf("Minha matriz: \n\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    free(matriz);
    return 0;
}