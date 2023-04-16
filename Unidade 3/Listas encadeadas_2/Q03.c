#include "listadupla.c"
#include <time.h>

int main(void)
{
    int i;
    Listad *listadint = list_cria();
    srand(time(NULL)); // inicializa a semente
    for (i = 0; i < 10; i++)
    {
        listadint = listd_adc(listadint, rand() % 50); // adicionando 10 valores aleatorios de 0 a 50 a lista
    }
    listd_imprime(listadint);
    listd_libera(listadint);
    return 0;
}