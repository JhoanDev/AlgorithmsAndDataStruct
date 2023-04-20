#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

#define max 50;

typedef struct pilha
{
    int n = 0 ;
    float dado[n];
} Pilha;

// cria a pilha
Pilha *pilha_cria(void)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p == NULL)
    {
        printf("ERRO");
    }
    p->dado = 0; // inicia com 0 elementos
    return p;
}

// Adiciona itens no topo da pilha
void pilha_push(Pilha *p, float v)
{
    if (p->n == n)
    {
        printf("Capacidade da pilha estourou.\n");
        exit(1);
    }
    p->dado[p->n] = v;
    p->n++;
}

// verifica se a pilha está vazia
int pilha_vazia(Pilha *p)
{
    return (p->n == 0);
}

// retira um item do topo da pilha
float pilha_pop(Pilha *p)
{
    if (pilha_vazia(p))
    {
        printf("Pilha vazia.\n");
        exit(1);
    }
    float v;
    v = p->dado[p->n - 1];
    (p->n)--;
    return v;
}

// liberando pilha
void pilha_libera(Pilha *p)
{
    free(p);
}

void pilha_imprime(Pilha *p)
{
    int i = p->n - 1;
    while (p->n != 0)
    {
        printf("Dado: %.2f\n", p->dado[i]);
        i--;
    }
}
