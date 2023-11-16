#include <stdio.h>
#include <string.h>
#include <math.h>

void recebeNum(float *a, float *b);

int main()
{
    int idade;

    printf("Digite sua idade: \n");
    scanf(" %d", &idade);

    if (idade >= 5 && idade <= 7)
    {
        printf("\nCategoria Infantil A\n");
    }
    else if (idade >= 8 && idade <= 10)
    {
        printf("\nCategoria Infantil B\n");
    }
    else if (idade >= 11 && idade <= 13)
    {
        printf("\nCategoria Juvenil A\n");
    }
    else if (idade >= 14 && idade <= 17)
    {
        printf("\nCategoria Juvenil B\n");
    }
    else if (idade >= 18 && idade <= 100)
    {
        printf("\nCategoria Senior!!!\n");
    }
    else
    {
        printf("\nIdade Insuficiente!!!\n");
    }

    return 0;
}
