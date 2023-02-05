#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int entrevistados, i;
    float m = 0, f = 0, mg = 0, fg = 0, pf = 0, pm = 0;
    printf("Insira o numero de entrevistados: ");
    scanf("%d", &entrevistados);
    char *sexo = (char *)malloc(entrevistados * sizeof(char));
    char **opiniao = (char **)malloc(entrevistados * sizeof(char *));
    for (i = 0; i < entrevistados; i++)
    {
        opiniao[i] = (char *)malloc(14 * sizeof(char));
    }
    if (opiniao == NULL || sexo == NULL)
    {
        printf("ERRO");
        exit(1);
    }

    for (i = 0; i < entrevistados; i++)
    {
        printf("\nInsira seu sexo (F ou M): ");
        scanf(" %c", &sexo[i]);
        printf("\nInsira sua opiniao (gostei ou nao gostei):");
        scanf(" %[^\n]", opiniao[i]);
    }
    for (i = 0; i < entrevistados; i++)
    {
        if (sexo[i] == 'f' || sexo[i] == 'F')
        {
            f++;
            if (strcmp(opiniao[i], "gostei") == 0)
            {
                fg++;
            }
        }
        else
        {
            m++;
            if (strcmp(opiniao[i], "gostei") == 0)
            {
                mg++;
            }
        }
    }
    if (m == 0)
    {
        pm = mg/1*100;
    }
    else if (f == 0)
    {
        pf = fg/1*100;
    }
    else{
        pm = (mg/m)*100;
        pf = (fg/f)*100;
    }
    printf("\n-------------------------------------------------------------------");
    printf("\nPublico masculino total: %.0f \n %.2f %% gostaram do produto.", m, pm);
    printf("\n-------------------------------------------------------------------");
    printf("\nPublico feminino total: %.0f \n %.2f %% gostaram do produto.", f, pf);
    printf("\n-------------------------------------------------------------------");
    return 0;
}
