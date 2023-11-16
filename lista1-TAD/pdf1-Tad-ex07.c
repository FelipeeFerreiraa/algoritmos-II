#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct esfera
{
    float r; // raio
} esfera;

esfera *criarCilindro();
int inserirMedidas(esfera *a);
void retornarRaio(esfera *a);
int areaEsfera(esfera *a);
int volumeEsfera(esfera *a);

int main()
{
    int opcao;
    esfera *c12;

    do
    {
        printf("Escolha uma opcao\n[0] Criar esfera\n[1] Inserir medidas\n[2] Retornar Raio do circulo\n[3] Retornar a area do esfera\n[4] Retornar volume da esfera\n[5] Sair\n");
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
            printf("Area do esfera eh %d!!\n", areaEsfera(c12));

            opcao = -1;
            break;

        case 4:
            printf("Volume do esfera eh %d!!\n", volumeEsfera(c12));
            opcao = -1;
            break;

        case 5:
            break;
        }
    } while (opcao < 0 || opcao > 5);

    return 0;
}

esfera *criarCilindro()
{
    esfera *c1;
    c1 = (esfera *)malloc(1 * sizeof(esfera));

    c1->r = 0;
    printf("esfera criado!!\n");

    return c1;
}

int inserirMedidas(esfera *a)
{
    if (a == NULL)
    {
        printf("Falha na alocacao!!!\n");
        return -1; // verificandoo se a alocacao deu certo
    }

    printf("Digite o raio da esfera: ");
    scanf("%f", &a->r);
    printf("Inserçao realizada\n");

    return 1;
}

void retornarRaio(esfera *a)
{
    printf("Raio da esfera: %.2f \n", (*a).r);
}

int areaEsfera(esfera *a)
{
    int area;
    area = 4 * 3.14 * pow(a->r, 2);

    return area;
}

int volumeEsfera(esfera *a)
{
    int volume;

    volume = (4 / 3) * 3.14 * pow(a->r, 3);

    return volume;
}