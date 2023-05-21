#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *entrada = fopen("entrada_q2.txt", "r");
    FILE *saida = fopen("saida_q2.txt", "w");
    if (entrada == NULL || saida == NULL)
    {
        printf("erro");
        exit(1);
    }
    char linha[100];
    float media = 0.0;
    int maior = NULL, menor = NULL, i = 0, vet[10];
    while (fgets(linha, 100, entrada) != NULL)
    {
        sscanf(linha, "%d", &vet[i]);
        if (maior <= vet[i] || maior == NULL)
            maior = vet[i];
        if (menor >= vet[i] || menor == NULL)
            menor = vet[i];
        media += vet[i];
        i++;
    }
    media = media / 10;
    fprintf(saida, "menor elemento: %d\n", menor);
    fprintf(saida, "maior elemento: %d\n", maior);
    fprintf(saida, "media dos elementos: %f", media);
    fclose(entrada);
    fclose(saida);
    return 0;
}