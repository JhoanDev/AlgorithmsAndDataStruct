#include <stdio.h>
#include <stdlib.h>

int main (void){
    int *vetor = (int *) malloc(10 * sizeof(int));
    int i;
    if (vetor == NULL)
    {
        printf("Erro ao alocar memoria");
        exit(1);
    }
    for (i = 0; i < 10; i++)
    {
        vetor[i] = i;
    }
    printf("vetor: ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", vetor[i]);
    }
    free(vetor);
    for (i = 0; i < 10; i++)
    {
        printf("%d ", vetor[i]);
    }
    return 0;
}