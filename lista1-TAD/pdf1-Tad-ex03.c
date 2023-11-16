#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct conjuntoInteiros
{
    int tam, inteiros[100];
} conjuntoInteiros;

#define MAX 100

conjuntoInteiros uniaoDeConjuntos(conjuntoInteiros a, conjuntoInteiros b);
conjuntoInteiros criarConjVazio(conjuntoInteiros *a);
void inserirElementos(conjuntoInteiros *a);
void imprimindoConj(conjuntoInteiros a);
conjuntoInteiros removerElementos(conjuntoInteiros a);
conjuntoInteiros interseccao(conjuntoInteiros a, conjuntoInteiros b);
conjuntoInteiros diferenca(conjuntoInteiros a, conjuntoInteiros b);
int pertencimento(conjuntoInteiros a);
int menorValor(conjuntoInteiros a);
int maiorValor(conjuntoInteiros a);
int igualdadeConj(conjuntoInteiros a, conjuntoInteiros b);
int verificarTam(conjuntoInteiros a);
int testarConjVazio(conjuntoInteiros a);

int main()
{

    conjuntoInteiros conj1, conj2, conjUniao;

    printf("Inserindo elementos no conjunto-1 \n");
    inserirElementos(&conj1);

    printf("Inserindo elementos no conjunto-2 \n");
    inserirElementos(&conj2);

    imprimindoConj(conj1);
    imprimindoConj(conj2);

    conjUniao = uniaoDeConjuntos(conj1, conj2);

    // printf("\nConjunto-1:  ");
    // imprimindoConj(conj1);

    //  printf("\nConjunto-2:  ");
    // imprimindoConj(conj2);

    printf("\nConjuntoUniao:  ");
    imprimindoConj(conjUniao);

    return 0;
}

conjuntoInteiros uniaoDeConjuntos(conjuntoInteiros a, conjuntoInteiros b)
{
    conjuntoInteiros conjUniao;
    int somaTam = 0;
    for (int w = 0; w < a.tam; w++)
    {

        conjUniao.inteiros[w] = a.inteiros[w];
    }

    for (int x = 0; x < b.tam; x++)
    {
        // for (int y = 0; y < a.tam; y++)
        //{
        if (b.inteiros[x] != a.inteiros[x])
        {

            conjUniao.inteiros[a.tam + x] = b.inteiros[x];
            somaTam++;
        }
        //}
    }

    conjUniao.tam = a.tam + somaTam;

    return conjUniao;
}

void inserirElementos(conjuntoInteiros *a)
{
    printf("Digite quantos numeros tera o conjunto: \n");
    scanf("%d", &a->tam);
    printf("Forneca os elementos do conjunto \n");
    for (int x = 0; x < a->tam; x++)
    {
        printf("Numero %d: ", x + 1);
        scanf("%d", &a->inteiros[x]);
    }
}

conjuntoInteiros criarConjVazio(conjuntoInteiros *a)
{
    a = malloc(MAX * sizeof(conjuntoInteiros));
    (*a).tam = 1;
    (*a).inteiros[0] = 0;
    return *a;
}

void imprimindoConj(conjuntoInteiros a)
{
    printf("Tamanho do conjunto: %d\n", a.tam);
    for (int x = 0; x < a.tam; x++)
    {
        printf("%d, ", a.inteiros[x]);
    }
}

conjuntoInteiros removerElementos(conjuntoInteiros a)
{
    int remover;
    printf("Digite qual numero voce deseja remover do conjunto: (caso ele esteja no vetor) \n");
    scanf("%d", &remover);

    for (int x = 0; x < a.tam; x++)
    {
        if (a.inteiros[x] == remover)
        {
            a.inteiros[x] = ' ';
        }
    }

    return a;
}

conjuntoInteiros interseccao(conjuntoInteiros a, conjuntoInteiros b)
{
    conjuntoInteiros conjInter;
    int tamConj = 0;

    for (int x = 0; x < a.tam; x++)
    {
        for (int y = 0; y < b.tam; y++)
        {
            if (a.inteiros[x] == b.inteiros[y])
            {
                conjInter.inteiros[x] = a.inteiros[x];
                tamConj++;
            }
        }
    }

    conjInter.tam = tamConj;

    return conjInter;
}

conjuntoInteiros diferenca(conjuntoInteiros a, conjuntoInteiros b)
{
    conjuntoInteiros conjDiferenca;
    int tamConj = 0;

    for (int x = 0; x < a.tam; x++)
    {
        conjDiferenca.inteiros[x] = a.inteiros[x];
    }

    for (int x = 0; x < a.tam; x++)
    {
        for (int y = 0; y < b.tam; y++)
        {
            if (a.inteiros[x] == b.inteiros[y])
            {
                conjDiferenca.inteiros[x] = ' ';
                tamConj++;
            }
        }
    }

    conjDiferenca.tam = a.tam - tamConj;

    return conjDiferenca;
}

int pertencimento(conjuntoInteiros a)
{
    int num;
    printf("Digite um numero para verificar se ele pertence ao conjunto: ");
    scanf("%d", &num);

    for (int x = 0; x < a.tam; x++)
    {
        if (a.inteiros[x] == num)
        {
            return 1; // pertence ao conjunto
        }
    }

    return -1; // nao pertence
}

int menorValor(conjuntoInteiros a)
{
    int menorValor = a.inteiros[0];

    for (int x = 0; x < a.tam; x++)
    {
        if (a.inteiros[x] < menorValor)
        {
            menorValor = a.inteiros[x];
        }
    }

    return menorValor;
}

int maiorValor(conjuntoInteiros a)
{
    int maiorValor = a.inteiros[0];

    for (int x = 0; x < a.tam; x++)
    {
        if (a.inteiros[x] > maiorValor)
        {
            maiorValor = a.inteiros[x];
        }
    }

    return maiorValor;
}

int igualdadeConj(conjuntoInteiros a, conjuntoInteiros b)
{
    // int igualdade;

    if (a.tam == b.tam)
    {
        for (int x = 0; x < a.tam; x++)
        {
            for (int y = 0; y < b.tam; y++)
            {
                if (a.inteiros[x] != b.inteiros[y])
                {
                    return -1; // conjuntos diferentes
                }
                else
                {
                    return 1; // conjuntos iguais
                }
            }
        }
    }

    return -1; // conjuntos diferentes
}

int verificarTam(conjuntoInteiros a)
{
    return a.tam;
}

int testarConjVazio(conjuntoInteiros a)
{
    if (a.tam == 1 && a.inteiros[0] == 0)
    {
        return 1; // conjunto vazio
    }
    return -1; // nao eh um conjunto vazio
}