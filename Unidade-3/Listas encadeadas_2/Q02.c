#include "lista.c"
#include <time.h>

// imprimir a informação
void lcirc_imprime(Lista *l)
{
    Lista *p = l;
    do
    {
        printf("Dado = %d\n", p->dado);
        p = p->prox;
    } while (p != l);
}

int main(void)
{
    int i;
    Lista *listaint = list_cria();
    srand(time(NULL)); // inicializa a semente
    for (i = 0; i < 10; i++)
    {
        listaint = listc_adc(listaint, rand() % 50); // adicionando 10 valores aleatorios de 0 a 50 a lista
    }
    lcirc_imprime(listaint);
    list_libera(listaint);
    return 0;
}