// TAD:Aluno

#include <stdio.h>  //funções basicas da linguagem c
#include <stdlib.h> //para fazer alocação dinamica
#include <string.h> //para usar strings
#include <math.h>   //operações algebricas
#include <time.h>   //Tempo de execução
#include <ctype.h>  //manipulação de caracteres

typedef struct aluno Aluno;

// cria um aluno
Aluno *aluno_cria(char *nome, float nota);

// libera um aluno
void aluno_libera(Aluno *a);

// imprime um aluno
void aluno_imprime(Aluno *a);

// ordena o vetor de ponteiros
void aluno_ordena(int n, Aluno **v);

// salva os dados dos alunos em um arquivo
void aluno_salva(FILE *fp, int n, Aluno **v);