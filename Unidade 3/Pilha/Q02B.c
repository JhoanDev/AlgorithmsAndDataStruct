#include "pilhav.c"

void concatena_pilhas(Pilha* p1, Pilha* p2){
    if (p1 == NULL || p2 == NULL) {
        printf("Erro: pilhas não inicializadas.\n");
        exit(1);
    }
    if (pilha_vazia(p2)) {
        printf("Pilha 2 está vazia. Não há elementos para concatenar.\n");
        exit(1);
    }
    int i;
    for (i = 0; i < p2->size; i++) {
        pilha_push(p1, p2->data[i]);
    }
    printf("Pilhas concatenadas!\n");
    pilha_imprime(p1);
}

int main(void)
{
    Pilha *p1 = pilha_cria();
    Pilha *p2 = pilha_cria();
    printf("Pilhas criadas!\n");
    printf("Empilhando elementos...\n");
    pilha_push(p1, 1.0);
    pilha_push(p1, 4.5);
    pilha_push(p1, 2.1);
    pilha_push(p2, 9.8);
    pilha_push(p2, 3.1);
    pilha_push(p2, 7.2);
    printf("1 ");
    pilha_imprime(p1);
    printf("2 ");
    pilha_imprime(p2);
    concatena_pilhas(p1,p2);
    pilha_libera(p1);
    pilha_libera(p2);
    return 0;
}