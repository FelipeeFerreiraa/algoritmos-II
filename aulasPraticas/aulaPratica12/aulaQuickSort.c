#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10

void particionar(int esq, int dir, int *x, int *y, int *a);

void ordenar(int esq, int dir, int *a);

void quickSort(int *a, int n);

int main()
{

    srand(time NULL);

    int vetoooor[MAX];

    for (int x = 0; x < MAX; x++)
    {
        vetoooor[x] = rand() % 50 + 1;
        /*
            for(int y =0; y<x; y++)
            {
              if(vetoooor[x] == vetoooor[y])
              {
                x--;
              }
            }
        */
    }

    printf("Vetor: \n");
    for (int x = 0; x < MAX; x++)
    {
        printf("%d, ", vetoooor[x]);
    }

    quickSort(vetoooor, MAX);

    printf("\n\nVetor Ordenado: \n");
    for (int x = 0; x < MAX; x++)
    {
        printf("%d, ", vetoooor[x]);
    }

    return 0;
}

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