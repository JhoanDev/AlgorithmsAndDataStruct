#include <stdio.h>

int main(void)
{
    int a, b, c, d; //declarando variaveis
    int *p1; // declarando um ponteiro
    int *p2 = &a; //declarando ponteiro p2 e apontando ele pra "a"
    int *p3 = &c; //declarando ponteiro p3 e apontando ele pra "c"
    p1 = p2; // apontando p1 para o mesmo que p2, no caso "a"
    *p2 = 10; // atualizando o valor de a para 10
    b = 20; // b recebe 20
    int **pp; // declarando um ponteiro de ponteiro
    pp = &p1; // o ponteiro de ponteiro esta apontando pra p1 que esta apontando pra "a"
    *p3 = **pp; // c recebe o valor de a ou seja 10
    int *p4 = &d; // declarando ponteiro p4 e apontando ele pra "d"
    *p4 = b + (*p1)++; // d recebe b + a, e depois é atualizado o valor de a com a=a+1
    //valores finais: a = 11, b=20, c=10, d=30.
    printf("%d\t%d\t%d\t%d\n", a, b, c, d);
    return 0;
}