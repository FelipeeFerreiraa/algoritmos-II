#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// algo dando errado com as funcoes de pesquisar

typedef struct no
{
    int valor;
    struct no *prox, *ant;
} no;

typedef struct listaDupla
{
    no *inicio;
} listaDupla;

listaDupla *criarLista();
void liberarLista(listaDupla *l);
int estaVazia(listaDupla *l);
// int estaCheia(listaDupla *l);

int inserirInicio(listaDupla *l, int num);
int inserirPosicao(listaDupla *l, int num, int pos);
int inserirFinal(listaDupla *l, int num);

int removerInicio(listaDupla *l, int *num);
int removerPosicao(listaDupla *l, int *num, int pos);
int removerFinal(listaDupla *l, int *num);

int pesquisarPosicao(listaDupla *l, int pos, int *res);
int pesquisarChave(listaDupla *l, int chave, int *res);
int qtdItens(listaDupla *l);
void imprimirLista(listaDupla *l);

int main()
{
    int opcao, num, pos, *res;
    listaDupla *l1 = NULL;

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

            if (pesquisarChave(l1, pos, &res))
            {
                printf("\nNumero informado esta na posicao %d da lista\n", *res);
            }
            else
            {
                printf("\nFalha ao encontrar numero!!\n");
            }

            break;

        case 9:
            printf("Informe qual indice voce deseja pesquisar na lista: \n");
            scanf("%d", &pos);

            if (pesquisarPosicao(l1, pos, &res))
            {
                printf("\nValor na posicao informada: %d\n", *res);
            }

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

    free(res);
    return 0;
}

listaDupla *criarLista()
{
    listaDupla *l1 = (listaDupla *)malloc(sizeof(listaDupla));
    if (l1 != NULL)
        l1->inicio = NULL;
    return l1;
}

void liberarLista(listaDupla *l)
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

int estaVazia(listaDupla *l)
{
    if (l->inicio == NULL)
    {
        return 0;
    }
    else
        return 1;
}

// int estaCheia(listaDupla *l);
int inserirInicio(listaDupla *l, int num)
{
    if (l != NULL)
    {

        no *novo = (no *)malloc(sizeof(no));
        novo->valor = num;
        if (l->inicio == NULL)
        {
            novo->prox = NULL;
            novo->ant = NULL;
            l->inicio = novo;
            return 1;
        }
        else
        {
            l->inicio->ant = novo;
            novo->ant = NULL;
            novo->prox = l->inicio;
            l->inicio = novo;
            return 1;
        }
    }
    else
        return 0;
}

int inserirPosicao(listaDupla *l, int num, int pos)
{
    if (l != NULL)
    {

        no *novo = (no *)malloc(sizeof(no));
        no *aux;
        novo->valor = num;
        int cont = 1;
        aux = l->inicio;

        if (l->inicio == NULL)
        {
            novo->prox = NULL;
            novo->ant = NULL;
            l->inicio = novo;
            return 1;
        }
        else
        {
            while (cont < pos - 1)
            {
                aux = aux->prox;
                cont++;
            }

            novo->prox = aux->prox;
            aux->prox = novo;
            novo->ant = aux->ant;
            return 1;
        }
    }
    else
        return 0;
}

int inserirFinal(listaDupla *l, int num)
{
    if (l != NULL)
    {

        no *novo = (no *)malloc(sizeof(no));
        no *aux = l->inicio;
        novo->valor = num;
        novo->prox = NULL;

        if (l->inicio == NULL)
        {
            novo->ant = NULL;
            l->inicio = novo;
            return 1;
        }
        else
        {
            while (aux->prox != NULL)
            {
                aux = aux->prox;
            }
            aux->prox = novo;
            novo->ant = aux;
            return 1;
        }
    }
    else
        return 0;
}

int removerInicio(listaDupla *l, int *num)
{
    if (l != NULL)
    {
        if (estaVazia(l))
        {
            no *aux = l->inicio;
            *num = aux->valor;
            l->inicio = aux->prox;
            if (aux->prox != NULL)
            {
                aux->prox->ant = NULL;
            }
            free(aux);
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}

int removerPosicao(listaDupla *l, int *num, int pos)
{
    int cont = 1;
    no *ant, *atual = l->inicio;
    if (l != NULL)
    {
        if (estaVazia(l))
        {
            if (pos > 0 && pos < qtdItens(l))
            {
                while (atual != NULL && cont != pos)
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
    else
        return 0;
}

int removerFinal(listaDupla *l, int *num)
{
    if (l != NULL)
    {
        if (estaVazia(l))
        {
            no *aux = l->inicio;
            while (aux->prox != NULL)
            {
                aux = aux->prox;
            }
            if (aux->ant == NULL) // remove primeiro e unico elemento
            {
                *num = aux->valor;
                l->inicio = aux->prox;
            }
            else
            {
                *num = aux->valor;
                aux->ant->prox = NULL;
            }
            free(aux);
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}

int pesquisarPosicao(listaDupla *l, int pos, int *res)
{
    if (l != NULL)
    {
        if (estaVazia(l))
        {
            int cont = 1;
            no *aux = l->inicio;
            while (cont < pos)
            {
                aux = aux->prox;
                cont++;
            }
            *res = aux->valor;
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}

int pesquisarChave(listaDupla *l, int chave, int *res)
{
    if (l != NULL)
    {
        if (estaVazia(l))
        {

            no *aux = l->inicio;
            int cont = 1;
            while (aux != NULL)
            {
                if (aux->valor == chave)
                {
                    *res = cont; // se res == 0, a chave n existe na lista
                }
                aux = aux->prox;
                cont++;
            }

            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}

int qtdItens(listaDupla *l)
{
    if (l != NULL)
    {
        if (estaVazia(l))
        {
            no *aux = l->inicio;
            int qtd = 0;
            while (aux != NULL)
            {
                aux = aux->prox;
                qtd++;
            }

            return qtd;
        }
        else
            return 0;
    }
    else
        return 0;
}

void imprimirLista(listaDupla *l)
{

    no *aux = l->inicio;
    printf("\n----------- LISTA ---------------\n");
    while (aux != NULL)
    {
        printf(" [%d] ", aux->valor);
        aux = aux->prox;
    }
    printf("\n----------- LISTA ---------------\n");
}
