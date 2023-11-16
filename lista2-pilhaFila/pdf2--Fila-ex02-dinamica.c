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
void liberarFila(fila *f);
int enfileirar(fila *f, int num);
int desenfileirar(fila *f, int *num);
int estaVazia(fila *f);
// int estaCheia(fila *f); ------ nao precisa
void imprimirFila(fila *f);

int maior(fila *f);
int menor(fila *f);
float media(fila *f);

int main()
{

    int opcao, num;
    fila *f1;

    do
    {
        printf("\nEscolha\n[0] Sair\n[1] Criar Fila\n[2] Enfileirar\n[3] Desenfileirar\n[4] Liberar Fila\n[5] Imprimir\n[6] Maior Valor da Fila\n[7] Menor valor da Fila\n[8] Media dos valores da Fila\n");
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
            printf("\nMaior valor da Fila = [%d]\n", maior(f1));
            break;

        case 7:
            printf("\nMenor valor da Fila = [%d]\n", menor(f1));
            break;

        case 8:
            printf("\nMedia dos valores da Fila = [%.2f]\n", media(f1));
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

int enfileirar(fila *f, int num)
{
    no *novo;
    novo = (no *)malloc(sizeof(no));
    if (novo != NULL)
    {
        novo->valor = num;
        novo->prox = NULL;

        if (f->final == NULL)
        {
            f->final = novo;
            f->inicio = novo;
        }
        else
        {
            f->final->prox = novo;
            f->final = novo;
        }
        return 1;
    }
    else
        return 0;
}

int desenfileirar(fila *f, int *num)
{
    if (f != NULL)
    {
        no *aux;
        aux = f->inicio;

        if (aux == NULL)
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

// int estaCheia(fila *f); ------ nao precisa
void imprimirFila(fila *f)
{
    no *aux;
    aux = f->inicio;

    printf("\n-----------------------------INICIO DA FILA\n");
    while (aux != NULL)
    {
        printf("%d, ", aux->valor);
        aux = aux->prox;
    }
    printf("\n-----------------------------INICIO DA FILA\n");
}

int maior(fila *f)
{
    no *aux = f->inicio;
    int maior = aux->valor;
    while (aux != NULL)
    {
        if (maior < aux->valor)
        {
            maior = aux->valor;
        }
        aux = aux->prox;
    }

    return maior;
}

int menor(fila *f)
{
    no *aux = f->inicio;
    int menor = aux->valor;
    while (aux != NULL)
    {
        if (menor > aux->valor)
        {
            menor = aux->valor;
        }
        aux = aux->prox;
    }

    return menor;
}

float media(fila *f)
{
    no *aux = f->inicio;
    int tam = 0;
    float soma = 0, media;
    while (aux != NULL)
    {
        soma = soma + aux->valor;
        aux = aux->prox;
        tam++;
    }

    media = soma / tam;

    return media;
}