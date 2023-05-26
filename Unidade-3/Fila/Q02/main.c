#include "fila.c"

void combina_filas(Fila *f_res, Fila *f1, Fila *f2)
{
    float v;
    while (f1->ini != NULL && f2->ini != NULL)
    {
        if (f1->ini != NULL)
        {
            v = fila_retira(f1);
            fila_insere(f_res, v);
        }
        if (f2->ini != NULL)
        {
            v = fila_retira(f2);
            fila_insere(f_res, v);
        }
    }

    while (f2->ini != NULL)
    {
        v = fila_retira(f2);
        fila_insere(f_res, v);
    }
    while (f1->ini != NULL)
    {
        v = fila_retira(f1);
        fila_insere(f_res, v);
    }
}

int main(void)
{
    // criando filas
    Fila *f1 = fila_cria();
    Fila *f2 = fila_cria();
    Fila *f_res = fila_cria();
    // adicionando valores
    fila_insere(f_res, 1.0);
    fila_insere(f1, 2.4);
    fila_insere(f1, 5.2);
    fila_insere(f1, 7.6);
    fila_insere(f2, 2.3);
    fila_insere(f2, 2.5);
    fila_insere(f2, 2.7);
    fila_insere(f2, 10.3);
    // imprimindo filas criadas ate o momento;
    printf("\n=============Fila 1=============\n");
    fila_imprime(f1);
    printf("\n=============Fila 2=============\n");
    fila_imprime(f2);
    printf("\n================================\n");
    combina_filas(f_res, f1, f2);
    printf("\n=============Fila res=============\n");
    fila_imprime(f_res);
    printf("\n==================================\n");
    return 0;
}