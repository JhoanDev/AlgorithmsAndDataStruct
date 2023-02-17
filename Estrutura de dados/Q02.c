#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa
{
    char nome[50];
    int documento;
    int idade;
} Pessoa;

void cadastrapessoa(Pessoa *pessoa, int qnt)
{ // cadastra as pessoas
    for (int i = 0; i < qnt; i++)
    {
        printf("\nInsira o nome da %d pessoa: ", i + 1);
        scanf(" %[^\n]s", pessoa[i].nome);
        printf("Insira o documento da %d pessoa: ", i + 1);
        scanf("%d", &pessoa[i].documento);
        printf("Insira a idade da %d pessoa: ", i + 1);
        scanf("%d", &pessoa[i].idade);
    }
}

void exibepessoa(Pessoa *pessoa, int qnt)
{

    for (int i = 0; i < qnt; i++)
    {
        printf("\nPessoa %d: %s", i + 1, pessoa[i].nome);
        printf("\nDocumento %d: %d", i + 1, pessoa[i].documento);
        printf("\nIdade %d: %d\n", i + 1, pessoa[i].idade);
    }
}

void alteraidade(Pessoa *pessoa, int qnt)
{
    int n;
    printf("\n\nInsira o numero da pessoa que quer alterar a idade de acordo com a lista anterior: ");
    scanf("%d",&n);
    if (n <= 0 || n > qnt) { //verificando se o numero é valido
        printf("Erro: numero invalido.\n");
        return;
    }
    printf("Insira a nova idade: ");
    scanf("%d", &pessoa[n-1].idade);
    printf("\nIdade alterada!\n");
}

void maiormenor(Pessoa *pessoa, int qnt)
{
    int idmaior, idmenor;
    idmaior = 0;
    idmenor = 0;
    //procurando o indice da pessoa com o maior/menor idade
    for (int i = 0; i < qnt; i++)
    {
        if (pessoa[i].idade > pessoa[idmaior].idade)
        {
            idmaior = i;
        }
        if (pessoa[i].idade < pessoa[idmenor].idade)
        {
            idmenor = i;
        }
    }
    printf("==================================\n");
    printf("pessoa com o maior idade:\n");
    printf("Nome: %s\n", pessoa[idmaior].nome);
    printf("Documento: %d\n", pessoa[idmaior].documento);
    printf("idade: %d\n", pessoa[idmaior].idade);
    printf("==================================\n");
    printf("pessoa com o menor idade:\n");
    printf("Nome: %s\n", pessoa[idmenor].nome);
    printf("Documento: %d\n", pessoa[idmenor].documento);
    printf("idade: %d\n", pessoa[idmenor].idade);
    printf("==================================\n");
}

int main(void)
{
    int qnt;
    Pessoa *pessoa;
    printf("quantas pessoas deseja cadastrar: ");
    scanf("%d", &qnt);
    pessoa = (Pessoa *)malloc(qnt * sizeof(Pessoa)); // alocando memoria
    cadastrapessoa(pessoa, qnt);
    exibepessoa(pessoa, qnt);
    alteraidade(pessoa, qnt);
    exibepessoa(pessoa, qnt);
    maiormenor(pessoa,qnt);
    return 0;
}