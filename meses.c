#include <stdio.h>
#include <stdlib.h>

typedef union mes
{
    char Janeiro[10];
    char Fevereiro[10];
    char Marco[10];
    char Abril[10];
    char Maio[10];
    char Junho[10];
    char Julho[10];
    char Agosto[10];
    char Setembro[10];
    char Outubro[10];
    char Novembro[10];
    char Dezembro[10];
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
    scanf(" %[^\n]", &data.mes);
    printf("Insira o ano: ");
    scanf(" %d", &data.ano);
    printf("\n\n%d/%s/%d",data.dia,data.mes.Abril,data.ano);
    return 0;
}