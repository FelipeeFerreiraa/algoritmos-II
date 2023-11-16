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
    no *inicio, *final;
} fila;

fila *criarFila();
int enfileirar(fila *f, int num);
int desenfileirar(fila *f, int *num);
int estaVazia(fila *f);
// int estaCheia(fila *f);  NAO PRECISAAAAA
void liberarFila(fila *f);

void imprimirFila(fila *f);
int maiorFila(fila *f1, fila *f2);

int main()
{

    int opcao, num;
    fila *f1 = NULL, *f2 = NULL;

    printf("Crie duas Pilhas!\n");
    f1 = criarFila();
    f2 = criarFila();
    do
    {
        printf("\nEscolha\n[0] Sair\n[2] Enfileirar F1\n[3] Enfileirar F2\n[4] Imprimir F1\n[5] Imprimir F2\n[6] Comparar Filas\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            break;
        case 2:
            printf("Digite um numero: \n");
            scanf("%d", &num);

            if (enfileirar(f1, num))
            {
                printf("\nF1 Enfileirado com sucesso!!!!!\n");
            }
            else
                printf("Falha ao enfileirar!!!\n");

            break;

        case 3:
            printf("Digite um numero: \n");
            scanf("%d", &num);

            if (enfileirar(f2, num))
            {
                printf("\nF2 Enfileirado com sucesso!!!!!\n");
            }
            else
                printf("Falha ao enfileirar!!!\n");
            break;

        case 4:
            if (f1 != NULL)
            {
                imprimirFila(f1);
            }
            else
            {
                printf("Crie uma Fila!!!\n");
            }
            break;

        case 5:
            if (f2 != NULL)
            {
                imprimirFila(f2);
            }
            else
            {
                printf("Crie uma Filaaa!!!\n");
            }
            break;

        case 6:
            if (maiorFila(f1, f2))
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

fila *criarFila()
{
    fila *f1;
    f1 = (fila *)malloc(sizeof(fila));
    if (f1 != NULL)
    {
        f1->final = NULL;
        f1->inicio = NULL;
    }
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

        if (f->final == NULL)
        {
            f->final = novo;
            f->inicio = novo;
        }
        else
        {
            f->final = novo;
            f->final->prox = novo;
            return 1;
        }
    }
    else
        return 0;

}

int desenfileirar(fila *f, int *num)
{
    no *aux;
    if (f != NULL)
    {
        if (f->inicio == NULL)
        {
            return 0;
        }

        aux = f->inicio;
        *num = aux->valor;
        f->inicio = aux->prox;

        if (f->inicio == NULL)
        {
            f->final = NULL;
        }

        free(aux);
        return 1;
    }
    else
        return 0;
}

int estaVazia(fila *f)
{
    if (f->final && f->inicio == NULL)
    {
        return 0;
    }
    else
        return 1;
}

// int estaCheia(fila *f);  NAO PRECISAAAAA
void liberarFila(fila *f)
{
    if (f != NULL)
    {
        while (f->inicio != NULL)
        {
            no *aux = f->inicio;
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

int maiorFila(fila *f1, fila *f2)
{
    int tam1 = 0, tam2 = 0;

    if (f1 && f2 != NULL)
    {
        while (f1->inicio != NULL)
        {
            no *aux = f1->inicio;
            f1->inicio = aux->prox;
            tam1++;
        }

        while (f2->inicio != NULL)
        {
            no *aux2 = f2->inicio;
            f2->inicio = aux2->prox;
            tam2++;
        }

        if (tam1 > tam2)
        {
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}