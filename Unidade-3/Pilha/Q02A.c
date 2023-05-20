#include "pilhav.c"

float topo(Pilha *p)
{
    if (pilha_vazia(p) == 1)
    { // verifica se a pilha está vazia
        printf("Erro: pilha vazia.\n");
        exit(1); // termina o programa em caso de erro
    }
    float valor = pilha_pop(p); // armazena o valor do topo da pilha em uma variável temporária
    pilha_push(p, valor);       // restaura o conteúdo da pilha
    return valor;               // retorna o valor armazenado na variável temporária
}

int main(void)
{
    Pilha *p = pilha_cria(); // cria uma nova pilha
    pilha_push(p, 3.1);      // insere alguns valores na pilha
    pilha_push(p, 2.7);
    pilha_push(p, 1.6);
    float valor_topo = topo(p);                             // obtém o valor do topo da pilha
    printf("Valor do topo da pilha: %.1f\n\n", valor_topo); // imprime o valor do topo da pilha
    pilha_imprime(p);
    pilha_libera(p); // libera a memória alocada pela pilha
    return 0;
}
