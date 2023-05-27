#include "aluno.h"

struct aluno
{
    char nome[100];
    float nota;
};

Aluno *aluno_cria(char *nome, float nota)
{
    Aluno *novo = (Aluno *)malloc(sizeof(Aluno));
    if (novo == NULL)
    {
        printf("[ERRO]\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    novo->nota = nota;
    return novo;
}

void aluno_libera(Aluno *a)
{
    free(a);
}

void aluno_imprime(Aluno *a)
{
    printf("Nome: %s\n", a->nome);
    printf("Nota: %.1f\n", a->nota);
}

void aluno_ordena(int n, Aluno **v)
{
    int i, j;
    Aluno *chave;
    for (i = 1; i < n; i++)
    {
        chave = v[i];
        j = i - 1;
        while (j >= 0 && strcmp(v[j]->nome, chave->nome) > 0)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = chave;
    }
}

void aluno_salva(FILE *fp, int n, Aluno **v)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "Nome: %s\n", v[i]->nome);
        fprintf(fp, "Nota: %.1f\n", v[i]->nota);
        fprintf(fp, "\n");
    }
    printf("Dados salvos no arquivo com sucesso.\n");
}
