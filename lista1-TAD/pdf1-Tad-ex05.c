#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cubo
{
    int x, y, z; // largura,altura,profundidade
} cubo;

cubo *criarCubo();
int inserirMedidas(cubo *a);
void retornarX(cubo *a);
void retornarY(cubo *a);
void retornarZ(cubo *a);
int areaCubo(cubo *a);
int volumeCubo(cubo *a);

int main()
{
    int opcao;
    cubo *c12;

    do
    {
        printf("Escolha uma opcao\n[0] Criar cubo\n[1] Inserir medidas\n[2] Retornar X\n[3] Retornar Y\n[4] Retornar Z\n[5] Retornar a area do cubo\n[6] Retornar volume do cubo\n[7] Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            c12 = criarCubo();
            opcao = -1;
            break;

        case 1:
            inserirMedidas(c12);
            opcao = -1;
            break;

        case 2:
            retornarX(c12);
            opcao = -1;
            break;

        case 3:
            retornarY(c12);
            opcao = -1;
            break;

        case 4:
            retornarZ(c12);
            opcao = -1;
            break;

        case 5:
            printf("Area do cubo eh %d!!\n", areaCubo(c12));

            opcao = -1;
            break;

        case 6:
            printf("Volume do cubo eh %d!!\n", volumeCubo(c12));
            opcao = -1;
            break;

        case 7:
            break;
        }
    } while (opcao < 0 || opcao > 7);

    return 0;
}

cubo *criarCubo()
{
    cubo *c1;
    c1 = (cubo *)malloc(1 * sizeof(cubo));

    c1->x = 0;
    (*c1).y = 0;
    c1->z = 0;
    printf("Cubo criado!!\n");

    return c1;
}

int inserirMedidas(cubo *a)
{
    if (a == NULL)
    {
        printf("Falha na alocacao!!!\n");
        return -1; // verificandoo se a alocacao deu certo
    }

    printf("Digite a largura (x) do cubo: ");
    scanf("%d", &a->x);
    printf("Digite a altura (y) do cubo: ");
    scanf("%d", &a->y);
    printf("Digite a profundidade (z) do cubo: ");
    scanf("%d", &a->z);

    printf("Inserçao realizada\n");

    return 1;
}

void retornarX(cubo *a)
{
    printf("Largura do cubo: %d (eixo x)\n", (*a).x);
}

void retornarY(cubo *a)
{
    printf("Altura do cubo: %d (eixo y)\n", (*a).y);
}

void retornarZ(cubo *a)
{
    printf("Profundidade do cubo: %d (eixo z)\n", (*a).z);
}

int areaCubo(cubo *a)
{
    int area;
    area = (2 * ((*a).y * (*a).z)) + (2 * ((*a).y * (*a).x)) + (2 * ((*a).z * (*a).x));

    return area;
}

int volumeCubo(cubo *a)
{
    int volume;

    volume = (*a).x * (*a).y * (*a).z;

    return volume;
}