/*O programa permite ao usuário criar uma lista de produtos, onde cada produto é descrito por um nome, preço e quantidade.
 O usuário pode adicionar, exibir e remover produtos da lista. ao fim do codigo deve aparecer a soma de todos produtos
 para saber o preço total,quantidade de tipos e quantidade geral. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXName 40
#define MINQuantidade 0
#define MINPreco 0.0

typedef struct produtos // criando estrutura
{
    char nome[MAXName];
    int quantidade;
    float preco;
} produtos;

void addproduto(produtos *produto, int *i) // função para adicionar produto
{
    int cont;
    do
    {
        printf("Digite o nome do produto: ");
        scanf("%s", produto[*i].nome);
        printf("Digite a quantidade do produto: ");
        scanf("%d", &produto[*i].quantidade);
        while (produto[*i].quantidade < MINQuantidade)
        {
            printf("Por favor insira uma quantidade valida: ");
            scanf("%d", &produto[*i].quantidade);
        }
        printf("Digite o preco do produto: ");
        scanf("%f", &produto[*i].preco);
        while (produto[*i].preco < MINPreco)
        {
            printf("Por favor insira uma preco valido: ");
            scanf("%f", &produto[*i].preco);
        }
        (*i)++;
        produto = realloc(produto, ((*i) + 1) * sizeof(produtos));
        if (produto == NULL)
        {
            printf("Erro na alocação de memoria, Fechando o programa...");
            exit(1);
        }
        printf("\nDeseja cadastrar mais algum produto?\nsim-1\nnao-2\n");
        scanf("%d", &cont);
        printf("\n");
    } while (cont != 2);
}
void exibirprodutos(produtos *produto, int *i)
{ // função para exibir a lista de produtos
    printf("\n------------------Lista de produtos------------------");
    for (int j = 0; j < *i; j++)
    {
        printf("\nNome do produto %d: %s\nQuantidade em estoque: %d\nPreco da unidade: R$%.2f", j + 1, produto[j].nome, produto[j].quantidade, produto[j].preco);
        printf("\n-----------------------------------------------------");
    }
    printf("\n");
}

void analiseprodutos(int *total, int *quantidades, float *valortotal, produtos *produto, int *i) // função para analisar e exibir os resultados
{
    int j;
    printf("\n-----------------Analise dos produtos----------------");
    for (j = 0; j < (*i); j++)
    {
        *quantidades += produto[j].quantidade;
        *valortotal += produto[j].preco * produto[j].quantidade;
    }
    *total = *i;
    printf("\nQuantidade de produtos diferentes cadastrados: %d\nQuantidade total de produtos: %d\nValor total de todos os produtos: R$%.2f", *total, *quantidades, *valortotal);
    printf("\n-----------------------------------------------------\n");
}

void removerproduto(produtos *produto) // função para remover todos os dados de um produto especifico
{
    int j = 0;
    printf("insira o numero em que o produto que voce quer remover esta cadastrado(de acordo com a tabela do (exibirprodutos): ");
    scanf("%d", &j);
    strcpy(produto[j - 1].nome, "PRODUTO REMOVIDO");
    produto[j - 1].quantidade = 0;
    produto[j - 1].preco = 0.00;
}

void editarproduto(produtos *produto) //função editar produto
{
    int j, opc;
    printf("insira o numero em que o produto que voce quer alterar esta cadastrado(de acordo com a tabela do (exibirprodutos): ");
    scanf("%d", &j);
    printf("Digite o nome do novo produto: ");
    scanf("%s", produto[j - 1].nome);
    printf("Digite a quantidade do novo produto: ");
    scanf("%d", &produto[j - 1].quantidade);
    while (produto[j - 1].quantidade < MINQuantidade)
    {
        printf("Por favor insira uma quantidade valida: ");
        scanf("%d", &produto[j - 1].quantidade);
    }
    printf("Digite o preco do novo produto: ");
    scanf("%f", &produto[j - 1].preco);
    while (produto[j - 1].preco < MINPreco)
    {
        printf("Por favor insira uma preco valido: ");
        scanf("%f", &produto[j - 1].preco);
    }
}

int main(void)
{
    produtos *produto = (produtos *)malloc(sizeof(produtos));
    if (produto == NULL)
    {
        printf("Erro na alocação de memoria, Fechando o programa...");
        exit(1);
    }
    int qnt = 0, cont = 1, i = 0, total = 0, quantidades = 0;
    float valortotal = 0;
    do
    {
        printf("O que deseja fazer?\n1-Exibir lista de produtos\n2-Exibir analise dos produtos\n3-Adcionar mais produtos\n4-Remover produto\n5-Editar produto\n6-Fechar o programa\n");
        scanf("%d", &cont);
        switch (cont)
        {
        case 1:
            exibirprodutos(produto, &i);
            break;
        case 2:
            analiseprodutos(&total, &quantidades, &valortotal, produto, &i);
            break;
        case 3:
            addproduto(produto, &i);
            break;
        case 4:
            removerproduto(produto);
            break;
        case 5:
            editarproduto(produto);
        default:
            break;
        }
    } while (cont != 6);
    free(produto);
    return 0;
}