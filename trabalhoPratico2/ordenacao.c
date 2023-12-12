#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct aluno
{
    int matricula, periodoAtual;
    char nome[20], cursoMat[30];
    float coefRend;
} aluno;

//----------selectSort()
void selectionSort(int *a, int tam);

//----------insertSort()
void insertionSort(int *a, int tam);

//----------quickSort()
void particionar(int esq, int dir, int *x, int *y, int *a);
void ordenar(int esq, int dir, int *a);
void quickSort(int *a, int n);

//----------mergeSort()
void intercala(int *a, int tam);
void mergeSort(int *a, int tam);

int main()
{
    return 0;
}

//----------selectSort()
void selectionSort(int *a, int tam)
{
    int x, y, menor;
    int aux;

    for (x = 0; x < tam - 1; x++)
    {
        menor = x;
        for (y = x + 1; y < tam; y++)
        {
            if (a[y] < a[menor])
            {
                menor = y;
            }
        }
        aux = a[menor];
        a[menor] = a[x];
        a[x] = aux;
    }
}

//----------insertSort()
void insertionSort(int *a, int tam)
{
    int x, y;
    int aux;

    for (x = 1; x < tam; x++)
    {
        aux = a[x];
        y = x - 1;
        while (aux < a[y] && y >= 0)
        {
            a[y + 1] = a[y];
            y--;
        }
        a[y + 1] = aux;
    }
}

//----------quickSort()
void particionar(int esq, int dir, int *x, int *y, int *a)
{
    int i, aux;
    *x = esq;
    *y = dir;
    i = a[(*x + *y) / 2]; // pivooooo

    do
    {
        while (i > a[*x])
        {
            ++(*x);
        }

        while (i < a[*y])
        {
            --(*y);
        }

        if (*x <= *y)
        {
            aux = a[*x];
            a[*x] = a[*y];
            a[*y] = aux;
            (*x)++;
            (*y)--;
        }

    } while (*x <= *y);
}

void ordenar(int esq, int dir, int *a)
{
    int x, y;
    particionar(esq, dir, &x, &y, a);
    if (esq < y)
        ordenar(esq, y, a);
    if (x < dir)
        ordenar(x, dir, a);
}

void quickSort(int *a, int n)
{
    ordenar(0, n - 1, a);
}

//----------mergeSort()
void intercala(int *a, int tam)
{
    int *aux = (int *)malloc(tam * sizeof(int));
    int meio = tam / 2;

    int x = 0, y = meio, z = 0;

    while (x < meio && y < tam)
    {
        if (a[x] < a[y])
        {
            aux[z] = a[x];
            x++;
        }
        else
        {
            aux[z] = a[y];
            y++;
        }
        z++;
    }

    if (x == meio)
    {
        while (y < tam)
        {
            aux[z] = a[y];
            y++;
            z++;
        }
    }
    else
    {
        while (x < meio)
        {
            aux[z] = a[x];
            x++;
            z++;
        }
    }

    for (x = 0; x < tam; x++)
    {
        a[x] = aux[x];
    }
    free(aux);
}

void mergeSort(int *a, int tam)
{
    int meio;
    if (tam > 1)
    {
        meio = tam / 2;
        mergeSort(a, meio);
        mergeSort(a + meio, tam - meio);
        intercala(a, tam);
    }
}