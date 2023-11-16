#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int num;
    printf("Digite um numero: \n");
    scanf("%d", &num);

    if (num > 0)
    {
        printf("Numero fornecido ao quadrado: [%.f] \n", pow(num, 2));
    }
    else
    {
        printf("Numero fornecido: [%d]", num);
    }
    return 0;
}