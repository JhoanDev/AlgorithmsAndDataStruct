#include "lista.c"
#include <time.h>

Lista *ultimo(Lista *l)
{
    if (list_vazia(l) == 1)
    {
        printf("A lista esta vazia");
        exit(1);
    }
    while (l->prox != NULL)
    {
        l = l->prox; //avança para o proximo nó
    }
    return l;
}

int main(void)
{
    int i;
    Lista *listaint = list_cria();
    srand(time(NULL)); // inicializa a semente
    for (i = 0; i < 10; i++)
    {
        listaint = list_adc(listaint, rand() % 50); // adicionando 10 valores aleatorios de 0 a 50 a lista
    }
    list_imprime(listaint);
    Lista *final = ultimo(listaint);
    printf("\nO valor do ultimo (no) da lista: %d",final->dado);
    return 0;
}