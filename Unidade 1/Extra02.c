/* Crie um tipo estruturado para representar uma conta bancária, cujos campos são: o nome do cliente, 
o número da conta e um saldo. Crie uma variável do tipo estrutura e escreva instruções para inicializar seus campos. 
Em seguida, implemente uma função para realizar um depósito em uma estrutura do tipo struct contaBancaria.
Sua função deve obedecer ao seguinte protótipo: void deposita(float valor, struct contaBancaria* conta); */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ContaBancaria //criando a struct
{
    char nome[20];
    int conta;
    float saldo;
}ContaBancaria;

void deposita(float valor, ContaBancaria *user){
    user->saldo += valor;
}

int main (void){
    ContaBancaria *user = (ContaBancaria*) malloc(sizeof(ContaBancaria));
    if (user == NULL)
    {
        printf("Erro na alocacao de memoria!\n");
        return 1;
    }
    strcpy(user->nome, "Jhoan");
    user->conta = 1;
    user->saldo = 100.25;
    printf("Seu saldo atual: %.2f\nQuanto deseja depositar? ",user->saldo);
    float valor;
    scanf("%f",&valor);
    deposita(valor, user); //chamando a função
    printf("\nConta atualizada: %s \nNumero da conta: %d \nSaldo atual: %.2f",user->nome,user->conta,user->saldo); //exibindo o resultado
    free(user);
    return 0;
}
