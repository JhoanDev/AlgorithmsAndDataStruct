/* Escreva um programa em C que crie uma estrutura "Aluno" com os seguintes campos: nome (string de até 20 caracteres),
matrícula (inteiro) e notas (array de 4 floats). O programa deve alocar dinamicamente uma quantidade N de alunos,
ler os dados para cada aluno e imprimir o nome, matrícula e média das notas de cada aluno. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_NOTAS 4 //definindo constante

typedef struct aluno
{
    char nome[20];
    int matricula;
    float notas[NUM_NOTAS];
} aluno;

void calcula_media(aluno *alunos, float *media)
{
    float mediaa = 0;
    for (size_t i = 0; i < NUM_NOTAS; i++)
    {
        mediaa += alunos->notas[i];
    }
    *media = mediaa / NUM_NOTAS;
}

int main(void)
{
    int qnt, i, j;
    printf("Insira a quantidade de alunos: ");
    scanf("%d", &qnt);
    aluno *alunos = (aluno *)malloc(qnt * sizeof(aluno)); //alocando dinamicamente
    if (alunos == NULL)
    {
        printf("Erro ao alocar memória para os alunos.\n");
        return 1;
    }
    float *media = (float *)malloc(qnt * sizeof(float));
    if (media == NULL)
    {
        printf("Erro ao alocar memória para as médias.\n");
        free(alunos);
        return 1;
    }
    srand(time(NULL)); // inicializando o gerador de números aleatórios
    for (i = 0; i < qnt; i++)
    {
        printf("\nInsira o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);
        alunos[i].matricula = rand() % 100000; // gera uma matrícula aleatória de até 5 dígitos
        for (j = 0; j < NUM_NOTAS; j++)
        {
            printf("Insira a nota %d: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }
    }
    for (i = 0; i < qnt; i++)
    {
        calcula_media(&alunos[i], &media[i]);
        printf("\n---------------------------------------------------\n");
        printf("Aluno %d\nNome: %s\nMatricula: %d\nMedia: %.2f", i + 1, alunos[i].nome, alunos[i].matricula, media[i]);
    }
    printf("\n---------------------------------------------------\n");
    free(alunos);
    free(media);
    return 0;
}