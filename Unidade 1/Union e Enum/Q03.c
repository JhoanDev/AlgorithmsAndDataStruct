#include <stdio.h>
#include <stdlib.h>

typedef enum mes
{
    Janeiro,
    Fevereiro,
    Marco,
    Abril,
    Maio,
    Junho,
    Julho,
    Agosto,
    Setembro,
    Outubro,
    Novembro,
    Dezembro
} Mes;

typedef struct data
{
    int dia;
    Mes mes;
    int ano;
} Data;

int main(void)
{
    Data data;
    printf("Insira o dia de hoje: ");
    scanf(" %d", &data.dia);
    printf("Insira o mes: ");
    scanf(" %d", &data.mes);
    data.mes += -1;
    printf("Insira o ano: ");
    scanf(" %d", &data.ano);
    switch (data.mes)
    {
    case Janeiro:
        printf("\n\n%d/01/%d", data.dia, data.ano);
        break;
    case Fevereiro:
        printf("\n\n%d/02/%d", data.dia, data.ano);
        break;
    case Marco:
        printf("\n\n%d/03/%d", data.dia, data.ano);
        break;
    case Abril:
        printf("\n\n%d/04/%d", data.dia, data.ano);
        break;
    case Maio:
        printf("\n\n%d/05/%d", data.dia, data.ano);
        break;
    case Junho:
        printf("\n\n%d/06/%d", data.dia, data.ano);
        break;
    case Julho:
        printf("\n\n%d/07/%d", data.dia, data.ano);
        break;
    case Agosto:
        printf("\n\n%d/08/%d", data.dia, data.ano);
        break;
    case Setembro:
        printf("\n\n%d/09/%d", data.dia, data.ano);
        break;
    case Outubro:
        printf("\n\n%d/10/%d", data.dia, data.ano);
        break;
    case Novembro:
        printf("\n\n%d/11/%d", data.dia, data.ano);
        break;
    case Dezembro:
        printf("\n\n%d/12/%d", data.dia, data.ano);
        break;
    default:
        printf("ERRO");
        break;
    }

    return 0;
}