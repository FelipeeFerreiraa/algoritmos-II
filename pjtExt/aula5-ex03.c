#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    float altura;
    char sexo;
    printf("Informe seu sexo: M (masculino) ou F (feminino): \n");
    scanf(" %c", &sexo);

    printf("Agora informe sua Altura: \n");
    scanf("%f", &altura);

    if (sexo == 'M')
    {
        printf("Seu peso ideal eh: [%.2f] \n", (72.7 * altura) - 58);
    }
    else
    {
        printf("Seu peso ideal eh: [%.2f]", (62.1 * altura) - 44.7);
    }
    return 0;
}