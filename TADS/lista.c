#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// definindo struct
struct lista
{
    int dado;
    struct lista *prox;
};

// criando lista
Lista *list_cria(void)
{
    return NULL;
}

// inserindo no inicio
Lista *list_adc(Lista *l, int i)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->dado = i;
    novo->prox = l;
    return novo;
}

// imprimir a informação
void list_imprime(Lista *l)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
    {
        printf("Dado = %d\n", p->dado);
    }
}

// verifica se a lista está vazia
int list_vazia(Lista *l)
{
    if (l == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// função para buscar um elemento da lista
Lista *list_busca(Lista *l, int v)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->dado == v)
        {
            return p;
        }
    }
    return NULL;
}

// função para retirar um elemento
Lista *list_retira(Lista *l, int v)
{
    Lista *ant = NULL;
    Lista *p = l;
    while (p != NULL && p->dado != v)
    {
        ant = p;
        p = p->prox;
    }
    if (p == NULL)
    {
        return l; // não achou
    }
    // retira o elemento
    if (ant == NULL)
    {
        l = p->prox;
    }
    else
    {
        ant->prox = p->prox; // retira o do meio
    }
    free(p);
    return l;
}

// função para liberar elementos
void list_libera(Lista *l)
{
    Lista *p = l;
    while (p != NULL)
    {
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}

// imprimir a informação
void listc_imprime(Lista *l)
{
    Lista *p = l;
    do
    {
        printf("Dado = %d\n", p->dado);
        p = p->prox;
    } while (p != l);
}

// inserindo no inicio
Lista *listc_adc(Lista *l, int i)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL)
    {
        printf("[ERRO] memoria insuficiente!");
        exit(1);
    }
    novo->dado = i;
    if (l == NULL) // se a lista estiver vazia
    {
        novo->prox = novo; // o próximo aponta para si mesmo
        return novo;       // retorna a nova célula como primeira e última
    }
    novo->prox = l->prox; // o próximo aponta para a primeira célula
    l->prox = novo;       // atualiza o próximo da última célula para apontar para a nova célula
    return l;             // retorna a primeira célula da lista
}

// função para buscar um elemento da lista c
Lista *listc_busca(Lista *l, int v)
{
    Lista *p = l;
    while (p != NULL && p->prox != l && p->dado != v)
    {
        p = p->prox;
        if (p->dado == v)
            return p;
    }
    return NULL;
}

// função para retirar um elemento
Lista *listc_retira(Lista *l, int v)
{
    Lista *ant = NULL;
    Lista *p = l;
    while (p != NULL && p->dado != v)
    {
        ant = p;
        p = p->prox;
    }
    if (p == NULL)
    {
        return l; // não achou
    }
    // retira o elemento
    ant->prox = p->prox;
    free(p);
    return l;
}