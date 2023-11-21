#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void intercala(int *a, int tam);

void mergeSort(int *a, int tam);

int main()
{
    srand(time(NULL));

    int vetoor[TAM];
    int x = 0;

    do
    {
        vetoor[x] = rand() % 50;
        /* para nao repetir numeros
        for (int y = 0; y < x; y++)
         {
             if (vetoor[x] == vetoor[y])
             {
                 x--;
             }
         }
        */

        x++;
    } while (x < TAM);

    printf("\n\nArray:\n");
    for (int x = 0; x < TAM; x++)
    {
        printf(" [%d], ", vetoor[x]);
    }

    mergeSort(vetoor, TAM);

    printf("\n\nArray Ordenado:\n");
    for (int x = 0; x < TAM; x++)
    {
        printf(" [%d], ", vetoor[x]);
    }

    return 0;
}

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