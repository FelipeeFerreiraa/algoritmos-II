#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct pilha
{
    int topo, vetor[MAX];
} pilha;

pilha *criarPilha();
void liberarPilha(pilha *p);
int empilhar(pilha *p);
int desempilhar(pilha *p, int *num);
int estaVazia(pilha *p);
int estaCheia(pilha *p);

int impares(pilha *p);

void imprimirPilha(pilha *p);

int main()
{

    int opcao, num;
    pilha *p1;

    do
    {
        printf("Escolha\n[0] Sair\n[1] Criar Pilha\n[2] Empilhar\n[3] Desempilhar\n[4] Liberar Pilha\n[5] Imprimir\n[6] Qtd valores impares\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            break;
        case 1:
            p1 = criarPilha();
            break;
        case 2:
            if (empilhar(p1) == 1)
            {
                printf("Empilhado com sucesso\n");
            }
            else
                printf("Falha ao empilhar!!!\n");
            break;
        case 3:
            if (desempilhar(p1, &num) == 1)
            {
                printf("Numero Desempilhado com sucesso [%d]\n", num);
            }
            else
                printf("Falha ao desempilhar!!!\n");
            break;
        case 4:
            liberarPilha(p1);
            printf("Memoria Liberada!!!\n");
            break;
        case 5:
            if (p1 != NULL)
            {
                imprimirPilha(p1);
            }
            else
            {
                printf("Crie uma pilha!!!\n");
            }
            break;

        case 6:
            printf("\n\nNa pilha possui %d numeros IMPARES!!!\n\n", impares(p1));
            break;
        default:
            break;
        }
    } while (opcao != 0);

    return 0;
}

pilha *criarPilha()
{
    pilha *p;
    p = (pilha *)malloc(sizeof(pilha));

    p->topo = 0;
    return p;
}

void liberarPilha(pilha *p)
{
    free(p);
}

int empilhar(pilha *p)
{
    if (p != NULL && estaCheia(p) != 0)
    {
        printf("Digite um numero: \n");
        scanf("%d", &p->vetor[p->topo]);
        p->topo++;
        return 1;
    }
    else
        printf("##ERRO NA ALOCACAO DE MEMORIA!!!!");
    return -1;
}

int desempilhar(pilha *p, int *num)
{
    if (p != NULL && estaVazia(p) != 0)
    {
        *num = p->vetor[p->topo - 1];
        p->topo--;
        return 1;
    }
    else
        printf("Pilha esta vazia!!!");
    return -1;
}

int estaVazia(pilha *p)
{
    if (p->topo == 0)
    {
        printf("Pilha esta vazia!!!\n");
        return 0;
    }

    else
        return 1;
}

int estaCheia(pilha *p)
{
    if (p->topo == MAX)
    {
        printf("Pilha cheia!!!\n");
        return 0;
    }
    else
        return 1;
}

void imprimirPilha(pilha *p)
{

    printf("----------- Pilha -------------\n");
    int i = p->topo - 1;
    while (i >= 0)
    {
        printf(" [%d]\n", (*p).vetor[i]);
        i--;
    }

    printf("----------- Fim Pilha -------------\n");
}

int impares(pilha *p)
{
    int numImpares = 0;
    for (int x = 0; x < p->topo; x++)
    {
        if (p->vetor[x] % 2 != 0)
        {
            numImpares++;
        }
    }

    return numImpares;
}
