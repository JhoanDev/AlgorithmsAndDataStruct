#include "listadupla.c"
#include <time.h>

// imprime a lista
void l2circ_imprime_rev(Listad *l)
{
    if (l == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }
    Listad *p = l;
    do
    {
        printf("Dado = %d\n", p->dado);
        p = p->ant;
    } while (p != l);
}

int main(void)
{
    int i;
    Listad *listadint = listd_cria();
    srand(time(NULL)); // inicializa a semente
    for (i = 0; i < 10; i++)
    {
        listadint = listdc_adc(listadint, rand() % 50); // adicionando 10 valores aleatorios de 0 a 50 a lista
    }
    l2circ_imprime_rev(listadint);
    printf("============\n");
    listdc_imprime(listadint);
    listd_libera(listadint);
    return 0;
}