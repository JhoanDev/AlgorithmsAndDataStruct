#include "contabancaria.c"

int main()
{
    // Criando uma conta bancária
    ContaBancaria *conta1 = criaconta("João Silva", 1, 1000.0);
    printf("Conta criada: Titular: %s, Numero: %d, Saldo: %.2f\n", conta1->titular, conta1->numero, conta1->saldo);
    // Realizando um depósito
    deposita(conta1, 500.0);
    // Criando uma segunda conta bancária
    ContaBancaria *conta2 = criaconta("Maria Souza", 2, 2000.0);
    printf("Conta criada: Titular: %s, Numero: %d, Saldo: %.2f\n", conta2->titular, conta2->numero, conta2->saldo);
    // Realizando uma transferência entre contas
    transfere(conta1, conta2, 300.0);
    // Verificando o saldo das contas
    printf("Saldo da conta 1: %.2f\n", saldo(conta1));
    printf("Saldo da conta 2: %.2f\n", saldo(conta2));
    // Excluindo uma conta
    excluiconta(conta1);
    return 0;
}
