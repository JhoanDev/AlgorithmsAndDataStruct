#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAGAS 10
#define MAX_TURMAS 3
#define NUM_NOTAS 3
#define MAX_NOME 81

typedef struct aluno
{
    int mat;
    char nome[MAX_NOME];
    float notas[NUM_NOTAS];
    float media;
} Aluno;

typedef struct turma
{
    char id;   /* caractere que identifica a turma, por exemplo, A ou B */
    int vagas; /* números de vagas disponíveis para fechar a turma */
    Aluno *alunos[MAX_VAGAS];
} Turma;

Turma *cria_turma(char id)
{
    Turma *t = malloc(sizeof(Turma)); // alocando memoria para a turma
    t->id = id;
    t->vagas = MAX_VAGAS;
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        t->alunos[i] = NULL; // definindo o vetor de alunos como nulo
    }
    return t;
}

void imprime_turmas(Turma **turmas, int n)
{
    for (int i = 0; i < n; i++)
    {
        Turma *turma = turmas[i];
        printf("Turma %c - Vagas disponiveis: %d\n", turma->id, turma->vagas);
        /*         if (turma->vagas == MAX_VAGAS)
                { // verificando se há alunos na turma
                    printf("Nao ha alunos matriculados.\n");
                }
                else
                {
                    // exibindo todos os dados da turma
                    for (int j = 0; j < MAX_VAGAS - turma->vagas; j++)
                    {
                        Aluno *aluno = turma->alunos[j];
                        printf("Matricula: %d | Nome: %s | Notas: %.1f ; %.1f ; %.1f | Media: %.1f\n", aluno->mat, aluno->nome, aluno->notas[0], aluno->notas[1], aluno->notas[2], aluno->media);
                    }
                }
                printf("\n"); */
    }
}

Turma *procura_turma(Turma **turma, int n, char id)
{
    int i = 0, verificadorindice = -1;
    for (i = 0; i < n; i++)
    {
        if (turma[i]->id == id)
        {
            verificadorindice = i;
        }
    }
    if (verificadorindice == -1)
    {
        return NULL;
    }
    else
    {
        return turma[verificadorindice];
    }
}

void matricula_aluno(Turma *turma, int mat, char *nome)
{
    // Verifica se ainda há vagas disponíveis na turma
    if (turma->vagas == 0)
    {
        printf("Nao ha vagas disponiveis na turma %c.\n", turma->id);
        return;
    }
    // Cria um novo aluno e preenche seus dados
    Aluno *novo_aluno = malloc(sizeof(Aluno));
    novo_aluno->mat = mat;
    strcpy(novo_aluno->nome, nome);
    novo_aluno->notas[0] = 0;
    novo_aluno->notas[1] = 0;
    novo_aluno->notas[2] = 0;
    novo_aluno->media = 0;
    // Adiciona o novo aluno à turma
    int i;
    for (i = 0; i < MAX_VAGAS; i++)
    {
        if (turma->alunos[i] == NULL)
        {
            turma->alunos[i] = novo_aluno;
            turma->vagas--;
            printf("Aluno matriculado com sucesso!");
            return;
        }
    }
}
void lanca_notas(Turma *turma)
{
    printf("Lancamento de notas para a turma %c:\n", turma->id);
    // percorre o vetor de alunos e solicita o lançamento das notas
    for (int j = 0; j < MAX_VAGAS; j++)
    {
        if (turma->alunos[j] != NULL)
        {
            printf("Matricula: %d\t - \tAluno: %s\n", turma->alunos[j]->mat, turma->alunos[j]->nome);
            for (int s = 0; s < 3; s++)
            {
                printf("Digite a nota %d: ", s + 1);
                scanf("%f", &turma->alunos[j]->notas[s]);
            }
            // calcula a média do aluno
            float soma = 0.0;
            for (int s = 0; s < 3; s++)
            {
                soma += turma->alunos[j]->notas[s];
            }
            turma->alunos[j]->media = soma / 3.0;
        }
    }
    printf("Notas lancadas com sucesso!\n");
}

void imprime_alunos(Turma *turma)
{
    printf("Alunos da turma %c:\n\n", turma->id);
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        Aluno *aluno = turma->alunos[i];
        if (aluno != NULL) // verificando se existe o aluno nesse espaço
        {
            printf("Matricula: %d\n", aluno->mat);
            printf("Nome: %s\n", aluno->nome);
            printf("Notas: %.1f, %.1f, %.1f\n", aluno->notas[0], aluno->notas[1], aluno->notas[2]);
            printf("Media: %.1f\n\n", aluno->media);
        }
    }
}

int main(void)
{
    // declarando variaveis
    char id, nome[MAX_NOME];
    Turma **turma = (Turma **)malloc(MAX_TURMAS * sizeof(Turma *));
    // verificando memoria
    if (turma == NULL)
    {
        printf("ERRO");
        exit(1);
    }
    Turma *minhaTurma;
    int controle = 0, n = 0, matricula = 0;
    // exibindo visor inicial
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\nEste programa gerencia as turmas ofertadas, fornecendo as\nfuncionalidades de matricula, lancamento de notas e listagem de alunos.\n\nAutor: Jhoan Fernandes\tVersao:2.0");
    while (controle != 6) // vai repetir ate o usuario digitar 6
    {
        printf("\n\nMenu:\n1-Criar turma\n2-Listar turmas\n3-Matricular aluno\n4-Lancar notas\n5-Listar alunos\n6-Sair\n\nDigite sua opcao: ");
        scanf("%d", &controle);
        system("cls");
        switch (controle)
        {
        case 1:
            printf("Criando uma nova turma...");
            printf("\nDigite um id: ");
            scanf(" %c", &id);
            if (n > 3)
            {
                printf("numero maximo atingido");
            }
            else
            {
                turma[n] = (Turma *)malloc(sizeof(Turma));
                turma[n] = cria_turma(id);
                n++; // quantidade de turmas ate agora
                printf("Turma %c criada com sucesso!", id);
            }
            break;
        case 2:
            imprime_turmas(turma, n);
            break;
        case 3:
            printf("Matriculando aluno...");
            printf("\nDigite o id da turma: ");
            scanf(" %c", &id);
            minhaTurma = procura_turma(turma, n, id);
            if (minhaTurma != NULL)
            {
                printf("Digite a matricula: ");
                scanf("%d", &matricula);
                printf("Digite o nome: ");
                scanf(" %[^\n]s", (char *)&nome);
                matricula_aluno(minhaTurma, matricula, nome);
            }
            else
            {
                printf("Turma inexistente!");
            }
            break;
        case 4:
            printf("Lancando notas...");
            printf("\nDigite o id da turma: ");
            scanf(" %c", &id);
            minhaTurma = procura_turma(turma, n, id);
            if (minhaTurma != NULL)
            {
                lanca_notas(minhaTurma);
            }
            else
            {
                printf("Turma inexistente!");
            }
            break;
        case 5:
            printf("Listando alunos...");
            printf("\nDigite o id da turma: ");
            scanf(" %c", &id);
            minhaTurma = procura_turma(turma, n, id);
            if (minhaTurma != NULL)
            {
                imprime_alunos(minhaTurma);
            }
            else
            {
                printf("Turma inexistente!");
            }
            break;
        case 6:
            printf("Obrigado por usar meu programa!");
            break;
        default:
            printf("opcao invalida!");
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        free(turma[i]);
    }
    free(turma);
    return 0;
}
