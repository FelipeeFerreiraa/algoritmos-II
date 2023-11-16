#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *anterior;
} no;

typedef struct pilha
{
    no *topo;
} pilha;

pilha *criarPilha();
void liberarPilha(pilha *p);
int empilhar(pilha *p, int num);
int desempilhar(pilha *p, int *num);
int estaVazia(pilha *p);
// int estaCheia(pilha *p); NAAAOO precisa
int impares(pilha *p);

void imprimirPilha(pilha *p);

int main()
{
    int opcao, num;
    pilha *p1;

    do
    {
        printf("\nEscolha:\n[0] Sair\n[1] Criar pilha\n[2] Empilhar\n[3] Desempilhar\n[4] Liberar Pilha\n[5] Imprimir\n[6] Impares\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            break;

        case 1:
            p1 = criarPilha();
            printf("\nPilha criada com sucesssssoo!!\n");
            break;

        case 2:
            printf("Digite um numero: ");
            scanf("%d", &num);
            if (empilhar(p1, num))
            {
                printf("\nEmpilhado com sucesssso!!\n");
            }
            else
            {
                printf("\nFalha ao empilhar\n");
            }
            break;

        case 3:
            if (desempilhar(p1, &num))
            {
                printf("\nDesempilhado com sucesso!!!  [%d]  \n", num);
            }
            else
            {
                printf("\nFalha ao desempilhar!!!\n");
            }
            break;

        case 4:
            liberarPilha(p1);
            printf("\nPilha liberada com sucesso!!!\n");
            break;

        case 5:
            if (p1 != NULL)
                imprimirPilha(p1);

            else
                printf("\nPilha vazia - crie uma!\n");
            break;

        case 6:
            if (p1 != NULL)
            {
                printf("\nA pilha possui %d numeros impares!!!\n", impares(p1));
            }
            else
                printf("\nPilha vazia!!!\n");
        }
    } while (opcao != 0);

    return 0;
}

pilha *criarPilha()
{
    pilha *p1;
    p1 = (pilha *)malloc(sizeof(pilha));
    p1->topo = NULL;
    return p1;
}

void liberarPilha(pilha *p)
{

    while (p->topo != NULL)
    {
        no *aux;
        aux = p->topo;
        p->topo = aux->anterior;
        free(aux);
    }
    free(p);
    p = NULL;
}

int empilhar(pilha *p, int num)
{
    no *novo;
    novo = (no *)(malloc(sizeof(no)));
    if (novo != NULL)
    {
        novo->valor = num;
        novo->anterior = p->topo;
        p->topo = novo;
        return 1;
    }
    else
        return 0;
}

int desempilhar(pilha *p, int *num)
{
    no *aux;
    if (estaVazia(p))
    {
        aux = p->topo;
        *num = aux->valor;
        p->topo = aux->anterior;
        free(aux);
        return 1;
    }
    else
        return 0;
}

int estaVazia(pilha *p)
{
    if (p->topo == NULL)
    {
        return 0;
    }
    else
        return 1; // NAO esta vaziaaaa
}

// int estaCheia(pilha *p); NAO precisaaa

void imprimirPilha(pilha *p)
{
    no *aux;
    aux = p->topo;

    printf("\n---------- PILHA --------------\n");
    while (aux != NULL)
    {
        printf("[%d]\n", aux->valor);
        aux = aux->anterior;
    }
    printf("\n---------- FIM PILHA --------------\n");
}

int impares(pilha *p)
{
    no *aux;
    int numImpares = 0;
    aux = p->topo;
    while (aux != NULL)
    {
        if (aux->valor % 2 != 0)
        {
            numImpares++;
        }
        aux = aux->anterior;
    }
    return numImpares;
}
