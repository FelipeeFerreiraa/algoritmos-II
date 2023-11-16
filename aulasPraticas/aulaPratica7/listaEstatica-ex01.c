#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
funçao de pesquisar indice e elemento contem algum erro (arrumar dps)
*/

#define MAX 5

typedef struct lista
{
    int vetor[MAX], N;
} lista;

lista *criarLista();
void liberarLista(lista *l);
int estaCheia(lista *l);
int estaVazia(lista *l);

int inserirFinal(lista *l, int num);
int inserirInicio(lista *l, int num);
int inserirPosicao(lista *l, int num, int pos);

int removerFinal(lista *l, int *num);
int removerMeio(lista *l, int *num, int pos);
int removerInicio(lista *l, int *num);

int pesquisarChave(lista *l, int *elemento); // mostra o indice do elemento existente na lista
int pesquisarPosicao(lista *l, int *pos);    // mostra o elemento existente no indice fornecido

int qtdElementos(lista *l);
void imprimirLista(lista *l);

int main()
{
    int opcao, num, pos;
    lista *l1;

    do
    {
        printf("\nEscolha:\n[0] Sair\n[1] Criar Lista\n[2] Inserir no Final\n[3] Inserir no Inicio\n[4] Informar posicao para inserir\n[5] Remover do final\n[6] Remover do inicio\n[7] Informar posicao para remover\n[8] Pesquisar elemento\n[9] Pesquisar Indice\n[10] Verificar Quantidade de elementos\n[11] Liberar lista\n[12] Imprimir Lista\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            break;

        case 1:
            l1 = criarLista();
            printf("\nLista Criada Com Sucessssso!\n");
            break;

        case 2:
            printf("Digite um numero: \n");
            scanf("%d", &num);
            if (inserirFinal(l1, num))
            {
                printf("\n\nNumero inserido com Sucessso!!\n");
            }
            else
            {
                printf("\nFalha ao inserir numero!\n");
            }
            break;

        case 3:
            printf("Digite um numero: \n");
            scanf("%d", &num);
            if (inserirInicio(l1, num))
            {
                printf("\n\nNumero inserido com Sucessso!!\n");
            }
            else
            {
                printf("\nFalha ao inserir numero!\n");
            }
            break;

        case 4:
            printf("Informe em qual posicao deseja inserir: \n");
            scanf("%d", &pos);
            printf("Digite um numero: \n");
            scanf("%d", &num);
            if (inserirPosicao(l1, num, pos))
            {
                printf("\n\nNumero inserido com Sucessso!!\n");
            }
            else
            {
                printf("\nFalha ao inserir numero!\n");
            }
            break;

        case 5:
            if (removerFinal(l1, &num))
            {
                printf("\nNumero removido com sucesso!! [%d]\n", num);
            }
            else
            {
                printf("\nFalha ao remover numero!!\n");
            }
            break;

        case 6:
            if (removerInicio(l1, &num))
            {
                printf("\nNumero removido com sucesso!! [%d]\n", num);
            }
            else
            {
                printf("\nFalha ao remover numero!!\n");
            }
            break;

        case 7:
            printf("Informe em qual posicao deseja remover: \n");
            scanf("%d", &pos);
            printf("Digite um numero: \n");
            scanf("%d", &num);
            if (removerMeio(l1, &num, pos))
            {
                printf("\nNumero removido com sucesso!! [%d]\n", num);
            }
            else
            {
                printf("\nFalha ao remover numero!!\n");
            }
            break;

        case 8:
            printf("Informe qual elemento voce deseja pesquisar se tem na lista: \n");
            scanf("%d", &pos);
            
            if (pesquisarChave(l1, &pos))
            {
                printf("\nNumero informado esta na posicao [%d] da lista\n", pos);
            }
            else
            {
                printf("\nFalha ao encontrar numero!!\n");
            }

            break;

        case 9:
            printf("Informe qual indice voce deseja pesquisar se tem na lista: \n");
            scanf("%d", &pos);

            if (pesquisarChave(l1, &pos))
            {
                printf("\nIndice informado contem o numero [%d] da lista\n", pos);
            }
            else
            {
                printf("\nFalha ao encontrar indice!!\n");
            }
            break;

        case 10:

            printf("\nA lista contem %d elementos\n", qtdElementos(l1));

            break;

        case 11:
            liberarLista(l1);
            printf("\nMemoria liberada!\n");
            break;

        case 12:
            imprimirLista(l1);
            break;

        default:
            printf("\nNumero invalido digite outro!!!\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}

lista *criarLista()
{
    lista *l1;
    l1 = (lista *)malloc(sizeof(lista));
    if (l1 != NULL)
    {
        l1->N = 0;
    }
    return l1;
}

void liberarLista(lista *l)
{
    free(l);
}

int estaCheia(lista *l)
{
    if (l->N == MAX)
    {
        return 0; // esta cheiaaaaa!
    }
    else
        return 1;
}

int estaVazia(lista *l)
{
    if (l->N == 0)
    {
        return 0; // lista esta vaziaa!
    }
    else
        return 1;
}

int inserirFinal(lista *l, int num)
{
    if (estaCheia(l))
    {
        l->vetor[l->N] = num;
        l->N++;
        return 1;
    }
    else
        return 0;
}

int inserirInicio(lista *l, int num)
{
    if (estaCheia(l))
    {
        int aux = l->N;
        while (aux != 0)
        {
            // l->vetor[aux + 1] = l->vetor[aux];
            l->vetor[aux] = l->vetor[aux - 1];
            aux--;
        }

        l->vetor[aux] = num;
        l->N++;
        return 1;
    }
    else
        return 0;
}

int inserirPosicao(lista *l, int num, int pos)
{
    if (estaCheia(l))
    {
        if (pos >= MAX)
        {
            return 0; // Posicao invalida
        }

        int aux = pos;
        while (l->vetor[l->N] > l->vetor[pos])
        {
            l->vetor[aux + 1] = l->vetor[aux];
        }
        l->vetor[pos] = num;
        l->N++;
        return 1;
    }
    else
        return 0;
}

int removerFinal(lista *l, int *num)
{
    if (l != NULL)
    {
        if (l->N == 0)
        {
            return 0;
        }
        *num = l->vetor[l->N - 1];
        l->N--;
        return 1;
    }
    else
        return 0;
}

int removerMeio(lista *l, int *num, int pos)
{
    if (l != NULL)
    {
        if (l->N == 0)
        {
            return 0;
        }

        *num = l->vetor[pos];
        int aux = pos;
        while (aux < l->N + 1)
        {
            l->vetor[aux] = l->vetor[aux + 1];
            aux++;
        }
        l->N--;
        return 1;
    }
    else
        return 0;
}

int removerInicio(lista *l, int *num)
{
    if (l != NULL)
    {
        if (l->N == 0)
        {
            return 0;
        }
        int aux = l->N, x = 0;
        *num = l->vetor[0];
        while (aux != 0)
        {
            l->vetor[x] = l->vetor[x + 1];
            x++;
            aux--;
        }
        l->N--;
        return 1;
    }
    else
        return 0;
}

int pesquisarChave(lista *l, int *elemento)
{
    if (l != NULL)
    {
        if (l->N == 0)
            return 0;

        int x = 0;
        while (x < l->N)
        {
            if (*elemento == l->vetor[x])
            {
                *elemento = x; // indice do elemento na lista
                return 1;
            }

            x++;
        }
    }
    else
        return 0;
}

int pesquisarPosicao(lista *l, int *pos)
{
    if (l != NULL)
    {
        if (l->N == 0)
            return 0;

        if (*pos > l->N || *pos <= 0)
        {
            return 0;
        }
        else
        {
            *pos = l->vetor[*pos - 1]; // elemento da posicao fornecida
            return 1;
        }
    }
    else
        return 0;
}

int qtdElementos(lista *l)
{
    return l->N;
}

void imprimirLista(lista *l)
{
    if (l != NULL)
    {
        // int aux = l->N - 1;
        int aux = 0;

        printf("\n--------- LISTA -------\n");
        while (aux < l->N)
        {
            printf("%d, ", l->vetor[aux]);
            // aux--;
            aux++;
        }
        printf("\n--------- LISTA -------\n");
    }
}