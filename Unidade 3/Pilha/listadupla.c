#include "listadupla.h"
#include <stdio.h>
#include <stdlib.h>

struct listad
{
    float info;
    struct listad *prox;
    struct listad *ant;
};

// inicia a lista
Listad *listd_cria(void)
{
    return NULL;
}

// libera os nos da lista
void listd_libera(Listad *l)
{
    Listad *p = l;
    while (p != NULL)
    {
        Listad *t = p->prox;
        free(p);
        p = t;
    }
}

// adiciona um novo valor na lista
Listad *listd_adc(Listad *l, int v)
{
    Listad *novo = (Listad *)malloc(sizeof(Listad));
    if (novo == NULL)
    {
        printf("[ERRO] memoria insuficiente!");
        exit(1);
    }
    novo->info = v;
    novo->prox = l;
    novo->ant = NULL;
    if (l)
        l->ant = novo;
    return l;
}

// busca um item na lista
Listad *listd_busca(Listad *l, int v)
{
    Listad *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->info == v)
        {
            return p;
        }
    }
    return NULL; // nao achou
}

// retira um no da lista
Listad *listd_retira(Listad *l, int v)
{
    Listad *p = listd_busca(l, v);

    if (p == NULL)
    {
        return l; // não achou
    }
    // retira o elemento
    if (l == p) // testa se é o primeiro elemento
    {
        l = p->prox;
    }
    else
    {
        p->ant->prox = p->prox; // retira o do meio
    }
    if (p->prox != NULL) // testa se é o ultimo elemento
    {
        p->prox->ant = p->ant;
    }
    free(p);
    return l;
}

// verifica se a lista esta vazia
int listd_vazia(Listad *l)
{
    if (l == NULL)
        return 1;
    else
        return 0;
}

// imprime o valor de todos os valores da lista
void listd_imprime(Listad *l)
{
    Listad *p;
    for (p = l; p != NULL; p = p->prox)
    {
        printf("info = %.2f\n", p->info);
    }
}

// adiciona em uma lista dupla circular
Listad *listdc_adc(Listad *l, int v)
{
    Listad *novo = (Listad *)malloc(sizeof(Listad));
    if (novo == NULL)
    {
        printf("[ERRO] memoria insuficiente!");
        exit(1);
    }
    novo->info = v;
    novo->prox = novo;
    novo->ant = novo;
    if (!l)
    {
        return novo;
    }
    else
    {
        Listad *ultimo = l->ant;
        novo->prox = l;
        l->ant = novo;
        ultimo->prox = novo;
        novo->ant = ultimo;
        return l;
    }
}

// busca um elemento
Listad *listdc_busca(Listad *l, int v)
{
    Listad *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->info == v)
        {
            return p;
        }
    }
    return NULL; // não achou
}

// retira um elemento
Listad *listdc_retira(Listad *l, int v)
{
    Listad *p = listd_busca(l, v);

    if (p == NULL)
    {
        return l; // não achou
    }
    // retira o elemento
    if (l == p)
    { // testa se é o primeiro elemento
        l = p->prox;
    }
    if (p->ant != NULL)
    {
        p->ant->prox = p->prox; // retira o do meio ou do final
    }
    if (p->prox != NULL)
    { // testa se é o último elemento
        p->prox->ant = p->ant;
    }
    free(p);
    return l;
}

// verifica se a lista esta vazia
int listdc_vazia(Listad *l)
{
    if (l == NULL)
        return 1;
    else
        return 0;
}

// imprime a lista
void listdc_imprime(Listad *l)
{
    if (l == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }
    Listad *p = l;
    do
    {
        printf("info = %.2f\n", p->info);
        p = p->prox;
    } while (p != l);
}
