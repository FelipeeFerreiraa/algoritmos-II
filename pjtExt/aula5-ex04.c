#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int num;
    do
    {
        printf("Digite um numero de 1 a 12: \n");
        scanf(" %d", &num);
        switch (num)
        {
        case 1:
            printf("Janeiro!!!\n");
            break;
        case 2:
            printf("Fevereiro!!!\n");
            break;

        case 3:
            printf("Marco!!!\n");
            break;

        case 4:
            printf("Abril!!!\n");
            break;

        case 5:
            printf("Maio!!!\n");
            break;

        case 6:
            printf("Junho!!!\n");
            break;

        case 7:
            printf("Julho!!!\n");
            break;

        case 8:
            printf("Agosto!!!\n");
            break;

        case 9:
            printf("Setembro!!!\n");
            break;

        case 10:
            printf("Outubro!!!\n");
            break;

        case 11:
            printf("Novembro!!!\n");
            break;

        case 12:
            printf("Dezembro!!!\n");
            break;

        default:
            printf("\nAlgo de errado nao esta certo! - Digite outro numero!!\n\n");
            break;
        }
    } while (num < 1 || num > 12);

    return 0;
}