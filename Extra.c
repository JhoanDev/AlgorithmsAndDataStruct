#include <stdio.h>
#include <stdlib.h>

typedef enum situacao
{
    ativo,
    inativo,
    trancado,
} Situacao;

typedef union indiceacademico
{
    float IG;
    float IRA;
    float IRT;
} Indiceacademico;

typedef struct aluno
{
    char nome[50];
    int matricula;
    char curso[30];
    Indiceacademico indice;
    Situacao si;
} Aluno;

int main(void)
{
    Aluno aluno;
    int opc;
    printf("Insira o nome do aluno: ");
    scanf(" %[^\n]", &aluno.nome);
    printf("Insira a matricula: ");
    scanf("%d", &aluno.matricula);
    printf("Insira o nome do curso: ");
    scanf(" %[^\n]", &aluno.curso);
    printf("Qual a situacao do aluno? 0-Ativo 1-Inativo 2-Trancado\n");
    scanf("%d", &aluno.si);
    printf("Qual indice academico vai inserir? 1-IG 2-IRA 3-IRT\n");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
        printf("Insira seu IG: ");
        scanf("%f", &aluno.indice.IG);
        printf("\nAluno: %s\nMatricula: %d\nCurso: %s\nIG: %.2f\nSituacao: ", aluno.nome, aluno.matricula, aluno.curso, aluno.indice.IG);
        break;
    case 2:
        printf("Insira seu IRA: ");
        scanf("%f", &aluno.indice.IRA);
        printf("\nAluno: %s\nMatricula: %d\nCurso: %s\nIG: %.2f\nSituacao: ", aluno.nome, aluno.matricula, aluno.curso, aluno.indice.IRA);
        break;
    case 3:
        printf("Insira seu IRT: ");
        scanf("%f", &aluno.indice.IRT);
        printf("\nAluno: %s\nMatricula: %d\nCurso: %s\nIG: %.2f\nSituacao: ", aluno.nome, aluno.matricula, aluno.curso, aluno.indice.IRT);
        break;
    default:
        printf("ERRO");
        break;
    }
    switch (aluno.si)
    {
    case ativo:
        printf("Ativo");
        break;
    case inativo:
        printf("Inativo");
        break;
    case trancado:
        printf("Trancado");
        break;
    default:
        printf("ERRO");
        break;
    }
    return 0;
}
