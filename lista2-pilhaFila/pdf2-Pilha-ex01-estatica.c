#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct pilha
{
    char txt[MAX];
    int topo;
} pilha;

pilha *criaPilha();
void liberarPilha(pilha *a);
void empilhar(pilha *a, char *letra);
void desempilhar(pilha *a, char *num);
int estahVazia(pilha *a);
int estahCheia(pilha *a);

void inverte(pilha *p, char *a);

void peek(pilha *a);

int main()
{

    char frase[50] = "ESTE EXERCICIO E MUITO FACIL \0";

    int opcao;
    pilha *p1 = NULL;

    do
    {
        printf("\nEscolha\n[0] Sair\n[1] Criar Pilha\n[2] Inverter\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            break;

        case 1:
            p1 = criaPilha();
            printf("\nPilha Criada com sucessssoo!!\n");
            break;

        case 2:
            inverte(p1, frase);
            break;

        default:
            break;
        }
    } while (opcao != 0);

    return 0;
}

pilha *criaPilha()
{
    pilha *p1;
    p1 = (pilha *)malloc(sizeof(pilha));
    p1->topo = 0;

    return p1;
}

void liberarPilha(pilha *a)
{
    free(a);
}

void empilhar(pilha *a, char *letra)
{
    int x = 0;
    a->txt[a->topo] = letra[x];
    a->topo++;
}
void desempilhar(pilha *a, char *num)
{
    *num = a->txt[a->topo - 1];
    a->topo--;
}

int estahVazia(pilha *a)
{
    if ((*a).topo == 0)
        return 0;
    else
        return 1;
}

int estahCheia(pilha *a)
{
    if ((*a).topo == MAX)
        return 0;
    else
        return 1;
}

void inverte(pilha *p, char *a)
{
    int x = 0;
    char teste;

    while (a[x] != '\0')
    {
        if (a[x] != ' ')
        {
            empilhar(p, &a[x]);
        }
        else
        {
            while (estahVazia(p) == 0)
            {
                desempilhar(p, &teste);
                printf(" %c", teste);
            }
            printf(" ");
        }
        x++;
    }
    while (estahVazia(p) == 0)
    {
        desempilhar(p, &teste);
        printf(" %c", teste);
    }
    printf(".\n");
}

void peek(pilha *a);