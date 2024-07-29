#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linha, coluna, i, j, costa = 0;
    scanf("%d %d", &linha, &coluna);
    char **mat = (char **)malloc(linha * sizeof(char *));
    if (mat == NULL)
        exit(1);

    for (i = 0; i < linha; i++)
    {
        mat[i] = (char *)malloc(coluna * sizeof(char));
        if (mat[i] == NULL)
            exit(1);
    }

    for (i = 0; i < linha; i++)
        scanf(" %[^\n]", mat[i]);

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            if (mat[i][j] == '#')
            {
                if (i == 0 || j == 0 || (i == linha - 1 && j != 0) 
                || (j == coluna - 1 && (i != 0 && i != linha - 1)))
                {
                    costa++;
                }
                if (i != 0 && j!=0 && i != linha-1 && j!=coluna-1)
                {
                    if (mat[i+1][j] == '.' || mat[i-1][j] == '.' || mat[i][j+1] == '.' || mat[i][j-1] == '.')
                    {
                        costa++;
                    }
                }
            }
        }
    }
    printf("%d\n", costa);
    return 0;
}
