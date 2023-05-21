#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contabancaria.h"

struct contabancaria
{
    char titular[50];
    int numero;
    float saldo;
};

ContaBancaria *criaconta(char titular[], int numero, float saldo)
{
    ContaBancaria *cliente = (ContaBancaria *)malloc(sizeof(ContaBancaria));
    if (cliente == NULL)
    {
        printf("Erro de alocacao");
        exit(1);
    }

    strcpy(cliente->titular, titular);
    cliente->saldo = saldo;
    cliente->numero = numero;
    return cliente;
}

void deposita(ContaBancaria *cliente, float valor)
{
    if (cliente != NULL)
    {
        cliente->saldo += valor;
        printf("%s seu saldo atual agora é %.2f!\n", cliente->titular, cliente->saldo);
    }
    else
    {
        printf("Cliente inexistente!");
    }
}

void transfere(ContaBancaria *cliente, ContaBancaria *receptor, float valor)
{
    if (cliente != NULL)
    {
        if (cliente->saldo >= valor)
        {
            cliente->saldo -= valor;
            receptor->saldo += valor;
        }
        else
        {
            printf("Saldo insuficiente\n");
        }
    }
    else
    {
        printf("Cliente inexistente!\n");
    }
}

float saldo(ContaBancaria *cliente)
{
    if (cliente != NULL)
    {
        return cliente->saldo;
    }
    else
    {
        printf("Cliente inexistente!\n");
    }
}

void excluiconta(ContaBancaria *cliente)
{
    if (cliente != NULL)
    {
        free(cliente);
        printf("Cliente excluido com sucesso!\n");
    }
    else
    {
        printf("Cliente inexistente!\n");
    }
}