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
int estaVazia(fila *f);
// int estaCheia(fila *f);  NNAAAOOO precisa!
void liberarFila(fila *f);
void imprimir(fila *f);

int main()
{

    int opcao, num;
    fila *f1;

    do
    {
        printf("\nEscolha\n[0] Sair\n[1] Criar Fila\n[2] Enfileirar\n[3] Desenfileirar\n[4] Liberar Fila\n[5] Imprimir\n");
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
                imprimir(f1);
            }
            else
                printf("\nFila vazia - crie uma!\n");
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
    f1->fim = NULL;
    f1->inicio = NULL;

    return f1;
}

int enfileirar(fila *f, int num)
{
    no *novo;
    novo = (no *)malloc(sizeof(no));
    if (novo != NULL)
    {
        novo->prox = NULL;
        novo->valor = num;

        if (f->fim == NULL)
        {
            f->inicio = novo;
            f->fim = novo;
        }
        else
        {
            f->fim->prox = novo;
            f->fim = novo;
            return 1;
        }
    }
    else
        return 0;
}

int desenfileirar(fila *f, int *num)
{
    if (f != NULL)
    {

        if (f->inicio == NULL) // fila vaziaaaa
        {
            return 0;
        }

        no *aux;
        aux = f->inicio;
        *num = aux->valor;
        f->inicio = aux->prox;
        if (f->inicio == NULL) // verificando se foi o ultimo NO
        {
            f->fim = NULL;
        }
        free(aux);
        return 1;
    }
    else
        return 0;
}

int estaVazia(fila *f)
{
    if (f->fim && f->inicio == NULL)
        return 0; /// esta vaziaa
    else
        return 1; /// NAAAOO  esta vazia!
}

// int estaCheia(fila *f);  NNAAAOOO precisa!
void liberarFila(fila *f)
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

void imprimir(fila *f)
{
    no *aux = f->inicio;

    printf("\nINICIO DA FILA -------------\n");
    while (aux != NULL)
    {
        printf("[%d]  , ", aux->valor);
        aux = aux->prox;
    }
    printf("\n----------------------- FIM DA FILA\n");
}