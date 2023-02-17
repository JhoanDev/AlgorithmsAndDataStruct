/* 
int main(void)
{
    int x, *p;
    x = 100;
    p = x;
    printf("Valor de p = % p\tValor de *p = % d", p, *p);
}

Se tentarmos compilar o programa (não o compile ainda), você acha que o compilador nos
fornece alguma mensagem? Se sim, responda:
a) Esta mensagem é de erro ou advertência? advertencia
b) Por que o compilador emite tal mensagem? por que um ponteiro ta recebendo o valor de x e nao o endereço, o que faz com que ele aponte pra o espaço 100 da memoria que provavelmente ta vazio.
c) Compile e execute o programa. A execução foi bem sucedida? sim porem sem exibição
d) Modifique o trecho de código acima, de modo que nenhuma mensagem seja emitida 
pelo compilador.
e) Compile e execute novamente o programa. A execução foi bem sucedida? Sim
*/

#include <stdio.h>

int main(void)
{
    int x, *p;
    x = 100;
    p = &x; //adicionei um & para apontar para x. 
    printf("Valor de p = %p\tValor de *p = %d", p, *p);
}
