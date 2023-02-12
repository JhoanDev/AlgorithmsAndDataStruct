#include <stdio.h>
#include <stdlib.h>

typedef struct funcionarios
{
    char nome[75];
    float salario;
    int id;
    char cargo[25];
} funcionarios;

void preenchefuncionarios(funcionarios *funcionario, int qnt)
{
    for (size_t i = 0; i < qnt; i++)
    {
        printf("Digite o nome do funcionario %d: ",i+1);
        scanf(" %[^\n]", funcionario[i].nome);
        printf("Digite o salario do funcionario %d: ",i+1);
        scanf("%f", &funcionario[i].salario);
        printf("Digite o ID do funcionario %d: ",i+1);
        scanf("%d", &funcionario[i].id);
        printf("Digite o cargo do funcionario %d: ",i+1);
        scanf(" %[^\n]", funcionario[i].cargo);
        system("cls");
    }
}

void imprime (funcionarios *funcionario, int qnt)
{
    for (size_t i = 0; i < qnt; i++)
    {
        printf("Funcionario %d\n", i+1);
        printf("Nome: %s\n", funcionario[i].nome);
        printf("ID: %d\n", funcionario[i].id);
        printf("Salario: %.2f\n", funcionario[i].salario);
        printf("Cargo :%s\n", funcionario[i].cargo);
        printf("==================================\n");
    }
}

void alterasalario(funcionarios *funcionario){

}

int main(void)
{
    int qnt;
    printf("Quantos funcionarios deseja cadastrar?");
    scanf("%d", &qnt);
    funcionarios *funcionario = malloc(qnt * sizeof(funcionarios));
    preenchefuncionarios(funcionario, qnt);
    imprime(funcionario, qnt);
    alterasalario(funcionario);
    free(funcionario);
    return 0;
}
