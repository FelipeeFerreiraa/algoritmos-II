#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void liberarLista(lista *l);
// int estaCheia(lista *l1);
int estaVazia(lista *l);

int inserirInicio(lista *l, int num);
int inserirPosicao(lista *l, int num, int pos);
int inserirFinal(lista *l, int num);

int removerInicio(lista *l, int *num);
int removerPosicao(lista *l, int *num, int pos);
int removerFinal(lista *l, int *num);

int pesquisarChave(lista *l, int chave);
void pesquisarPosicao(lista *l, int pos);
int qtdItens(lista *l);
void imprimirLista(lista *l);

int main()
{
    int opcao, num, pos;
    lista *l1;

    do
    {
        printf("\nEscolha:\n[0] Sair\n[1] Criar Lista\n[2] Inserir no Final\n[3] Inserir no Inicio\n[4] Informar posicao para inserir\n[5] Remover do final\n[6] Remover do inicio\n[7] Informar posicao para remover\n[8] Pesquisar elemento\n[9] Pesquisar Indice\n[10] Verificar Quantidade de elementos\n[11] Liberar lista\n[12] Imprimir Lista\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            break;

        case 1:
            l1 = criarLista();
            printf("\nLista Criada Com Sucessssso!\n");
            break;

        case 2:
            printf("Digite um numero: \n");
            scanf("%d", &num);
            if (inserirFinal(l1, num))
            {
                printf("\n\nNumero inserido com Sucessso!!\n");
            }
            else
            {
                printf("\nFalha ao inserir numero!\n");
            }
            break;

        case 3:
            printf("Digite um numero: \n");
            scanf("%d", &num);
            if (inserirInicio(l1, num))
            {
                printf("\n\nNumero inserido com Sucessso!!\n");
            }
            else
            {
                printf("\nFalha ao inserir numero!\n");
            }
            break;

        case 4:
            printf("Informe em qual posicao deseja inserir: \n");
            scanf("%d", &pos);
            printf("Digite um numero: \n");
            scanf("%d", &num);
            if (inserirPosicao(l1, num, pos))
            {
                printf("\n\nNumero inserido com Sucessso!!\n");
            }
            else
            {
                printf("\nFalha ao inserir numero!\n");
            }
            break;

        case 5:
            if (removerFinal(l1, &num))
            {
                printf("\nNumero removido com sucesso!! [%d]\n", num);
            }
            else
            {
                printf("\nFalha ao remover numero!!\n");
            }
            break;

        case 6:
            if (removerInicio(l1, &num))
            {
                printf("\nNumero removido com sucesso!! [%d]\n", num);
            }
            else
            {
                printf("\nFalha ao remover numero!!\n");
            }
            break;

        case 7:
            printf("Informe em qual posicao deseja remover: \n");
            scanf("%d", &pos);

            if (removerPosicao(l1, &num, pos))
            {
                printf("\nNumero removido com sucesso!! [%d]\n", num);
            }
            else
            {
                printf("\nFalha ao remover numero!!\n");
            }
            break;

        case 8:
            printf("Informe qual elemento voce deseja pesquisar se tem na lista: \n");
            scanf("%d", &pos);

            if (pesquisarChave(l1, pos))
            {
                printf("\nNumero informado esta na lista\n");
            }
            else
            {
                printf("\nFalha ao encontrar numero!!\n");
            }

            break;

        case 9:
            printf("Informe qual indice voce deseja pesquisar na lista: \n");
            scanf("%d", &pos);

            pesquisarPosicao(l1, pos);

            break;

        case 10:

            printf("\nA lista contem %d elementos\n", qtdItens(l1));

            break;

        case 11:
            liberarLista(l1);
            printf("\nMemoria liberada!\n");
            break;

        case 12:
            imprimirLista(l1);
            break;

        default:
            printf("\nNumero invalido digite outro!!!\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}

lista *criarLista()
{
    lista *l1;
    l1 = (lista *)malloc(sizeof(lista));
    l1->inicio = NULL;
    return l1;
}

void liberarLista(lista *l)
{
    no *aux;

    while (l->inicio != NULL)
    {
        aux = l->inicio;
        l->inicio = aux->prox;
        free(aux);
    }
    free(l);
}

// int estaCheia(lista *l1);
int estaVazia(lista *l)
{
    if (l->inicio == NULL)
    {
        return 0;
    }
    else
        return 1;
}

int inserirInicio(lista *l, int num)
{
    no *novo;
    novo = (no *)malloc(sizeof(no));

    if (l != NULL)
    {
        if (novo != NULL)
        {
            novo->valor = num;
            novo->prox = NULL;
            if (l->inicio == NULL)
            {
                l->inicio = novo;
                return 1;
            }
            else
            {
                novo->prox = l->inicio;
                l->inicio = novo;
                return 1;
            }
        }
        else
            return 0;
    }
    else
        return 0;
}

int inserirPosicao(lista *l, int num, int pos)
{
    if (l != NULL)
    {
        if (pos <= qtdItens(l) + 1 && pos > 0) // verificando posicao valida
        {
            int cont = 1;
            no *aux = l->inicio;
            no *novo = (no *)malloc(sizeof(no));

            novo->valor = num;

            if (l->inicio == NULL)
            {
                novo->prox = NULL;
                l->inicio = novo;
                return 1;
            }
            while (cont != (pos - 1))
            {
                cont++;
                aux = aux->prox;
            }

            novo->prox = aux->prox;
            aux->prox = novo;
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}

int inserirFinal(lista *l, int num)
{
    if (l != NULL)
    {
        no *novo;
        novo = (no *)malloc(sizeof(no));
        novo->valor = num;
        novo->prox = NULL;
        no *aux = l->inicio;

        if (l->inicio == NULL)
        {
            l->inicio = novo;
            return 1;
        }
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;

        return 1;
    }
    else
        return 0;
}

int removerInicio(lista *l, int *num)
{
    if (l != NULL)
    {
        if (estaVazia(l))
        {
            no *aux = l->inicio;
            *num = aux->valor;
            l->inicio = aux->prox;
            free(aux);
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}

int removerPosicao(lista *l, int *num, int pos)
{
    if (l != NULL)
    {
        if (estaVazia(l))
        {
            no *ant, *atual = l->inicio;
            int cont = 1;

            while (cont != pos && atual != NULL)
            {
                ant = atual;
                atual = atual->prox;
                cont++;
            }
            ant->prox = atual->prox;
            *num = atual->valor;
            free(atual);
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}

int removerFinal(lista *l, int *num)
{
    if (l != NULL)
    {
        if (estaVazia(l))
        {
            no *ant, *atual = l->inicio;

            while (atual->prox != NULL)
            {
                ant = atual;
                atual = atual->prox;
            }

            if (atual == l->inicio)
            {
                *num = atual->valor;
                l->inicio = atual->prox;
                return 1;
            }
            else
            {
                ant->prox = atual->prox;
                *num = atual->valor;
                free(atual);
                return 1;
            }
        }
        else
            return 0;
    }
    else
        return 0;
}

int pesquisarChave(lista *l, int chave)
{
    if (l != NULL)
    {
        no *aux;
        aux = l->inicio;
        while (aux != NULL)
        {
            if (aux->valor == chave)
            {
                return 1; // chave esta na lista
            }
            aux = aux->prox;
        }
    }
    else
        return 0;
}

void pesquisarPosicao(lista *l, int pos)
{
    no *aux = l->inicio;
    int cont = 1;
    if (pos <= qtdItens(l) && pos > 0)
    {
        while (aux != NULL)
        {
            if (pos == cont)
            {
                printf("\nValor na posicao informada: %d\n", aux->valor);
            }
            cont++;
            aux = aux->prox;
        }
    }
    else
    {
        printf("\nPosicao invalida!\n");
    }
}

int qtdItens(lista *l)
{
    int tam = 0;
    no *aux = l->inicio;
    if (estaVazia(l))
    {
        while (aux != NULL)
        {
            tam++;
            aux = aux->prox;
        }
        return tam;
    }
    else
        return 0;
}

void imprimirLista(lista *l)
{
    no *aux;
    aux = l->inicio;

    printf("\n========== LISTA ================\n");
    while (aux != NULL)
    {
        printf("%d, ", aux->valor);
        aux = aux->prox;
    }
    printf("\n========== LISTA ================\n");
}