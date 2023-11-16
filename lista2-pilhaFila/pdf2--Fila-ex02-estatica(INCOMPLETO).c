#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

typedef struct fila
{
    int inicio, final;
    int vetor[MAX];
} fila;

fila *criaFila();
void liberarFila(fila *p);
int enfileirar(fila *p, int num);
int desenfileirar(fila *p, int *num);
int estahVazia(fila *p);
int estahCheia(fila *p);
void liberarFila(fila *p);
int tamanhoFila(fila *p);

void peek(fila *p);

int main()
{
    int opcao, numFornecido, numDesenfileirado;

    fila *a;

    do
    {

        printf("Escolha oq deseja fazer: \n[0] Criar uma fila\n[1] Enfileirar elemento\n[2] Desenfileirar elemento\n[3] Verificar ultimo elemento retirado\n[4] Verificar se a fila esta vazia\n[5] Verificar se a fila esta cheia\n[6] Destruir fila\n[7] Verificar elemento do inicio\n[8] Tamanho da fila (qtd de elementos)\n[9] Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            a = criaFila();
            opcao = -1;
            break;

        case 1:
            printf("Digite um numero: ");
            scanf("%d", &numFornecido);
            if (enfileirar(a, numFornecido) == -1)
            {
                printf("Algo deu errado n enfileirou!!\n");
            }
            else
            {
                enfileirar(a, numFornecido);
            }
            opcao = -1;
            break;

        case 2:
            desenfileirar(a, &numDesenfileirado);
            printf("Elemento desenfileirado! (logicamente enfileire outro)\n");
            opcao = -1;
            break;

        case 3:
            if (estahVazia(a) == 1)
            {
                printf("Ultimo elemento retirado = [%d]\n", numDesenfileirado);
            }
            else
            {
                printf("Nenhum elemento retirado!\n");
            }
            opcao = -1;
            break;

        case 4:
            if (estahVazia(a) == -1)
            {
                printf("Fila esta vazia!\n");
            }
            else
            {
                printf("Fila NAO esta vazia!\n");
            }
            opcao = -1;
            break;

        case 5:
            if (estahCheia(a) == 1)
            {
                printf("Fila NAO esta cheia!\n");
            }
            else
            {
                printf("Fila esta cheia!\n");
            }
            opcao = -1;
            break;

        case 6:
            liberarFila(a);
            printf("Memoria alocada Liberada!\n");
            opcao = -1;
            break;

        case 7:
            peek(a);
            opcao = -1;
            break;

        case 8:
            printf("Tamanho da fila/qtd de elementos = %d\n", tamanhoFila(a));
            opcao = -1;
            break;

        case 9:
            break;
        }
    } while (opcao < 0 || opcao > 9);

    return 0;
}

fila *criaFila()
{
    fila *fila1;
    fila1 = (fila *)malloc(MAX * sizeof(fila));
    fila1->inicio = 0;
    fila1->final = 0;
    return fila1;
}

void liberarFila(fila *p)
{
    free(p);
}

int enfileirar(fila *p, int num)
{
    if (estahCheia(p))
    {
        if (p->inicio == 0)
        {
            p->vetor[(*p).final] = num;
            p->vetor[(*p).inicio] = num;

            p->final++;
            p->inicio++;
        }
        else
        {
            p->vetor[(*p).final] = num;
            p->final++;
        }

        return 1; // enfileirou gg
    }
    return 0; // n enfileirou F
}

int desenfileirar(fila *p, int *num)
{
    if (estahVazia(p))
    {
        *num = (*p).vetor[(*p).inicio];

        p->inicio;
        return 1; // desenfileirou gg
    }

    return -1; // n desenfileirou F
}

int estahVazia(fila *p)
{
    if (p->final == 0)
    {
        return 0; // esta vaziia
    }

    return 1; // n esta faziaaaa
}

int estahCheia(fila *p)
{
    if (p->final == MAX)
    {
        return 0; // fila esta cheia
    }
    return 1; // Fila NAO esta cheia
}

void peek(fila *p)
{
    if (estahVazia(p) == 1)
    {
        printf("Elemento do inicio: [%d]\n", (*p).vetor[p->inicio]);
    }
    else
    {
        return -1; // fila vazia
    }
}

int tamanhoFila(fila *p)
{
    if (estahVazia(p) == -1)
    {
        printf("Fila vazia - tamanho = 0");
        return -1;
    }
    else
    {
        return (*p).qtd;
    }
}
