#include "lista.c"
#include <time.h>

// função para retirar todas as ocorrências de um valor n da lista
Lista *retira_n(Lista *l, int n)
{
    Lista *ln = l; // ponteiro para percorrer a lista
    Lista *ant = NULL; // ponteiro para guardar o nó anterior ao nó atual

    while (ln != NULL)
    {
        // se encontrar um nó com o valor desejado, remove esse nó da lista
        if (ln->dado == n)
        {
            if (ant == NULL)
            {
                // se o nó a ser removido for o primeiro, atualiza o início da lista
                l = ln->prox;
            }
            else
            {
                // se o nó a ser removido não for o primeiro, atualiza o ponteiro do nó anterior
                ant->prox = ln->prox;
            }
            free(ln); // libera o nó da memória
            // atualiza os endereços
            ln = ant == NULL ? l : ant->prox;
        }
        else
        {
            // se o nó atual não tiver o valor desejado, atualiza o nó anterior e o nó atual
            ant = ln;
            ln = ln->prox;
        }
    }
    return l;
}

int main(void)
{
    int i, valor;
    Lista *listaint = list_cria(); 
    Lista *listanova = list_cria(); 
    srand(time(NULL)); // inicializa a semente do gerador de números aleatórios
    // adiciona 20 valores aleatórios de 0 a 25 à lista
    for (i = 0; i < 20; i++)
    {
        listaint = list_adc(listaint, rand() % 25);
    }
    printf("Lista:\n");
    list_imprime(listaint); 
    printf("\nInsira o valor que deseja eliminar:");
    scanf("%d", &valor); // lê o valor a ser removido
    listanova = retira_n(listaint, valor); 
    printf("\nLista atualizada:\n");
    list_imprime(listanova); 
    list_libera(listaint);
    list_libera(listanova);
    return 0;
}
