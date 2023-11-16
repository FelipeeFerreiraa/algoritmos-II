#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// funcao liberar esta com algo erradoooo

typedef struct no
{
    int valor;
    struct no *anterior;
} no;

typedef struct pilha
{
    no *topo;
} pilha;

pilha *criarPilha();
int empilhar(pilha *p, int num);
int desempilhar(pilha *p, int *num);
int estahVazia(pilha *p);
// int estaCheia();  nao precisaaaaaaa
void liberar(pilha *p);

void imprimirPilha(pilha *p);

int maior(pilha *p);
int menor(pilha *p);
float media(pilha *p);

int main()
{

    int opcao, num;
    pilha *p1 = NULL;

    do
    {
        printf("\nEscolha\n[0] Sair\n[1] Criar Pilha\n[2] Empilhar\n[3] Desempilhar\n[4] Liberar Pilha\n[5] Imprimir\n[6] Maior Valor\n[7] Menor Valor\n[8] Media dos Valores\n");
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
            printf("Digite um numero: \n");
            scanf("%d", &num);

            if (empilhar(p1, num))
            {
                printf("\nEmpilhado com sucesso!!!!!\n");
            }
            else
                printf("Falha ao empilhar!!!\n");
            break;

        case 3:
            if (desempilhar(p1, &num))
            {
                printf("Numero Desempilhado com sucesso [%d]\n", num);
            }
            else
                printf("Falha ao desempilhar!!!\n");
            break;

        case 4:
            liberar(p1);
            printf("\nPilha liberada com sucesso!!!\n");
            break;

        case 5:
            if (p1 != NULL)
            {
                imprimirPilha(p1);
            }
            else
            {
                printf("Crie uma pilha!!!\n");
            }
            break;

        case 6:
            printf("\nMaior valor da Pilha = [%d]\n", maior(p1));
            break;

        case 7:
            printf("\nMenor valor da Pilha = [%d]\n", menor(p1));
            break;

        case 8:
            printf("\nMedia dos valores da Pilhaa = [%.2f]\n", media(p1));
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
    p1->topo = NULL;

    return p1;
}

int empilhar(pilha *p, int num)
{
    no *novo;
    novo = (no *)malloc(sizeof(no));
    if (novo != NULL)
    {
        novo->valor = num;
        novo->anterior = p->topo;
        p->topo = novo;
        return 1;
    }
    else
        printf("Falha na alocacao de memoria!!!\n");
    return 0;
}

int desempilhar(pilha *p, int *num)
{
    if (estahVazia(p))
    {
        no *aux;
        aux = p->topo;
        *num = aux->valor;
        p->topo = aux->anterior;
        free(aux);
        return 1;
    }
    else
        printf("Pilha vaziaaa!!\n");
    return 0;
}

int estahVazia(pilha *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
        return 1; // pilha NAO esta vazia
}

void liberar(pilha *p)
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

void imprimirPilha(pilha *p)
{

    printf("----------- Pilha -------------\n");
    no *aux = p->topo;

    while (aux != NULL)
    {
        printf(" [%d]\n", aux->valor);
        aux = aux->anterior;
    }

    printf("----------- Fim Pilha -------------\n");
}

int maior(pilha *p)
{
    no *aux = p->topo;
    int maior = aux->valor;
    while (aux != NULL)
    {
        if (maior < aux->valor)
        {
            maior = aux->valor;
        }
        aux = aux->anterior;
    }

    return maior;
}

int menor(pilha *p)
{
    no *aux = p->topo;
    int menor = aux->valor;
    while (aux != NULL)
    {
        if (menor > aux->valor)
        {
            menor = aux->valor;
        }
        aux = aux->anterior;
    }

    return menor;
}

float media(pilha *p)
{
    no *aux = p->topo;
    int soma = 0, media, qtd = 0;

    while (aux != NULL)
    {
        soma = soma + aux->valor;
        aux = aux->anterior;
        qtd++;
    }
    media = soma / qtd;

    return media;
}