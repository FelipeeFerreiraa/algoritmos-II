#include <stdio.h>

int main()
{
    int num1, num2;
    printf("Digite um numero: \n");
    scanf("%d", &num1);
    printf("Digite outro numero: \n");
    scanf("%d", &num2);

    if (num1 > num2)
    {
        printf("Maior numero fornecido: [%d]\n", num1);
    }
    else
    {
        printf("Maior numero fornecido: [%d]\n", num2);
    }
    return 0;
}