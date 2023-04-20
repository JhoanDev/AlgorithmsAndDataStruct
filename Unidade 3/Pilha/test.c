#include "pilha.c"
#include <time.h>


int main(void)
{
    Pilha *Pilhafloat = pilha_cria();
    srand(time(NULL)); // inicializa a semente
    pilha_push(Pilhafloat, 50.3);
    pilha_push(Pilhafloat, 34.3);   
    pilha_push(Pilhafloat, 53.3);
    pilha_imprime(Pilhafloat);
    pilha_libera(Pilhafloat);
    return 0;
}