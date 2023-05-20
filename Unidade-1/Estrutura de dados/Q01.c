#include <stdio.h>
#include <stdlib.h>

//declarando struct
typedef struct funcionarios
{
    char nome[75];
    float salario;
    int id;
    char cargo[25];
} funcionarios;

void preenchefuncionarios(funcionarios *funcionario, int *qnt)
{
    int n;
    printf("quantos funcionarios deseja cadastrar:");
    scanf("%d", &n);
    funcionario = realloc(funcionario, (*qnt + n) * sizeof(funcionarios)); //reallocando memoria dinamicamente
    if (funcionario == NULL)
    {
        printf("Erro");
        exit(1);
    }
    for (int i = (*qnt); i < n + (*qnt); i++) // preenchendo funcionarios
    {
        printf("Digite o nome do funcionario %d: ", i + 1);
        scanf(" %[^\n]", funcionario[i].nome);
        printf("Digite o salario do funcionario %d: ", i + 1);
        scanf("%f", &funcionario[i].salario);
        printf("Digite o ID do funcionario %d: ", i + 1);
        scanf("%d", &funcionario[i].id);
        printf("Digite o cargo do funcionario %d: ", i + 1);
        scanf(" %[^\n]", funcionario[i].cargo);
        system("cls");
    }
    (*qnt) += n;
}

void imprime(funcionarios *funcionario, int *qnt)
{
    for (int i = 0; i < (*qnt); i++) //exibindo funcionarios
    {
        printf("Funcionario %d\n", i + 1);
        printf("Nome: %s\n", funcionario[i].nome);
        printf("ID: %d\n", funcionario[i].id);
        printf("Salario: %.2f\n", funcionario[i].salario);
        printf("Cargo :%s\n", funcionario[i].cargo);
        printf("==================================\n");
    }
}

void alterasalario(funcionarios *funcionario, int *qnt)
{
    int cont = 0, verificador = 0;

    do
    {
        verificador = 0;
        do
        {
            printf("Insira o numero do funcionario de acordo com a tabela: ");
            scanf("%d", &cont); //selecionando o funcioonario que tera o salario alterado
            if (cont > (*qnt) || cont <= 0)
            {
                printf("Número inválido, por favor insira um número válido.\n");
                verificador = 2;
            }
            else
            {
                printf("\nFuncionario %d\n", cont);
                printf("Nome: %s\n", funcionario[cont - 1].nome);
                printf("ID: %d\n", funcionario[cont - 1].id);
                printf("Salario: %.2f\n", funcionario[cont - 1].salario);
                printf("Cargo :%s\n", funcionario[cont - 1].cargo);
                printf("\nEste e o funcionario que deseja alterar o salario? (1-sim) (2-nao)\n");
                scanf("%d", &verificador);
            }

        } while (verificador == 2);
        verificador = 0;
        printf("Insira o novo salario: ");
        scanf("%f", &funcionario[cont - 1].salario);
        printf("Alterado com sucesso! \nDeseja alterar de mais algum funcionario? (1-sim) (2-nao)");
        scanf("%i", &verificador);
        system("cls");
    } while (verificador == 1);
}

void maiormenor(funcionarios *funcionario, int *qnt)
{
    int idmaior, idmenor;
    idmaior = 0;
    idmenor = 0;
    //procurando o indice do funcionario com o maior/menor salario
    for (int i = 0; i < (*qnt); i++)
    {
        if (funcionario[i].salario > funcionario[idmaior].salario)
        {
            idmaior = i;
        }
        if (funcionario[i].salario < funcionario[idmenor].salario)
        {
            idmenor = i;
        }
    }
    printf("Funcionario com o maior salario:");
    printf("Nome: %s\n", funcionario[idmaior].nome);
    printf("ID: %d\n", funcionario[idmaior].id);
    printf("Salario: %.2f\n", funcionario[idmaior].salario);
    printf("Cargo :%s\n", funcionario[idmaior].cargo);
    printf("==================================\n");
    printf("Funcionario com o menor salario:\n");
    printf("Nome: %s\n", funcionario[idmenor].nome);
    printf("ID: %d\n", funcionario[idmenor].id);
    printf("Salario: %.2f\n", funcionario[idmenor].salario);
    printf("Cargo :%s\n", funcionario[idmenor].cargo);
    printf("==================================\n");
}

int main(void)
{
    int qnt = 0, cont;
    int *p = &qnt;
    funcionarios *funcionario = malloc(sizeof(funcionarios));//alocando memoria inicial
    if (funcionario == NULL)
    {
        printf("Erro");
        exit(1);
    }
    //criando uma tela inicial para o programa
    do
    {
        printf("O que deseja fazer?\n0-Exibir lista de funcionarios\n1-Cadastrar funcionarios\n2-Alterar salario\n3-Exibir maior e menor salario\n4-fechar o programa\n");
        scanf("%d", &cont);
        system("cls");
        switch (cont)
        {
        case 0:
            imprime(funcionario, p);
            break;
        case 1:
            preenchefuncionarios(funcionario, p);
            break;
        case 2:
            alterasalario(funcionario, p);
            break;
        case 3:
            maiormenor(funcionario, p);
            break;
        default:
            break;
        }
    } while (cont != 4);
    free(funcionario); //liberando memoria
    return 0;
}
