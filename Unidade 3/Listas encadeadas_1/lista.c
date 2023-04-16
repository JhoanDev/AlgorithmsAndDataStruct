#include <stdio.h>
#include <stdlib.h>

// definindo struct
typedef struct lista
{
    int dado;
    struct lista *prox;
} Lista;

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