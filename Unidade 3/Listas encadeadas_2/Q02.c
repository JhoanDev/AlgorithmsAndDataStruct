#include "listac.c"

// imprimir a informação
void lcirc_imprime(Lista *l)
{
    Lista *p = l;
    do
    {
        printf("Dado = %d\n", p->dado);
        p=p->prox;
    } while (p != l);
}