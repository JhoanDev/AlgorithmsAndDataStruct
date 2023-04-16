#include "lista.c"
#include <time.h>

Lista *contatena(Lista *l1, Lista *l2)
{
    if (list_vazia(l1))
    {
        return l2;
    }

    Lista *lfnl = l1;
    while (lfnl->prox != NULL)
    {
        lfnl = lfnl->prox;
    }
    lfnl->prox = l2;

    return l1;
}

int main(void)
{
    int i;
    Lista *listaint1 = list_cria();
    Lista *listaint2 = list_cria();
    srand(time(NULL));           // inicializa a semente
    int tamanhol1 = rand() % 10; // definindo o tamanho da lista aleatoriamente
    int tamanhol2 = rand() % 10;
    for (i = 0; i < (tamanhol1 + 1); i++)
    {
        listaint1 = list_adc(listaint1, rand() % 50); // adicionando valores aleatorios de 0 a 50 a lista
    }
    for (i = 0; i < (tamanhol2 + 1); i++)
    {
        listaint2 = list_adc(listaint2, rand() % 50); // adicionando valores aleatorios de 0 a 50 a lista
    }
    printf("Lista 1:\n");
    list_imprime(listaint1);
    printf("\nLista 2:\n");
    list_imprime(listaint2);
    Lista *final = contatena(listaint1, listaint2);
    printf("\nLista concatenada:\n");
    list_imprime(final);
    list_libera(listaint1);
    list_libera(listaint2);
    list_libera(final);
    return 0;
}