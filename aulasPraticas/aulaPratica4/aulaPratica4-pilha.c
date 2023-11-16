#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct pilha
{
    int vetor[MAX];
    int topo;
} pilha;

pilha *criaPilha();
void liberarPilha(pilha *p);
int empilha(pilha *p, int num);
int desempilha(pilha *p, int *num);
int estahVazia(pilha *p);
int estahCheia(pilha *p);

void peek(pilha *p);

int main()
{
    int opcao, numFornecido, numDesempilhado;
    ;
    pilha *a;

    do
    {

        printf("Escolha oq deseja fazer: \n[0] Criar uma pilha\n[1] Empilhar elemento\n[2] Desempilhar elemento\n[3] Verificar se a pilha esta vazia\n[4] Verificar se a pilha esta cheia\n[5] Destruir pilha\n[6] Verificar elemento do topo\n[7] Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            a = criaPilha();
            opcao = -1;
            break;

        case 1:
            printf("Digite um numero: ");
            scanf("%d", &numFornecido);
            if (empilha(a, numFornecido) == -1)
            {
                printf("Algo deu errado n empilhou!!\n");
            }
            else
            {
                empilha(a, numFornecido);
            }
            opcao = -1;
            break;

        case 2:
            desempilha(a, &numDesempilhado);
            printf("Elemento desempilhado! (logicamente empilhe outro)\n");
            opcao = -1;
            break;

        case 3:
            if (estahVazia(a) == -1)
            {
                printf("Pilha esta vazia!\n");
            }
            else
            {
                printf("Pilha NAO esta vazia!\n");
            }
            opcao = -1;
            break;

        case 4:
            if (estahCheia(a) == 1)
            {
                printf("Pilha NAO esta cheia!\n");
            }
            else
            {
                printf("Pilha esta cheia!\n");
            }
            opcao = -1;
            break;

        case 5:
            liberarPilha(a);
            printf("Memoria alocada Liberada!\n");
            opcao = -1;
            break;

        case 6:
            peek(a);
            opcao = -1;
            break;

        case 7:
            break;
        }
    } while (opcao < 0 || opcao > 7);

    /*
    empilha(a, 20);
    empilha(a, 210);
    empilha(a, 2230);
    empilha(a, 48210);

    int numDesempilhado;
    desempilha(a, &numDesempilhado);
    desempilha(a, &numDesempilhado);
    if (desempilha(a, &numDesempilhado) == -1) {
      printf("Erro ao desempilhar!!!");
    } */

    // peek(a);

    return 0;
}

pilha *criaPilha()
{

    pilha *a;

    a = (pilha *)malloc(MAX * sizeof(pilha));
    a->topo = 0;

    return a;
}

void liberarPilha(pilha *p)
{
    free(p);
}

int empilha(pilha *p, int num)
{
    if (estahCheia(p) == 1)
    {
        p->vetor[(*p).topo] = num;
        p->topo++;
        return 1; // empilhou gg
    }
    return -1; // n empilhou F
}

int desempilha(pilha *p, int *num)
{
    if (estahVazia(p) == 1)
    {
        *num = (*p).vetor[(*p).topo];
        (*p).topo--;
        return 1; // desempilhado gg
    }

    return -1; // n desempilhou F
}

int estahVazia(pilha *p)
{
    if (p->topo == 0)
    {
        return -1; // esta vaziia
    }

    return 1; // n esta faziaaaa
}

int estahCheia(pilha *p)
{
    if (p->topo < MAX)
    {
        return 1; // pilha n esta cheia
    }
    return -1;
}

void peek(pilha *p)
{
    printf("Elemento no topo: [%d]\n", (*p).vetor[p->topo -1]);
}