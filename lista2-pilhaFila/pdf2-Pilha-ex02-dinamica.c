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
int empilhar(pilha *p, char letra);
int desempilhar(pilha *p, char *letra);
int estaVazia(pilha *p);
// int estaCheia(pilha *p);
void liberarPilha(pilha *p);

void imprimir(pilha *p);

int verificarPalindroma(pilha *p);

int main()
{
    int opcao;
    pilha *p1 = NULL;
    char teste;

    do
    {
        printf("\nEscolha\n[0] Sair\n[1] Criar Pilha\n[2] Empilhar\n[3] Desempilhar\n[4] Liberar Pilha\n[5] Imprimir\n[6] Verificar Palimdromo\n");
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
            printf("Digite uma letra: \n");
            scanf(" %c", &teste);

            if (empilhar(p1, teste))
            {
                printf("\nEmpilhado com sucesso!!!!!\n");
            }
            else
                printf("Falha ao empilhar!!!\n");
            break;

        case 3:
            if (desempilhar(p1, &teste))
            {
                printf("Numero Desempilhado com sucesso [%c]\n", teste);
            }
            else
                printf("Falha ao desempilhar!!!\n");
            break;

        case 4:
            liberarPilha(p1);
            printf("\nPilha liberada com sucesso!!!\n");
            break;

        case 5:
            if (p1 != NULL)
            {
                imprimir(p1);
            }
            else
            {
                printf("Crie uma pilha!!!\n");
            }
            break;

        case 6:
            if (verificarPalindroma(p1))
            {
                printf("\nPalavra Palimdromaaaaa!!!\n");
            }
            else
            {
                printf("\nA Palavra nao eh um palindromo!!!\n");
            }

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
    p1->topo = NULL;
    return p1;
}

int empilhar(pilha *p, char letra)
{
    no *novo;
    novo = (no *)malloc(sizeof(no));
    if (novo != NULL)
    {
        novo->caracter = letra;
        novo->anterior = (*p).topo;
        p->topo = novo;
        return 1;
    }
    else
        return 0;
}

int desempilhar(pilha *p, char *letra)
{
    no *aux;
    if (estaVazia(p) != 0)
    {
        aux = p->topo;
        *letra = aux->caracter;
        p->topo = aux->anterior;
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
        return 1;
}

// int estaCheia(pilha *p);
void liberarPilha(pilha *p)
{
    no *aux;
    aux = p->topo;
    while (aux != NULL)
    {
        p->topo = aux->anterior;
        free(aux);
    }
    free(p);
}

void imprimir(pilha *p)
{
    no *aux;
    aux = p->topo;
    printf("\n----------------- PILHA -----------------\n");
    while (aux != NULL)
    {
        printf(" %c \n", aux->caracter);
        aux = aux->anterior;
    }
    printf("\n----------------- FIM PILHA -----------------\n");
}

int verificarPalindroma(pilha *p)
{
    no *aux = p->topo;
    int tam = 0;
    while (aux != NULL) // verificando o tamanho daa pilha
    {
        tam++;
        aux = aux->anterior;
    }

    char *vetor; // criando um vetor para receber os caracteres da pilha
    int x = 0;
    vetor = (char *)malloc(tam * sizeof(char));
    aux = p->topo;
    while (aux != NULL) // passando a pilha para um vetor
    {
        vetor[x] = aux->caracter;
        aux = aux->anterior;
        x++;
    }

    // vetor[tam + 1] = '\0';
    int y = 0, diferentes = 0;

    while (tam >= y)
    {
        if (vetor[y] != vetor[tam-1])
        {
            diferentes++;
        }
        tam--;
        y++;
    }

    if (diferentes == 0)
    {
        return 1; // palavra palimdromo
    }
    else
        return 0; // palavra NAAOO eh palimdromo
}