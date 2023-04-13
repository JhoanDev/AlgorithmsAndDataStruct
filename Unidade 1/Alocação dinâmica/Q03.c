#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int qntf, i;
    printf("insira a quantidade de frutas que deseja inserir: ");
    scanf("%d", &qntf);
    //alocando memoria dinamicamente
    char **frutas = (char **)malloc(qntf * sizeof(char *));
    for (i = 0; i < qntf; i++)
    {
        frutas[i] = (char *)malloc(20 * sizeof(char));
    }
    float *preco = (float *)malloc(qntf * sizeof(float));
    //verificando memoria
    if (frutas == NULL || preco == NULL)
    {
        printf("ERRO");
        exit(1);
    }
    //preenchendo
    printf("-------------------------------------------------\n");
    for (i = 0; i < qntf; i++)
    {
        printf("insira o nome da %d fruta: ", i + 1);
        char *nova_fruta = (char *)malloc(20 * sizeof(char)); //vetor criado apenas para armazenar a fruta e logo apos liberar a memoria
        scanf(" %[^\n]s", nova_fruta);
        frutas[i] = (char *)realloc(frutas[i], strlen(nova_fruta) + 1); //reallocando memoria para nao disperdicar
        strcpy(frutas[i], nova_fruta); //atribuindo a gruta lida para o nossa matriz inicial
        free(nova_fruta); //liberando o espaço
        printf("insira o preco da %d fruta: ", i + 1);
        scanf("%f", &preco[i]);
        printf("----------------\n");
    }
    //exibindo resultados
    printf("\n-------------------------------------------------\n");
    for (i = 0; i < qntf; i++)
    {
        printf("nome da %d fruta: %s", i + 1, frutas[i]);
        printf("\npreco da %d fruta: %.2f", i + 1, preco[i]);
        free(frutas[i]); //liberando memoria
        printf("\n----------------\n");
    }
    //liberando espaço
    free(frutas);
    free(preco);
    return 0;
}
