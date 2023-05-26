#include <stdio.h>
#include <stdlib.h>
#include "filavet.h"

#define MAX 5

struct fila
{
    int tamanhoatual;
    float dados[MAX];
};

Fila *fila_cria(void)
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (f == NULL)
    {
        printf("Erro alocacao!\n");
        exit(1);
    }
    f->tamanhoatual = 0;
    return f;
}

void fila_insere(Fila *f, float v)
{
    if (fila_cheia(f))
        printf("Fila cheia!\n");
    else
    {
        f->dados[f->tamanhoatual] = v;
        f->tamanhoatual++;
        printf("Valor %.1f inserido na fila.\n", v);
    }
}

float fila_retira(Fila *f)
{
    if (fila_vazia(f))
    {
        printf("Fila Vazia!\n");
        return;
    }
    int i = 0, j = 1;
    float v = f->dados[0];
    for (i = 0; i < (f->tamanhoatual) - 1; i++)
    {
        f->dados[i] = f->dados[j];
        j++;
    }
    f->tamanhoatual--;
    return v;
}

int fila_vazia(Fila *f)
{
    if (f->tamanhoatual == 0)
        return 1;
    return 0;
}

int fila_cheia(Fila *f)
{
    if (f->tamanhoatual == MAX)
        return 1;
    return 0;
}

void fila_imprime(Fila *f)
{
    if (fila_vazia(f))
        printf("Fila vazia!\n");
    else
    {
        int i = 0, j = 0;
        for (i = 0; i < f->tamanhoatual; i++)
        {
            j++;
            printf("\nDado %d: %.1f\n", j, f->dados[i]);
        }
    }
}

void fila_libera(Fila *f)
{
    free(f);
}
