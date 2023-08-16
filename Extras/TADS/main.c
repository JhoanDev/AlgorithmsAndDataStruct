#include "aluno.c"

#define MAX_ALUNO 20
#define MAX_DISCIPLINAS 15

int main()
{
    Aluno *Alunos[MAX_ALUNO];
    Disciplina *disciplinas[MAX_DISCIPLINAS];
    int qntaluno = 0, qntdisciplinas = 0;
    int opc = 0;
    int mat, cod;
    do
    {
        printf("\n[1]\tCriar disciplina\n");
        printf("[2]\tMatricular aluno\n");
        printf("[3]\tMatricular aluno em uma disciplina\n");
        printf("[4]\tExibir alunos\n");
        printf("[5]\tExibir disciplinas\n");
        printf("[0]\tSair\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            if (qntdisciplinas < MAX_DISCIPLINAS)
            {
                char nome[100];
                int Codigo;
                printf("Insira o nome da disciplina: ");
                scanf(" %[^\n]s", nome);
                printf("Inisira a Codigo da disciplina: ");
                scanf("%d", &Codigo);
                disciplinas[qntdisciplinas] = cria_disciplina(nome, Codigo);
                qntdisciplinas++;
            }
            else
            {
                printf("Limite excedido!\n");
            }
            break;
        case 2:
            if (qntaluno < MAX_ALUNO)
            {
                char nome[100];
                int matricula;
                printf("Insira o nome do aluno: ");
                scanf(" %[^\n]s", nome);
                printf("Inisira a matricula do aluno: ");
                scanf("%d", &matricula);
                Alunos[qntaluno] = cria_aluno(nome, matricula);
                qntaluno++;
            }
            else
            {
                printf("Limite excedido!\n");
            }
            break;
        case 3:
            printf("Qual Disciplina? Insira o codigo: ");
            scanf("%d", &cod);
            for (int j = 0; j < qntdisciplinas; j++)
            {
                if (disciplinas[j]->codigo == cod)
                {
                    printf("Qual aluno vai se matricular insira a matricula dele: ");
                    scanf("%d", &mat);
                    for (int i = 0; i < qntaluno; i++)
                    {
                        if (Alunos[i]->matricula == mat)
                        {
                            matricula_disciplina(Alunos[i], disciplinas[j]);
                            break;
                        }
                        else if (i == qntaluno - 1)
                        {
                            printf("O aluno nao existe!\n");
                            break;
                        }
                    }
                    break;
                }
                else if (j == qntdisciplinas - 1)
                {
                    printf("A Disciplina nao existe!\n");
                    break;
                }
            }

            break;
        case 4:
            for (int i = 0; i < qntaluno; i++)
            {
                printf("\nAluno %d\n", i + 1);
                printf("Nome:%s\n", Alunos[i]->nome);
                printf("Matricula:%d\n", Alunos[i]->matricula);
                for (int j = 0; j < Alunos[i]->num_disciplinas; j++)
                {
                    printf("Disciplina: %s (Codigo: %d)\n", Alunos[i]->disciplinas[j]->nome, Alunos[i]->disciplinas[j]->codigo);
                }
            }
            break;
        case 5:
            for (int i = 0; i < qntdisciplinas; i++)
            {
                printf("\nDisciplina %d\n", i + 1);
                printf("Nome:%s\n", disciplinas[i]->nome);
                printf("Codigo:%d\n", disciplinas[i]->codigo);
            }
            break;
        case 0:
            printf("Obrigado por utilizar meu programa!\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (opc != 0);
    for (int i = 0; i < qntaluno; i++)
    {
        exclui_aluno(Alunos[i]);
    }
    for (int i = 0; i < qntdisciplinas; i++)
    {
        exclui_disciplina(disciplinas[i]);
    }
    return 0;
}