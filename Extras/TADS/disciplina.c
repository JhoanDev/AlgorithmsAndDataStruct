#include "disciplina.h"

struct disciplina
{
    char nome[100];
    int codigo;
};

Disciplina *cria_disciplina(char nome[], int codigo)
{
    Disciplina *disciplina = (Disciplina *)malloc(sizeof(Disciplina));
    if (disciplina == NULL)
    {
        printf("ERRO");
        exit(1);
    }
    disciplina->codigo = codigo;
    strcpy(disciplina->nome, nome);
    return disciplina;
}

void exclui_disciplina(Disciplina *disciplina)
{
    free(disciplina);
}
