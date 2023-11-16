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
void inverter(pilha *p);

void imprimirPilha(pilha *p);

int main()
{
    int opcao, num;
    pilha *p1 = NULL;

    do
    {
        printf("\nEscolha\n[0] Sair\n[1] Criar Pilha\n[2] Empilhar\n[3] Desempilhar\n[4] Liberar Pilha\n[5] Imprimir\n[6] Inverter\n");
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
            printf("Digite um numero: \n");
            scanf("%d", &num);

            if (empilhar(p1, num))
            {
                printf("\nEmpilhado com sucesso!!!!!\n");
            }
            else
                printf("Falha ao empilhar!!!\n");
            break;

        case 3:
            if (desempilhar(p1, &num))
            {
                printf("Numero Desempilhado com sucesso [%d]\n", num);
            }
            else
                printf("Falha ao desempilhar!!!\n");
            break;

        case 4:
            liberarPilha(p1);
            printf("\nPilha liberada com sucesso!!!\n");
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
            inverter(p1);

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

void inverter(pilha *p)
{
    pilha *novaInvertida = criarPilha();

    int numDesempilhado;
    while (p->topo != NULL)
    {
        desempilhar(p, &numDesempilhado);

        empilhar(novaInvertida, numDesempilhado);
    }

    printf("\n!!!!!!!!!!!!!!!PILHA INVERTIDA!!!!!!!!!!!!!!!\n");
    imprimirPilha(novaInvertida);

    // empilhando de volta
    while (novaInvertida->topo != NULL)
    {
        desempilhar(novaInvertida, &numDesempilhado);

        empilhar(p, numDesempilhado);
    }
}