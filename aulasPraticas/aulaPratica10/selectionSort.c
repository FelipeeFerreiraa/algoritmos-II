#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 20

void selectionSort(int *a, int tam);

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

    selectionSort(vetoor, TAM);

    printf("\n\nArray Ordenado:\n");
    for (int x = 0; x < TAM; x++)
    {
        printf(" [%d], ", vetoor[x]);
    }

    return 0;
}

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
