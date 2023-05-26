#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define MAX 5;

struct lista
{
    float dado;
    Lista *prox;
};

struct fila
{
    Lista *fim;
    Lista *ini;
    int tamanho;
};

Fila *fila_cria(void)
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->fim = NULL;
    f->ini = NULL;
    if (f == NULL)
    {
        printf("[Erro] memoria.\n");
        exit(1);
    }
    f->tamanho = 0;
    return f;
}

void fila_insere(Fila *f, float v)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL)
    {
        printf("[Erro] memoria.\n");
        exit(1);
    }
    novo->dado = v;
    novo->prox = NULL;
    if (f->fim != NULL)
        f->fim->prox = novo;
    else
        f->ini = novo;
    f->fim = novo;
    f->tamanho++;
    printf("Valor %.1f inserido na fila.\n", v);
}

float fila_retira(Fila *f)
{
    if (fila_vazia(f))
    {
        printf("Fila vazia!\n");
    }
    else
    {
        Lista *l = f->ini;
        float v = f->ini->dado;
        f->ini = f->ini->prox;
        if (f->ini == NULL)
            f->fim = NULL;
        f->tamanho--;
        free(l);
        return v;
    }
}

void fila_imprime(Fila *f)
{
    Lista *l;
    int i = 1;
    for (l = f->ini; l != NULL; l = l->prox)
    {
        printf("\nDado %d: %.1f\n", i, l->dado);
        i++;
    }
}

void fila_libera(Fila *f)
{
    Lista *p = f->ini;
    while (p != NULL)
    {
        Lista *t = p->prox;
        free(p);
        p = t;
    }
    free(f);
}

int fila_vazia(Fila *f)
{
    if (f->tamanho == 0)
        return 1;
    return 0;
}
