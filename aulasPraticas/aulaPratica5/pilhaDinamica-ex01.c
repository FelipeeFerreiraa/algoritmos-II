
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
int empilhar(pilha *p, int num);
int desempilhar(pilha *p, int *num);
int estaVazia(pilha *p);
// int estaCheia(pilha *p); NAAAOOO PRECISA
void liberarPilha(pilha *p);

void imprimir(pilha *p);

int main()
{

    int opcao, num;
    pilha *p1;

    do
    {
        printf("\nEscolha\n[0] Sair\n[1] Criar Pilha\n[2] Empilhar\n[3] Desempilhar\n[4] Liberar Pilha\n[5] Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            break;
        case 1:
            p1 = criarPilha();
            printf("\nPilha criada com sucessssoooo\n");
            break;
        case 2:
            printf("Digite um numero: \n");
            scanf("%d", &num);
            if (empilhar(p1, num))
            {
                printf("\nEmpilhado com sucesso\n\n");
            }
            else
                printf("Falha ao empilhar!!!\n");
            break;
        case 3:
            if (desempilhar(p1, &num))
            {
                printf("\nNumero Desempilhado com sucesso [%d]\n\n", num);
            }
            else
                printf("Falha ao desempilhar!!!\n");
            break;

        case 4:
            liberarPilha(p1);
            printf("\nMemoria Liberada!!!\n\n");

            break;
        case 5:
            if (p1 != NULL)
            {
                imprimir(p1);
            }
            else
                printf("\nPilha vazia - crie uma!\n");
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
        p1->topo = NULL;
    return p1;
}

int empilhar(pilha *p, int num)
{
    no *novo;
    novo = (no *)malloc(sizeof(no));
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
        return 1; // NAAAOOO esta vazia
}

// int estaCheia(pilha *p); NAAAOOO PRECISA
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
    
}

void imprimir(pilha *p)
{
    printf("----------- Pilha -------------\n");
    no *aux = p->topo;
    while (aux != NULL)
    {
        printf(" [%d]\n", aux->valor);
        aux = aux->anterior;
    }

    printf("----------- Fim Pilha -------------\n");
}
