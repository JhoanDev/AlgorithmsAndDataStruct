#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define pi 3.14

typedef struct retangulo
{
    float b; // base
    float h; // altura
    char tipo[4];
} Retangulo;

typedef struct triangulo
{
    float b; // base
    float h; // altura
    char tipo[4];
} Triangulo;

typedef struct circulo
{
    float r; // raio
    char tipo[5];
} Circulo;

typedef union het
{
    Retangulo *ret;
    Triangulo *tri;
    Circulo *circ;
} Het;

typedef struct listahet
{
    Het *het; // formas geometricas
    struct listahet *prox;
} ListaHet;

ListaHet *cria_ret(ListaHet *he, float b, float h)
{
    ListaHet *novo = (ListaHet *)malloc(sizeof(ListaHet));
    if (novo == NULL)
    {
        printf("[ERRO] memoria insuficiente!");
        exit(1);
    }
    novo->het = (Het *)malloc(sizeof(Het));
    novo->het->ret = (Retangulo *)malloc(sizeof(Retangulo));
    novo->prox = he;
    novo->het->ret->b = b;
    novo->het->ret->h = h;
    strcpy(novo->het->ret->tipo, "ret");
    return novo;
}

ListaHet *cria_tri(ListaHet *he, float b, float h)
{
    ListaHet *novo = (ListaHet *)malloc(sizeof(ListaHet));
    if (novo == NULL)
    {
        printf("[ERRO] memoria insuficiente!");
        exit(1);
    }
    novo->het = (Het *)malloc(sizeof(Het));
    novo->het->tri = (Triangulo *)malloc(sizeof(Triangulo));
    novo->prox = he;
    novo->het->tri->b = b;
    novo->het->tri->h = h;
    strcpy(novo->het->tri->tipo, "tri");
    return novo;
}

ListaHet *cria_circ(ListaHet *he, float r)
{
    ListaHet *novo = (ListaHet *)malloc(sizeof(ListaHet));
    if (novo == NULL)
    {
        printf("[ERRO] memoria insuficiente!");
        exit(1);
    }
    novo->het = (Het *)malloc(sizeof(Het));
    novo->het->circ = (Circulo *)malloc(sizeof(Circulo));
    novo->prox = he;
    novo->het->circ->r = r;
    strcpy(novo->het->circ->tipo, "circ");
    return novo;
}

static float ret_area(Retangulo *r)
{
    float area;
    area = r->b * r->h;
    return area;
}

static float tri_area(Triangulo *t)
{
    float area;
    area = (t->b * t->h) / 2;
    return area;
}
static float circ_area(Circulo *c)
{
    float area;
    area = pow(c->r, 2) * pi;
    return area;
}

float max_area(ListaHet *f)
{
    ListaHet *h;
    float area = 0.0, aream = 0.0;
    for (h = f; h != NULL; h = h->prox)
    {
        if (strcmp(h->het->ret->tipo, "ret") == 0)
        {
            area = ret_area(h->het->ret);
        }
        else if (strcmp(h->het->tri->tipo, "tri") == 0)
        {
            area = tri_area(h->het->tri);
        }
        else if (strcmp(h->het->circ->tipo, "circ") == 0)
        {
            area = circ_area(h->het->circ);
        }
        else
        {
            printf("[ERRO]");
            exit(1);
        }
        if (area > aream)
        {
            aream = area;
        }
    }
    return aream;
}

void libera_lista(ListaHet *he)
{
    ListaHet *atual = he;
    while (atual != NULL)
    {
        if (atual->het->ret != NULL)
        {
            free(atual->het->ret);
        }
        else if (atual->het->tri != NULL)
        {
            free(atual->het->tri);
        }
        else if (atual->het->circ != NULL)
        {
            free(atual->het->circ);
        }
        else
        {
            printf("[ERRO]");
            exit(1);
        }
        ListaHet *prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

int main(void)
{
    ListaHet *listaformas = NULL;
    // Criando algumas formas geométricas
    listaformas = cria_ret(listaformas, 2.0, 6.0);
    listaformas = cria_tri(listaformas, 5.0, 2.0);
    listaformas = cria_circ(listaformas, 2.0);
    // Calculando a maior área
    float maior_area = max_area(listaformas);
    printf("Maior area: %.2f\n", maior_area);
    libera_lista(listaformas);
    return 0;
}