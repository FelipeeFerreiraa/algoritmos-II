#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *prox;

} no;

typedef struct lista
{
    no *inicio;
} lista;

lista *criarLista();
int inserirOrdenado(lista *l, int num);
int removerInicio(lista *l, int *num);

void liberarLista(lista *l);
void imprimirLista(lista *l);

int inverterLista(lista *l);

int main()
{
    int escolha;
    int num;
    lista *l000;
    do
    {

        printf("\nEscolha: \n[0] Sair\n[1] Criar Lista\n[2] Inserir\n[3] Remover\n[4] Liberar Lista\n[5] Imprimir lista\n[6] Inverter Lista\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 0:

            break;

        case 1:
            l000 = criarLista();
            printf("\nLista Criadaaaa!\n");
            break;

        case 2:
            printf("Digite um numero: \n");
            scanf("%d", &num);
            if (inserirOrdenado(l000, num))
            {
                printf("\nNumero inserido com sucesso!!\n");
            }
            else
            {
                printf("\nFalha ao inserir!!\n");
            }
            break;

        case 3:
            if (removerInicio(l000, &num))
            {
                printf("\nNumero removido com sucesso!!! [%d]  \n", num);
            }
            else
            {
                printf("\nFalha ao remover!!\n");
            }

            break;

        case 4:
            liberarLista(l000);
            printf("\nLista liberada\n");
            break;

        case 5:
            imprimirLista(l000);
            break;

        case 6:
            if (inverterLista(l000))
            {
                printf("\nOrdem invertida com sucesso\n");
            }
            else
                printf("\nFalha em inverter ordem!!\n");
            break;

        default:
            break;
        }
    } while (escolha != 0);

    return 0;
}

lista *criarLista()
{
    lista *l1 = (lista *)malloc(sizeof(lista));
    if (l1 != NULL)
    {
        l1->inicio = NULL;
    }

    return l1;
}

int inserirOrdenado(lista *l, int num)
{
    if (l != NULL)
    {
        no *novo = (no *)malloc(sizeof(no));
        novo->valor = num;

        if (l->inicio == NULL)
        {
            novo->prox = NULL;
            l->inicio = novo;
            return 1;
        }
        else
        {
            no *atual = l->inicio, *ant;
            while (atual != NULL && atual->valor < novo->valor)
            {
                ant = atual;
                atual = atual->prox;
            }
            if (atual == l->inicio)
            {
                novo->prox = l->inicio;
                l->inicio = novo;
            }
            else
            {
                novo->prox = ant->prox;
                ant->prox = novo;
            }
            return 1;
        }
    }
    else
        return 0;
}

int removerInicio(lista *l, int *num)
{
    if (l != NULL)
    {
        if (l->inicio != NULL)
        {
            no *aux = l->inicio;
            *num = aux->valor;
            l->inicio = aux->prox;
            free(aux);
            return 1;
        }
        else if (l->inicio == NULL)
        {
            return 0;
        }
    }

    return 0;
}

void liberarLista(lista *l)
{
    if (l != NULL)
    {
        while (l != NULL)
        {
            no *aux = l->inicio;
            l->inicio = aux->prox;
            free(aux);
        }
        free(l);
    }
}

void imprimirLista(lista *l)
{
    no *aux = l->inicio;

    printf("\n========= LISTA =============\n");
    while (aux != NULL)
    {
        printf("[%d]  ", aux->valor);
        aux = aux->prox;
    }
    printf("\n========= LISTA =============\n");
}

int inverterLista(lista *l)
{
    if (l != NULL)
    {
        no *atual = l->inicio, *ant = NULL, *seg = NULL;

        while (atual != NULL)
        {
            seg = atual->prox;
            atual->prox = ant; // inversao
            ant = atual;
            atual = seg;
        }

        l->inicio = ant;

        imprimirLista(l);
        return 1;
    }
    else
        return 0;
}