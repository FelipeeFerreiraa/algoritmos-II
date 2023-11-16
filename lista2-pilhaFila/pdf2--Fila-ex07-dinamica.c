#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *prox;
} no;

typedef struct fila
{
    no *inicio, *fim;
} fila;

fila *criarFila();
int enfileirar(fila *f, int num);
int desenfileirar(fila *f, int *num);
int estahVazia(fila *f);
// estahCheia(fila *f); NAO precisa fazer
void liberarFila(fila *f);

void imprimirFila(fila *f);
int pares(fila *f);

int main()
{

    int opcao, num;
    fila *f1;

    do
    {
        printf("\nEscolha\n[0] Sair\n[1] Criar Fila\n[2] Enfileirar\n[3] Desenfileirar\n[4] Liberar Fila\n[5] Imprimir\n[6] Numeros pares\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            break;
        case 1:
            f1 = criarFila();
            printf("\nFila criada com sucessssoooo\n");
            break;
        case 2:
            printf("Digite um numero: \n");
            scanf("%d", &num);
            if (enfileirar(f1, num))
            {
                printf("\nEnfileirado com sucesso\n\n");
            }
            else
            {
                printf("Falha ao enfileirar!!!\n");
            }

            break;
        case 3:
            if (desenfileirar(f1, &num))
            {
                printf("\nNumero Desenfileirado com sucesso [%d]\n\n", num);
            }
            else
                printf("Falha ao Desenfileirar!!!\n");
            break;

        case 4:
            liberarFila(f1);
            printf("\nMemoria Liberada!!!\n\n");

            break;
        case 5:
            if (f1 != NULL)
            {
                imprimirFila(f1);
            }
            else
                printf("\nFila vazia - crie uma!\n");
            break;

        case 6:
            if (f1 != NULL)
            {
                printf("\nA Fila possui %d numeros impares!!!\n", pares(f1));
            }
            else
                printf("\nPilha vazia!!!\n");
            break;

        default:
            break;
        }
    } while (opcao != 0);

    return 0;
}

fila *criarFila()
{
    fila *f1;
    f1 = (fila *)malloc(sizeof(fila));

    if (f1 != NULL)
    {
        f1->fim = NULL;
        (*f1).inicio = NULL;
    }
    return f1;
}

int enfileirar(fila *f, int num)
{
    no *novo;
    novo = (no *)malloc(sizeof(no));
    if (novo != NULL) // adicionando primeiro elemento da fila
    {
        novo->valor = num;
        novo->prox = NULL;

        if (f->fim == NULL) // se a fila estiver vazia
        {
            f->inicio = novo;
            f->fim = novo;
        }
        else // inserindo no final da fila
        {
            f->fim->prox = novo;
            f->fim = novo;
            return 1;
        }
    }

    return 0;
}

int desenfileirar(fila *f, int *num)
{
    if (f != NULL)
    {
        if (f->inicio == NULL) // fila vaziaaaaa
        {
            return 0;
        }

        no *aux;
        aux = f->inicio;
        *num = aux->valor;
        f->inicio = aux->prox;
        if (f->inicio == NULL)
        {
            f->fim = NULL;
        }
        free(aux);

        return 1;
    }
    else
        return 0;
}

int estahVazia(fila *f)
{
    if (f->fim && f->inicio == NULL)
    {
        return 1;
    }
    else
        return 0; // pilha NAAOO esta vazia
}

void liberarFila(fila *f)
{
    if (f != NULL)
    {
        no *aux;
        while (f->inicio != NULL)
        {
            aux = f->inicio;
            f->inicio = aux->prox;
            free(aux);
        }
        free(f);
    }
}

void imprimirFila(fila *f)
{
    no *aux;
    aux = f->inicio;

    printf("\nINICIO DA FILA -------------\n");
    while (aux != NULL)
    {
        printf("[%d]  ,   ", aux->valor);
        aux = aux->prox;
    }
    printf("\n----------------------- FIM DA FILA\n");
}

int pares(fila *f)
{
    int numPares = 0;
    no *aux;
    if (f != NULL)
    {
        aux = f->inicio;
        while (aux != NULL)
        {
            if (aux->valor % 2 == 0)
            {
                numPares++;
            }
            aux = aux->prox;
        }
        return numPares;
    }
    else
        return 0;
}