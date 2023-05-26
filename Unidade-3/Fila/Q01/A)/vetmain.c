#include "filavet.c"

void exibirMenu()
{
    printf("\n==== Menu ====\n");
    printf("1. Criar fila\n");
    printf("2. Inserir elemento\n");
    printf("3. Retirar elemento\n");
    printf("4. Verificar se a fila está vazia\n");
    printf("5. Verificar se a fila está cheia\n");
    printf("6. Imprimir fila\n");
    printf("7. Liberar fila\n");
    printf("0. Sair\n");
    printf("==============\n");
}

int main()
{
    Fila *fila = NULL;
    int opcao;
    float valor;
    do
    {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:
            printf("Encerrando o programa.\n");
            break;
        case 1:
            if (fila != NULL)
            {
                printf("Ja existe uma fila criada.\n");
                break;
            }
            fila = fila_cria();
            printf("Fila criada com sucesso.\n");
            break;
        case 2:
            if (fila == NULL)
            {
                printf("Crie uma fila primeiro.\n");
                break;
            }
            printf("Digite o valor a ser inserido: ");
            scanf("%f", &valor);
            fila_insere(fila, valor);
            break;
        case 3:
            if (fila == NULL)
            {
                printf("Crie uma fila primeiro.\n");
                break;
            }
            if (fila_vazia(fila))
            {
                printf("A fila esta vazia.\n");
                break;
            }
            valor = fila_retira(fila);
            printf("Valor %.1f retirado da fila.\n", valor);
            break;
        case 4:
            if (fila == NULL)
            {
                printf("Crie uma fila primeiro.\n");
                break;
            }
            if (fila_vazia(fila))
                printf("A fila esta vazia.\n");
            else
                printf("A fila nao esta vazia.\n");
            break;
        case 5:
            if (fila == NULL)
            {
                printf("Crie uma fila primeiro.\n");
                break;
            }
            if (fila_cheia(fila))
                printf("A fila esta cheia.\n");
            else
                printf("A fila nao esta cheia.\n");
            break;
        case 6:
            if (fila == NULL)
            {
                printf("Crie uma fila primeiro.\n");
                break;
            }
            printf("Conteudo da fila:\n");
            fila_imprime(fila);
            break;
        case 7:
            if (fila == NULL)
            {
                printf("Crie uma fila primeiro.\n");
                break;
            }
            fila_libera(fila);
            fila = NULL;
            printf("Fila liberada.\n");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    } while (opcao != 0);
    return 0;
}