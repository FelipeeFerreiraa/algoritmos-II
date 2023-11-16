#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct cilindro
{
    float r, h; // raio,altura
} cilindro;

cilindro *criarCilindro();
int inserirMedidas(cilindro *a);
void retornarRaio(cilindro *a);
void retornarY(cilindro *a);
int areaCilindro(cilindro *a);
int volumeCilindro(cilindro *a);

int main()
{
    int opcao;
    cilindro *c12;

    do
    {
        printf("Escolha uma opcao\n[0] Criar cilindro\n[1] Inserir medidas\n[2] Retornar Raio do circulo\n[3] Retornar Y\n[4] Retornar a area do cilindro\n[5] Retornar volume do cubo\n[6] Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            c12 = criarCilindro();
            opcao = -1;
            break;

        case 1:
            inserirMedidas(c12);
            opcao = -1;
            break;

        case 2:
            retornarRaio(c12);
            opcao = -1;
            break;

        case 3:
            retornarY(c12);
            opcao = -1;
            break;

        case 4:
            printf("Area do cilindro eh %d!!\n", areaCilindro(c12));

            opcao = -1;
            break;

        case 5:
            printf("Volume do cilindro eh %d!!\n", volumeCilindro(c12));
            opcao = -1;
            break;

        case 6:
            break;
        }
    } while (opcao < 0 || opcao > 6);

    return 0;
}

cilindro *criarCilindro()
{
    cilindro *c1;
    c1 = (cilindro *)malloc(1 * sizeof(cilindro));

    c1->r = 0;
    (*c1).h = 0;
    printf("cilindro criado!!\n");

    return c1;
}

int inserirMedidas(cilindro *a)
{
    if (a == NULL)
    {
        printf("Falha na alocacao!!!\n");
        return -1; // verificandoo se a alocacao deu certo
    }

    printf("Digite o raio do circulo do cilindro: ");
    scanf("%f", &a->r);
    printf("Digite a altura (y) do cilindro: ");
    scanf("%f", &a->h);
    printf("Inserçao realizada\n");

    return 1;
}

void retornarRaio(cilindro *a)
{
    printf("Raio do circulo do cilindro: %.2f \n", (*a).r);
}

void retornarY(cilindro *a)
{
    printf("Altura do cilindro: %.2f (eixo y)\n", (*a).h);
}

int areaCilindro(cilindro *a)
{
    int area;
    area = 2 * 3.14 * a->r * (a->r + a->h);

    return area;
}

int volumeCilindro(cilindro *a)
{
    int volume;

    volume = 3.14 * a->h * pow(a->r, 3);

    return volume;
}