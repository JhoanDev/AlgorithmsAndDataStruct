#include <stdio.h>
#include <stdlib.h>

int main(void){
    //declarando variaveis
    int linhas, colunas, i, j, costa = 0;
    printf("Insira a quantidade de linhas: ");
    scanf("%d",&linhas);
    printf("Insira a quantidade de colunas: ");
    scanf("%d",&colunas);
    //alocando memoria dinamicamente
    char **territorio = (char**) malloc(linhas * sizeof(char*));
    if (territorio == NULL)
    {
        printf("ERRO");
        exit(1);
    }
    for (i = 0; i < linhas; i++)
    {
        territorio[i] = (char*) malloc(colunas * sizeof(char));
    }
    for (i = 0; i < linhas; i++)
    {
        scanf(" %s", territorio[i]);
    }
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            //verificando se é costa
            if (territorio[i][j] == '#' && ((i == 0 || territorio[i-1][j] == '.') || (i == linhas-1 || territorio[i+1][j] == '.') || (j == 0 || territorio[i][j-1] == '.') || (j == colunas-1 || territorio[i][j+1] == '.'))) {
                costa++;
            }
        }
    }
    for (i = 0; i < linhas; i++) {
        free(territorio[i]);//liberando memoria
    }
    free(territorio);
    printf("%d\n", costa);
    return 0;
}
