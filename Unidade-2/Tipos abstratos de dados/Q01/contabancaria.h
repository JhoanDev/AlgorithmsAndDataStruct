// TAD: conta bancaria
typedef struct contabancaria ContaBancaria;

// cria a conta para o cliente
ContaBancaria *criaconta(char titular[], int numero, float saldo);

// deposita na conta do cliente
void deposita(ContaBancaria *cliente, float valor);

// tranfere dinheiro da conta do cliente para outra pessoa
void transfere(ContaBancaria *cliente, ContaBancaria *receptor, float valor);

// retorna o saldo de um cliente especifico
float saldo(ContaBancaria *cliente);

// libera o espaço reservado para o cliente na memoria
void excluiconta(ContaBancaria *cliente);