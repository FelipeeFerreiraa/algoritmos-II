#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5

typedef struct fila
{
    int vetor[MAX], inicio, final, qtd;
} fila;

fila *criarFila();
void liberarFila(fila *f);
int enfileirar(fila *f, int num);
int desenfileirar(fila *f, int *num);
int estaVazia(fila *f);
int estaCheia(fila *f);
void imprimirFila(fila *f);

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
                printf("\nFalha ao enfileirar!!!\n");
            }

            break;
        case 3:
            if (desenfileirar(f1, &num))
            {
                printf("\nNumero Desenfileirado com sucesso [%d]\n\n", num);
            }
            else
                printf("\nFalha ao Desenfileirar!!!\n");
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

        default:
            break;
        }
    } while (opcao != 0);

    return 0;
}

fila *criarFila()
{
    fila *f1;
    f1 = (fila *)malloc(MAX * sizeof(fila));
    if (f1 != NULL)
    {
        f1->qtd = 0;
        f1->final = 0;
        f1->inicio = 0;
    }
    return f1;
}

void liberarFila(fila *f)
{
    free(f);
}

int enfileirar(fila *f, int num)
{
    if (estaCheia(f))
    {
        f->final = f->final % MAX;
        f->vetor[f->final] = num;
        f->final++;
        f->qtd++;
        return 1;
    }
    else
        return 0;
}

int desenfileirar(fila *f, int *num)
{
    if (estaVazia(f))
    {
        *num = (*f).vetor[f->inicio];
        f->inicio++;
        f->inicio = f->inicio % MAX;
        f->qtd--;
        return 1;
    }
    else
        return 0;
}

int estaVazia(fila *f)
{
    if (f->qtd == 0)
    {
        return 0; // esta vaziaaa!
    }
    else
        return 1;
}

int estaCheia(fila *f)
{
    if (f->qtd == MAX)
    {
        return 0; // esta cheia!
    }
    else
        return 1;
}

void imprimirFila(fila *f)
{
    int aux;
    aux = 0;

    printf("\nINICIO DA FILA-----------------------------\n");
    while (aux < 5)
    {
        printf("%d, ", f->vetor[aux]);
        aux++;
    }
    printf("\n-----------------------------FIM DA FILA\n");
}
