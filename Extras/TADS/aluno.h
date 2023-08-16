#include "disciplina.h"
//TAD: Aluno

typedef struct aluno Aluno;

//cria um aluno
Aluno* cria_aluno(char nome[], int matricula);

//Matricula disciplina num aluno
void matricula_disciplina(Aluno* aluno, Disciplina* disciplina);

//Exclui um aluno
void exclui_aluno(Aluno* aluno);