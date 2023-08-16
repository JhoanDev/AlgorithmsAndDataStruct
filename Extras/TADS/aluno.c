#include "aluno.h"
#include "disciplina.c"

struct aluno
{
    char nome[100];
    int matricula;
    Disciplina *disciplinas[10];
    int num_disciplinas;
};

Aluno *cria_aluno(char nome[], int matricula)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    if (aluno == NULL)
    {
        printf("ERRO");
        exit(1);
    }
    strcpy(aluno->nome, nome);
    aluno->matricula = matricula;
    aluno->num_disciplinas = 0;
    return aluno;
}

void matricula_disciplina(Aluno *aluno, Disciplina *disciplina)
{
    int cont = 0;
    if (aluno->num_disciplinas < 10)
    {
        int i;
        for (i = 0; i < aluno->num_disciplinas; i++)
        {
            if (aluno->disciplinas[i]->codigo == disciplina->codigo)
            {
                printf("Esse aluno ja esta matriculado!\n");
                cont = 1;
                break;
            }
        }
        if (cont != 1)
        {
            aluno->disciplinas[aluno->num_disciplinas] = disciplina;
            aluno->num_disciplinas++;
        }
    }
    else{
        printf("Maximo de disciplinas atingido!\n");
    }
}

void exclui_aluno(Aluno* aluno){
    free(aluno);
}