#include "listadupla.c"
#include <time.h>

/* // adiciona em uma lista dupla circular
Listad *listdc_adc(Listad *l, int v)
{
    Listad *novo = (Listad *)malloc(sizeof(Listad));
    novo->dado = v;
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
*/


int main(void)
{
    int i, valor;
    Listad *listaint = listd_cria(); 
    srand(time(NULL)); // inicializa a semente do gerador de números aleatórios
    // adiciona 20 valores aleatórios de 0 a 25 à lista
    for (i = 0; i < 20; i++)
    {
        listaint = listdc_adc(listaint, rand() % 25);
    }
    printf("Lista:\n");
    listdc_imprime(listaint); 
    printf("\nInsira o valor que deseja eliminar:");
    scanf("%d", &valor); // lê o valor a ser removido
    listaint = listdc_retira(listaint, valor); 
    printf("\nLista atualizada:\n");
    listdc_imprime(listaint); 
    listd_libera(listaint);
    return 0;
}
