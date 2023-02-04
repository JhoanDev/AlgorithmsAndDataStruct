#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL,"Portuguese");
    int qntf, i, j;
    printf("insira a quantidade de frutas que deseja inserir: ");
    scanf("%d", &qntf);
    char **frutas = (char **)malloc(qntf * sizeof(char *));
    for (i = 0; i < qntf; i++)
    {
        frutas[i] = (char *)malloc(20 * sizeof(char));
    }
    float *preco = (float *)malloc(qntf * sizeof(float));
    if (frutas == NULL || preco == NULL)
    {
        printf("ERRO");
        exit(1);
    }
    
    printf("-------------------------------------------------\n");
    for (i = 0; i < qntf; i++)
    {
        printf("insira o nome da %dº fruta: ", i + 1);
        scanf("%s", frutas[i]);
        printf("\ninsira o preço da %dº fruta: ", i + 1);
        scanf("%f", &preco[i]);
        printf("----------------\n");
    }
    printf("\n-------------------------------------------------\n");
    for (i = 0; i < qntf; i++)
    {
        printf("nome da %dº fruta: %s", i + 1, frutas[i]);
        printf("\npreço da %dº fruta: %.2f", i + 1, preco[i]);
        free(frutas[i]);
        printf("\n----------------\n");
    }
    free(frutas);
    free(preco);
    return 0;
}