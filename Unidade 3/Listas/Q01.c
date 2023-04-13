#include "lista.c"
#include <time.h>

int maiores(Lista *l, int n)
{
    // exibindo a lista
    Lista *p;
    int k = 0;
    printf("\n");
    list_imprime(l);
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->dado > n)
        {
            k++;
        }
    }
    return k;
}

int main(void)
{
    int i, no, valor;
    Lista *listaint = list_cria();
    srand(time(NULL)); // inicializa a semente
    for (i = 0; i < 10; i++)
    {
        listaint = list_adc(listaint, rand() % 50); // adicionando 10 valores aleatorios de 0 a 50 a lista
    }
    printf("Insira um valor para descobrir quantos maiores que ele existem na lista: ");
    scanf("%d", &valor);
    no = maiores(listaint, valor);
    printf("\nExistem %d (nos) com dados maiores que %d na lista", no, valor);
    return 0;
}