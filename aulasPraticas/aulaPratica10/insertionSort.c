#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 20

void insertionSort(int *a, int tam);

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

    insertionSort(vetoor, TAM);

    printf("\n\nArray Ordenado:\n");
    for (int x = 0; x < TAM; x++)
    {
        printf(" [%d], ", vetoor[x]);
    }

    return 0;
}

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
