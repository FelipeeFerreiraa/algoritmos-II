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
int compTam(pilha *p1, pilha *p2);

void imprimirPilha(pilha *p);

int main()
{
    int opcao, num;
    pilha *p1 = NULL, *p2 = NULL;

    printf("Crie duas Pilhas!\n");
    p1 = criarPilha();
    p2 = criarPilha();
    do
    {
        printf("\nEscolha\n[0] Sair\n[2] Empilhar P1\n[3] Empilhar P2\n[4] Imprimir P1\n[5] Imprimir P2\n[6] Comparar Pilhas\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            break;
        case 2:
            printf("Digite um numero: \n");
            scanf("%d", &num);

            if (empilhar(p1, num))
            {
                printf("\nP1 Empilhado com sucesso!!!!!\n");
            }
            else
                printf("Falha ao empilhar!!!\n");

            break;

        case 3:
            printf("Digite um numero: \n");
            scanf("%d", &num);

            if (empilhar(p2, num))
            {
                printf("\nP2 Empilhado com sucesso!!!!!\n");
            }
            else
                printf("Falha ao empilhar!!!\n");
            break;

        case 4:
            if (p1 != NULL)
            {
                imprimirPilha(p1);
            }
            else
            {
                printf("Crie uma pilha!!!\n");
            }
            break;

        case 5:
            if (p2 != NULL)
            {
                imprimirPilha(p2);
            }
            else
            {
                printf("Crie uma pilha!!!\n");
            }
            break;

        case 6:
            if (compTam(p1, p2))
            {
                printf("\nPilha 1 eh maior!!!!!\n");
            }
            else
            {
                printf("\nPilha 1 NNAAOO eh maior!!!!!\n");
            }
            break;
        default:
            break;
        }
    } while (opcao != 0);

    return 0;
}

pilha *criarPilha()
{
    pilha *p1;
    p1 = (pilha *)malloc(sizeof(pilha));
    if (p1 != NULL)
    {
        p1->topo = NULL;
    }
    return p1;
}

void liberarPilha(pilha *p)
{

    while (p->topo != NULL)
    {
        no *aux = p->topo;

        p->topo = aux->anterior;
        free(aux);
    }
    free(p);
}

int empilhar(pilha *p, int num)
{
    no *novo;
    novo = (no *)malloc(sizeof(no));
    if (novo != NULL)
    {
        novo->anterior = p->topo;
        novo->valor = num;
        p->topo = novo;
        return 1;
    }
    else
        return 0;
}

int desempilhar(pilha *p, int *num)
{
    no *aux;
    aux = p->topo;
    if (estaVazia(p))
    {
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
        return 1;
}

// int estaCheia(pilha *p); NAAAOO precisa

void imprimirPilha(pilha *p)
{
    no *aux = p->topo;
    printf("\n------------------ PILHA -----------------\n");
    while (aux != NULL)
    {
        printf("[%d]\n", aux->valor);
        aux = aux->anterior;
    }
    printf("\n------------------ FIM PILHA -----------------\n");
}

int compTam(pilha *p1, pilha *p2)
{
    no *aux1 = p1->topo, *aux2 = p2->topo;

    int tam1 = 0, tam2 = 0;

    while (aux1 != NULL)
    {
        tam1++;
        aux1 = aux1->anterior;
    }

    while (aux2 != NULL)
    {
        tam2++;
        aux2 = aux2->anterior;
    }

    if (tam1 > tam2)
    {
        return 1;
    }
    else
        return 0;
}
