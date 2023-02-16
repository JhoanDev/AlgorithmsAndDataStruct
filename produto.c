#include <stdio.h>
#include <stdlib.h>

typedef union tipos
{
    char Alimento[10];
    char Bebida[10];
    char Eletronico[10];
} Tipos;

typedef struct produto
{
    char nome[50];
    float preco;
    Tipos tipo;
} Produto;

int main(void)
{
    Produto produto;
    printf("Insira o nome do produto: ");
    scanf(" %[^\n]", produto.nome);
    printf("Insira o preco do produto: ");
    scanf(" %f", &produto.preco);
    printf("Qual o tipo do produto? (Alimento, Bebida ou Eletronico)");
    scanf(" %[^\n]", produto.tipo.Alimento);
    printf("\nNome do produto: %s", produto.nome);
    printf("\nPreço do produto: %.2f", produto.preco);
    printf("\nTipo do produto: %s", produto.tipo.Alimento);
    return 0;
}
