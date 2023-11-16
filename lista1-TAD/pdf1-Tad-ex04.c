#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// soma de conjuntos esta com algum problemaaaa somando numeros iguais
#define MAX 100

typedef struct conjRacionais
{
    float vetor[MAX];
    int tam;
} conjRacionais;

conjRacionais *criarRacional();
conjRacionais somarRacionais(conjRacionais *a, conjRacionais *b);
conjRacionais multpRacionais(int num, conjRacionais *a);
int testarIgualdade(conjRacionais *a, conjRacionais *b);
void imprimirConj(conjRacionais *a);
void inserirElementos(conjRacionais *a);

int main()
{
    int opcao, num;
    conjRacionais *conj1, *conj2, conjSomado;
    do
    {
        printf("Escolha uma opcao: \n[0] Criar conjunto racional\n[1] Somar dois conjuntos racionais\n[2] Multiplicar conjunto por um escalar\n[3] Verificar se sao iguais\n[4] Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("---------criando conjunto-1-----------\n");
            conj1 = criarRacional();
            inserirElementos(conj1);
            printf("---------criando conjunto-2-----------\n");
            conj2 = criarRacional();
            inserirElementos(conj2);
            opcao = -1;
            break;

        case 1:
            conjSomado = somarRacionais(conj1, conj2);
            imprimirConj(&conjSomado);
            opcao = -1;
            break;

        case 2:
            printf("Digite um escalar: \n");
            scanf("%d", &num);
            multpRacionais(num, conj1);
            imprimirConj(conj1);
            opcao = -1;
            break;

        case 3:
            if (testarIgualdade(conj1, conj2) == 1)
            {
                printf("Conjuntos Iguais!!!\n");
            }
            else
            {
                printf("Conjuntos difeerentes!!!\n");
            }
            opcao = -1;
            break;

        case 4:
            break;
        }
    } while (opcao < 0 || opcao >= 5);

    return 0;
}

conjRacionais *criarRacional()
{
    conjRacionais *a;

    a = (conjRacionais *)malloc(MAX * sizeof(conjRacionais));
    (*a).tam = 0;

    return a;
}

conjRacionais somarRacionais(conjRacionais *a, conjRacionais *b)
{
    conjRacionais soma;
    soma.tam = a->tam + b->tam;
    for (int x = 0; x < a->tam; x++)
    {
        soma.vetor[x] = a->vetor[x];
    }

    for (int y = 0; y < (*b).tam; y++)
    {
        soma.vetor[a->tam + y] = b->vetor[y];
    }

    return soma;
}

conjRacionais multpRacionais(int num, conjRacionais *a)
{
    for (int x = 0; x < (*a).tam; x++)
    {
        (*a).vetor[x] = a->vetor[x] * num;
    }

    return *a;
}

int testarIgualdade(conjRacionais *a, conjRacionais *b)
{
    for (int x = 0; x < a->tam; x++)
    {
        for (int y = 0; y < b->tam; y++)
        {
            if (a->vetor[x] != b->vetor[y])
            {
                return -1; // conjuntos diferentes
            }
        }
    }

    return 1; // conjuntos iguais
}

void imprimirConj(conjRacionais *a)
{
    printf("\n");
    for (int x = 0; x < a->tam; x++)
    {
        printf("%f, ", a->vetor[x]);
    }
}

void inserirElementos(conjRacionais *a)
{
    printf("Digite quantos numeros tera o conjunto: \n");
    scanf("%d", &a->tam);
    printf("Forneca os elementos do conjunto \n");
    for (int x = 0; x < a->tam; x++)
    {
        printf("Numero %d: ", x + 1);
        scanf("%f", &a->vetor[x]);
    }
}