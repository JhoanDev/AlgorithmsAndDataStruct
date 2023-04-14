#include <stdio.h>
#include <stdlib.h>

typedef enum genero //declarando enum
{
    masculino,
    feminino,
    neutro
} Genero;

typedef struct pessoa //declarando struct
{
    char nome[50];
    int idade;
    Genero genero;
} Pessoa;

int main(void)
{
    Pessoa pessoa;
    printf("Insira o nome da pessoa: ");
    scanf(" %[^\n]s", &pessoa.nome);
    printf("Insira a idade da pessoa: ");
    scanf(" %d", &pessoa.idade);
    printf("insira o genero da pessoa 0-Masculino 1-Feminino 2-neutro\n");
    scanf("%d",(int*)&pessoa.genero);
    if (pessoa.genero == masculino)
    {
        printf("\nNome: %s",pessoa.nome);
        printf("\nIdade: %d",pessoa.idade);
        printf("\nGenero: Masculino");
    }
    else if(pessoa.genero == feminino){
        printf("\nNome: %s",pessoa.nome);
        printf("\nIdade: %d",pessoa.idade);
        printf("\nGenero: Feminino");
    }
    else{
        printf("\nNome: %s",pessoa.nome);
        printf("\nIdade: %d",pessoa.idade);
        printf("\nGenero: Neutro");
    }
    return 0;
}