#include <stdio.h>

int main(void)
{
    int x, y, *p; //Declarando variaveis 
    y = 0; //y recebe 0
    p = &y; // p recebe endereco de y
    x = *p; // x recebe y
    x = 4; // x recebe 4
    (*p)++; // y + 1
    --x; // x - 1
    (*p) += x; // y = y + x
    // valores finais (*p) = 4, x = 3.
    // (*p) é a mesma coisa que y.
    printf("Y = %d\nX = %d",(*p),x);
}