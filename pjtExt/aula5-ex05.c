#include <stdio.h>
#include <string.h>
#include <math.h>

void recebeNum(float *a, float *b);

int main()
{
    int escolha;
    float num1, num2;
    do
    {
        printf("Escolha:\n[1] Soma de dois numeros.\n[2] Diferenca entre dois numeros.\n[3] Produto entre dois numeros.\n[4] Divisao entre dois numeros.\n");
        scanf(" %d", &escolha);
        switch (escolha)
        {
        case 1:
            recebeNum(&num1, &num2);
            printf("A soma dos numeros fornecidos eh: [%.2f]\n", num1 + num2);
            break;
        case 2:
            recebeNum(&num1, &num2);
            if (num1 > num2)
            {
                printf("A diferenca dos numeros fornecidos eh: [%.2f]", num1 - num2);
            }
            else
            {
                printf("A diferenca dos numeros fornecidos eh: [%.2f]", num2 - num1);
            }

            break;

        case 3:
            recebeNum(&num1, &num2);
            printf("O produto dos numeros fornecidos eh: [%.2f]\n", num1 * num2);
            break;

        case 4:
            recebeNum(&num1, &num2);
            if (num2 != 0)
            {
                printf("A divisao dos numeros fornecidos eh: [%.2f]", num1 / num2);
            }
            else
            {
                printf("Denominador iinvalido! \n");
                escolha = -1;
            }
            break;

        default:
            printf("\nAlgo de errado nao esta certo! - Digite outro numero!!\n\n");
            break;
        }
    } while (escolha < 1 || escolha > 4);

    return 0;
}

void recebeNum(float *a, float *b)
{
    printf("Digite o primeiro  numero: \n");
    scanf("%f", a);
    printf("Digite o segundo numero: \n");
    scanf("%f", b);
}
