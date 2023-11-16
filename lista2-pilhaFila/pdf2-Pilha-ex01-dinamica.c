#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no
{
    char caracter;
    struct no *anterior;
} no;

typedef struct pilha
{
    no *topo;
} pilha;

pilha *criarPilha();
void empilhar(pilha *p, char num);
void desempilhar(pilha *p, char *num);
int estaVazia(pilha *p);
// int estaCheia(pilha *p); NAO PRECISAAA
void liberarPilha(pilha *p);
void imprimirPilha(pilha *p); // teste

void inverterPalavras(pilha *p, char *letra);

int main()
{
    // char frase[50] = "ESTE EXERCICIO E MUITO FACIL";

    char frase[50] = "Felipe Ferreira Domingues";

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
            p1 = criarPilha();
            printf("\nPilha Criada com sucessssoo!!\n");
            break;

        case 2:
            inverterPalavras(p1, frase);
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
    {
        p1->topo = NULL;
        return p1;
    }
    else
        printf("\nFalha ao alocar memoria para a Pilha!\n");
    return NULL;
}

void empilhar(pilha *p, char num)
{
    no *novo;
    novo = (no *)malloc(sizeof(no));
    if (novo != NULL)
    {
        novo->caracter = num;
        novo->anterior = p->topo;
        p->topo = novo;
    }
}

void desempilhar(pilha *p, char *num)
{
    no *aux;

    if (estaVazia(p))
    {
        aux = p->topo;
        *num = aux->caracter;
        p->topo = aux->anterior;
    }
    free(aux);
}

int estaVazia(pilha *p)
{
    if (p->topo == 0)
    {
        return 0; // pilha Vazia
    }
    else
        return 1; // pilha NAAOO esta Vazia
}

// int estaCheia(pilha *p); NAO PRECISAAA
void liberarPilha(pilha *p);

void imprimirPilha(pilha *p) // teste
{
    no *aux;
    aux = p->topo;

    printf("\n---------- PILHA --------------\n");
    while (aux != NULL)
    {
        printf("[ %c ]\n", aux->caracter);
        aux = aux->anterior;
    }
    printf("\n---------- FIM PILHA --------------\n");
}

void inverterPalavras(pilha *p, char *letra) // ESTE EXERCICIO E MUITO FACIL.
{
    int x = 0;
    char teste;

    while (letra[x] != '\0')
    {
        if (letra[x] != ' ')
        {
            empilhar(p, letra[x]);
        }
        else
        {
            while (estaVazia(p) != 0)
            {
                desempilhar(p, &teste);
                printf("%c", teste);
            }
            printf(" ");
        }
        x++;
    }

    while (estaVazia(p) != 0)
    {
        desempilhar(p, &teste);
        printf("%c", teste);
    }
    printf(".\n");
}