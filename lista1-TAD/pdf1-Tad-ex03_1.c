#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct conjInteiros
{
    int tam, vetorConj[MAX];
} conjInteiros;

conjInteiros *criarConj();
conjInteiros uniaoConjs(conjInteiros *a, conjInteiros *b);
conjInteiros inserir(conjInteiros *a);
conjInteiros remover(conjInteiros *a);

int main()
{

    return 0;
}

conjInteiros *criarConj()
{
    conjInteiros *c1;
    c1 = (conjInteiros *)malloc(1 * sizeof(conjInteiros));
    (*c1).tam = 0;
    (*c1).vetorConj[] = 0;

    return c1;
}

conjInteiros uniaoConjs(conjInteiros *a, conjInteiros *b)
{
    conjInteiros *conjUnido;

    conjUnido = (conjInteiros *)malloc(MAX * sizeof(conjInteiros));

    for (int x = 0; x < (*a).tam; x++)
    {
        (*conjUnido).vetorConj[x] = (*a).vetorConj[x];
    }

    int tamUniao = (*a).tam;

    for (int x = 0; x < (*b).tam; x++)
    {

        int testeIguais = 0;
        for (int z = 0; z < tamUniao; z++)
        {
            if ((*b).vetorConj[x] == (*conjUnido).vetorConj[z])
            {
                testeIguais = 1;
                break;
            }
        }

        if (testeIguais == 0)
        {
            (*conjUnido).vetorConj[x] = (*b).vetorConj[x];
            tamUniao++;
        }
    }

    conjUnido->tam = tamUniao;

    return *conjUnido;
}

conjInteiros inserir(conjInteiros *a)
{
    int num;
    Printf("Digite quantos elementos voce vai digitar\n");
    scanf("%d", &num);

    printf("Forneca os numeros:\n");
    for (int x = 0; x < num; x++)
    {
        printf("Numero %d: ", x + 1);
        scanf("%d", &a->vetorConj[x]);
    }

    printf("Numeros inseridos!!\n");

    return *a;
}

conjInteiros remover(conjInteiros *a)
{
    int num;
    printf("Elementos do conjunto:\n");
    for (int x = 0; x < a->tam; x++)
    {
        printf("%d, ", a->vetorConj[x]);
    }

    printf("Foreneca o numero que deseja remover: \n");
    scanf("%d", &num);

    for (int x = 0; x < a->tam; x++)
    {
        if (num == a->vetorConj[x])
        {
            a->vetorConj[x] = " ";
        }
    }

    return *a;
}
