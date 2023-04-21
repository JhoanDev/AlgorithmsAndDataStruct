#include <stdio.h>
#include "pilhaL.c"

int main()
{
    Pilha *p = pilha_cria();
    printf("Pilha criada:\n");
    pilha_imprime(p);
    printf("\nEmpilhando elementos...\n");
    pilha_push(p, 4.5);
    pilha_push(p, 23.8);
    pilha_push(p, 10.2);
    pilha_push(p, 13.2);
    pilha_push(p, 17.2);
    printf("\nPilha atualizada:\n");
    pilha_imprime(p);
    printf("\nDesempilhando elementos...\n");
    printf("Elemento desempilhado: %.1f\n", pilha_pop(p));
    printf("Elemento desempilhado: %.1f\n", pilha_pop(p));
    printf("\nPilha atualizada:\n");
    pilha_imprime(p);
    printf("\nEmpilhando mais elementos...\n");
    pilha_push(p, 7.1);
    pilha_push(p, 9.6);
    printf("\nPilha atualizada:\n");
    pilha_imprime(p);
    // Liberando memória...
    pilha_libera(p);
    return 0;
}