#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario
{
    char depto; /* departamento */
    int mat;    /* matrícula */
    char nome[81];
    float salario;
} Funcionario;

typedef struct listaFunc
{
    Funcionario *funcionario;
    struct listaFunc *prox;
} ListaFunc;

// criar nova lista
ListaFunc *listfunc_cria()
{
    return NULL;
}

// inserindo no inicio
ListaFunc *listfunc_adc(ListaFunc *l, Funcionario *f)
{
    ListaFunc *novo = (ListaFunc *)malloc(sizeof(ListaFunc));
    if (novo == NULL)
    {
        printf("[ERRO] memoria insuficiente!");
        exit(1);
    }
    novo->funcionario = (Funcionario *)malloc(sizeof(Funcionario));
    if (novo->funcionario == NULL)
    {
        printf("[ERRO] memoria insuficiente!");
        exit(1);
    }
    novo->prox = l;
    memcpy(novo->funcionario, f, sizeof(Funcionario)); // para adicionar cada campo do funcionario sem necessitar ser um por um
    return novo;
}

// imprimir a informação
void listfunc_imprime(ListaFunc *f)
{
    ListaFunc *p;
    for (p = f; p != NULL; p = p->prox)
    {
        printf("Departamento: %c\n", p->funcionario->depto);
        printf("Matricula: %d\n", p->funcionario->mat);
        printf("Nome: %s\n", p->funcionario->nome);
        printf("Salario: %.2f\n", p->funcionario->salario);
        printf("========================\n");
    }
}

// calculando o total
float lstfunc_folha_pagto(ListaFunc *f, char depto)
{
    ListaFunc *p;
    float total = 0.0;
    for (p = f; p != NULL; p = p->prox)
    {
        if (p->funcionario->depto == depto)
        {
            total += p->funcionario->salario;
        }
    }
    if (total == 0)
    {
        printf("Departamento inexistente!");
        exit(1);
    }
    else
    {
        return total;
    }
}

void listfunc_libera(ListaFunc *f)
{
    ListaFunc *p = f;
    while (p != NULL)
    {
        ListaFunc *t = p->prox;
        free(p->funcionario);
        free(p);
        p = t;
    }
}

int main(void)
{
    char dptm;
    float fs;
    ListaFunc *listaf = listfunc_cria();
    Funcionario func;
    for (int i = 0; i < 5; i++)
    { // adicionando 2 funcionarios
        printf("Insira o departamento: ");
        scanf(" %c", &func.depto);
        printf("Insira a matricula: ");
        scanf(" %d", &func.mat);
        printf("Insira o nome: ");
        scanf(" %[^\n]s", func.nome);
        printf("Insira o salario: ");
        scanf(" %f", &func.salario);
        listaf = listfunc_adc(listaf, &func);
        system("cls");
    }
    listfunc_imprime(listaf);
    printf("\nInsira o departamento que deseja olhar a folha salarial: ");
    scanf(" %c", &dptm);
    fs = lstfunc_folha_pagto(listaf, dptm);
    printf("\nO total do departamento %c e de: %.2f$", dptm, fs);
    listfunc_libera(listaf);
    return 0;
}