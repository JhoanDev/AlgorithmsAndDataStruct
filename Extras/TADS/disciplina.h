#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TAD: Disciplina
typedef struct disciplina Disciplina;

//Cria a disciplina
Disciplina* cria_disciplina(char nome[], int codigo);

//exclui uma disciplina
void exclui_disciplina(Disciplina* disciplina);