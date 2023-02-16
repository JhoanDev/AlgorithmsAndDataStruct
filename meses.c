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
    printf("Insira o ano: ");
    scanf(" %d", &data.ano);
    switch (data.mes)
    {
    case 1:
        printf("\n\n%d/01/%d", data.dia, data.ano);
        break;
    case 2:
        printf("\n\n%d/02/%d", data.dia, data.ano);
        break;
    case 3:
        printf("\n\n%d/03/%d", data.dia, data.ano);
        break;
    case 4:
        printf("\n\n%d/04/%d", data.dia, data.ano);
        break;
    case 5:
        printf("\n\n%d/05/%d", data.dia, data.ano);
        break;
    case 6:
        printf("\n\n%d/06/%d", data.dia, data.ano);
        break;
    case 7:
        printf("\n\n%d/07/%d", data.dia, data.ano);
        break;
    case 8:
        printf("\n\n%d/08/%d", data.dia, data.ano);
        break;
    case 9:
        printf("\n\n%d/09/%d", data.dia, data.ano);
        break;
    case 10:
        printf("\n\n%d/10/%d", data.dia, data.ano);
        break;
    case 11:
        printf("\n\n%d/11/%d", data.dia, data.ano);
        break;
    case 12:
        printf("\n\n%d/12/%d", data.dia, data.ano);
        break;
    default:
        printf("ERRO");
        break;
    }

    return 0;
}