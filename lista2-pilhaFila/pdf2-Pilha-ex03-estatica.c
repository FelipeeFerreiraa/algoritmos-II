#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct pilha
{
    int topo, vetor[MAX];
} pilha;

pilha *criarPilha();
int empilhar(pilha *p);
int desempilhar(pilha *p, int *num);
int estaVazia(pilha *p);
int estaCheia(pilha *p);

pilha *liberarPilha(pilha *p);
void imprimirPilha(pilha *p);

int maior(pilha *p);
int menor(pilha *p);
float media(pilha *p);

int main()
{
    int opcao, num;
    pilha *p1 = NULL;

    do
    {
        printf("\nEscolha\n[0] Sair\n[1] Criar Pilha\n[2] Empilhar\n[3] Desempilhar\n[4] Liberar Pilha\n[5] Imprimir\n[6] Maior Valor\n[7] Menor Valor\n[8] Media dos Valores\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            break;
        case 1:
            p1 = criarPilha();
            printf("\nPilha Criada com sucessssoo!!\n");
            break;
        case 2:

            if (empilhar(p1))
            {
                printf("\nEmpilhado com sucesso\n");
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

            p1 = liberarPilha(p1);
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
            printf("\nMaior valor da Pilha = [%d]\n", maior(p1));
            break;

        case 7:
            printf("\nMenor valor da Pilha = [%d]\n", menor(p1));
            break;

        case 8:
            printf("\nMedia dos valores da Pilhaa = [%.2f]\n", media(p1));
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

int empilhar(pilha *p)
{
    int num;
    if (estaCheia(p))
    {
        printf("Digite um numero: \n");
        scanf("%d", &num);
        p->vetor[p->topo] = num;
        p->topo++;
        return 1;
    }
    else
        return 0;
}

int desempilhar(pilha *p, int *num)
{
    if (estaVazia(p))
    {
        *num = (*p).vetor[(*p).topo - 1];
        p->topo--;
        return 1;
    }
    else
        return 0;
}

int estaVazia(pilha *p)
{
    if (p != NULL && p->topo != 0)
    {
        return 1;
    }
    else
        printf("Pilha vazia!!!\n");
    return 0;
}

int estaCheia(pilha *p)
{
    if (p != NULL && p->topo != MAX)
    {
        return 1;
    }
    else
        printf("Pilha cheia!!!\n");
    return 0;
}

pilha *liberarPilha(pilha *p)
{
    free(p);
    p = NULL;
    printf("Memoria Liberadaaa!!\n");
    return p;
}

void imprimirPilha(pilha *p)
{

    int i = (*p).topo - 1;

    printf("\n---------- PILHA ---------\n");
    while (i >= 0)
    {
        printf("         [%d]\n", p->vetor[i]);
        i--;
    }
    printf("\n---------- FIM PILHA ---------\n");
}

int maior(pilha *p)
{
    int aux = p->topo - 1;
    int maior = p->vetor[0];
    for (int x = 0; x < aux; x++)
    {
        if (maior < p->vetor[x])
        {
            maior = p->vetor[x];
        }
    }

    return maior;
}

int menor(pilha *p)
{
    int aux = p->topo;
    int menor = p->vetor[0];
    for (int x = 0; x < aux; x++)
    {
        if (menor > p->vetor[x])
        {
            menor = p->vetor[x];
        }
    }

    return menor;
}

float media(pilha *p)
{
    int aux = p->topo;
    int soma = 0, media;
    for (int x = 0; x < aux; x++)
    {
        soma = soma + p->vetor[x];
    }
    media = soma / aux;

    return media;
}