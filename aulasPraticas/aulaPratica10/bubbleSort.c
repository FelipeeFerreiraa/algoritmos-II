#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 20

void bubbleSort(int *a, int tam);

int main()
{
    srand(time(NULL));

    int vetoor[TAM];
    int x = 0;

    do
    {
        vetoor[x] = rand() % 50;
        for (int y = 0; y < x; y++)
        {
            if (vetoor[x] == vetoor[y])
            {
                x--;
            }
        }

        x++;
    } while (x < TAM);

    printf("\n\nArray:\n");
    for (int x = 0; x < TAM; x++)
    {
        printf(" [%d], ", vetoor[x]);
    }

    bubbleSort(vetoor, TAM);

    printf("\n\nArray Ordenado:\n");
    for (int x = 0; x < TAM; x++)
    {
        printf(" [%d], ", vetoor[x]);
    }

    return 0;
}

void bubbleSort(int *a, int tam)
{
    int x, y;
    int aux;

    for (x = 0; x < tam; x++)
    {
        for (y = 1; y < tam - 1; y++)
        {
            if (a[y] < a[y - 1])
            {
                aux = a[y];
                a[y] = a[y - 1];
                a[y - 1] = aux;
            }
        }
    }
}
