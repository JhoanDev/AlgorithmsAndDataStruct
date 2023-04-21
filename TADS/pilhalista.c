#include <stdio.h>
#include <stdlib.h>
#include "listadupla.c"
#include "pilhalista.h"

// Definição da estrutura da pilha

struct pilha
{
    Listad *topo;
};

// Função para criar uma nova pilha vazia
Pilha *pilha_cria()
{
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    novo->topo = NULL;
    return novo;
}

// Função para empilhar um elemento na pilha
void pilha_push(Pilha *p, float v)
{
    Listad *novo = (Listad *)malloc(sizeof(Listad));
    if (novo == NULL)
    {
        printf("[ERRO] memoria insuficiente!");
        exit(1);
    }
    novo->info = v;
    novo->prox = p->topo;
    novo->ant = NULL;
    if (p->topo != NULL)
        p->topo->ant = novo;

    p->topo = novo;
}

// Função para desempilhar um elemento da pilha
float pilha_pop(Pilha *p)
{
    if (p->topo == NULL)
    {
        printf("Pilha vazia!");
        exit(1);
    }

    float v = p->topo->info;
    Listad *antigo = p->topo;
    p->topo = antigo->prox;

    if (p->topo != NULL)
        p->topo->ant = NULL;

    free(antigo);
    return v;
}

// Função para verificar se a pilha está vazia
int pilha_vazia(Pilha *p)
{
    return (p->topo == NULL);
}

// Função para liberar a memória utilizada pela pilha
void pilha_libera(Pilha *p)
{
    Listad *atual = p->topo;
    while (atual != NULL)
    {
        Listad *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(p);
}

// Função para imprimir os elementos da pilha
void pilha_imprime(Pilha *p)
{
    if (p->topo == NULL)
        printf("A pilha esta vazia.\n");
    else
    {
        printf("Pilha: \" ");
        Listad *atual = p->topo;
        while (atual != NULL)
        {
            printf("%.1f ", atual->info);
            atual = atual->prox;
        }
        printf("\"\n");
    }
}