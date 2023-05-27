#include "aluno.c"

int main()
{
    // Criando cinco alunos e armazenando-os em um vetor de ponteiros
    Aluno **alunos[5];
    alunos[0] = aluno_cria("João", 7.5);
    alunos[1] = aluno_cria("Maria", 8.2);
    alunos[2] = aluno_cria("Pedro", 6.9);
    alunos[3] = aluno_cria("Ana", 9.1);
    alunos[4] = aluno_cria("Carlos", 7.8);
    // Imprimindo os dados dos cinco alunos
    printf("Dados dos alunos antes da ordenação:\n");
    for (int i = 0; i < 5; i++)
    {
        aluno_imprime(alunos[i]);
        printf("\n");
    }
    // Ordenando o vetor de ponteiros
    aluno_ordena(5, alunos);
    // Salvando os dados dos alunos em um arquivo texto
    FILE *fp = fopen("alunos.txt", "w");
    if (fp == NULL)
    {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }
    aluno_salva(fp, 5, alunos);
    fclose(fp);
    printf("Dados dos alunos salvos no arquivo 'alunos.txt' com sucesso.\n");
    // Liberando o espaço em memória alocado para os alunos
    for (int i = 0; i < 5; i++)
    {
        aluno_libera(alunos[i]);
    }
    return 0;
}
