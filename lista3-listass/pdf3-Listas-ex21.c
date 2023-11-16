#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct filme
{
    char nome[50];
} filme;

typedef struct no
{
    struct no *prox, *ant;
    filme colecao; // na colecao eu terei nome dos filmes
} no;

typedef struct listaDupla
{
    no *inicio;
} listaDupla;

listaDupla *criarLista();
void liberarLista(listaDupla *l);
int estaVzia(listaDupla *l);
// int estaCheia(listaDupla *l);
int inserirInicio(listaDupla *l, filme p);
int inserirPosicao(listaDupla *l, filme p, int pos);
int inserirFinal(listaDupla *l, filme p);

int removerInicio(listaDupla *l, filme *p);
int removerPosicao(listaDupla *l, filme *p, int pos);
int removerFinal(listaDupla *l, filme *p);

int pesquisarChave(listaDupla *l, filme p, int *res); // res== resultado
int pesquisarPosicao(listaDupla *l, int pos, filme *p);

int qtdeItens(listaDupla *l);
void imprimirLista(listaDupla *l);

filme inserirFilme(filme p);
void imprimirFilme(filme p);

int inverterOrdem(listaDupla *l);

int main()
{
    // system("color B4");

    int opcao, pos, res;
    listaDupla *l1 = NULL;
    filme p1;

    do
    {
        printf("\nEscolha:\n[0] Sair\n[1] Criar Lista\n[2] Inserir no Final\n[3] Inserir no Inicio\n[4] Informar posicao para inserir\n[5] Remover do final\n[6] Remover do inicio\n[7] Informar posicao para remover\n[8] Pesquisar elemento\n[9] Pesquisar Indice\n[10] Verificar Quantidade de elementos\n[11] Liberar lista\n[12] Imprimir Lista\n[13] Inverter\n");
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
            p1 = inserirFilme(p1);
            if (inserirFinal(l1, p1))
            {
                printf("\nContato inserido com Sucessso!!\n");
            }
            else
            {
                printf("\nFalha ao inserir contato!\n");
            }
            break;

        case 3:
            p1 = inserirFilme(p1);
            if (inserirInicio(l1, p1))
            {
                printf("\nContato inserido com Sucessso!!\n");
            }
            else
            {
                printf("\nFalha ao inserir contato!\n");
            }
            break;

        case 4:
            printf("Informe em qual posicao deseja inserir: \n");
            scanf("%d", &pos);
            p1 = inserirFilme(p1);
            if (inserirPosicao(l1, p1, pos))
            {
                printf("\nContato inserido com Sucessso!!\n");
            }
            else
            {
                printf("\nFalha ao inserir contato!\n");
            }
            break;

        case 5:
            if (removerFinal(l1, &p1))
            {
                printf("\nContato removido com sucesso!!");
                imprimirFilme(p1);
            }
            else
            {
                printf("\nFalha ao remover numero!!\n");
            }
            break;

        case 6:
            if (removerInicio(l1, &p1))
            {
                printf("\nContato removido com sucesso!!");
                imprimirFilme(p1);
            }
            else
            {
                printf("\nFalha ao remover numero!!\n");
            }
            break;

        case 7:
            printf("Informe em qual posicao deseja remover: \n");
            scanf("%d", &pos);

            if (removerPosicao(l1, &p1, pos))
            {
                printf("\nContato removido com sucesso!!");
                imprimirFilme(p1);
            }
            else
            {
                printf("\nFalha ao remover numero!!\n");
            }
            break;

        case 8:
            printf("Informe qual Contato voce deseja pesquisar se tem na lista: \n");
            inserirFilme(p1);

            if (pesquisarChave(l1, p1, &res))
            {
                printf("\nO contato informado esta na posicao %d da lista\n", res);
            }
            else
            {
                printf("\nFalha ao encontrar numero!!\n");
            }

            break;

        case 9:
            printf("Informe qual indice voce deseja pesquisar na lista: \n");
            scanf("%d", &pos);

            if (pesquisarPosicao(l1, pos, &p1))
            {
                printf("\nValor na posicao informada:\n");
                imprimirFilme(p1);
            }

            break;

        case 10:

            printf("\nA lista contem %d contatos\n", qtdeItens(l1));

            break;

        case 11:
            liberarLista(l1);
            printf("\nMemoria liberada!\n");
            break;

        case 12:
            imprimirLista(l1);
            break;

        case 13:
            if (inverterOrdem(l1))
            {
                printf("\nOrdem invertida com sucesso\n");
            }
            else
                printf("\nFalha em inverter ordem!!\n");
            break;

        default:
            printf("\nNumero invalido digite outro!!!\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}

filme inserirFilme(filme p)
{
    printf("\nDigite o nome do filme: ");
    fflush(stdin);
    fgets(p.nome, 50, stdin);
    return p;
}

void imprimirFilme(filme p)
{
    printf("Nome: %s \n", p.nome);
}

listaDupla *criarLista()
{
    listaDupla *l1 = (listaDupla *)malloc(sizeof(listaDupla));
    if (l1 != NULL)
    {

        l1->inicio = NULL;
    }

    return l1;
}

void liberarLista(listaDupla *l)
{
    no *aux = l->inicio;
    while (aux != NULL)
    {
        aux = aux->prox;
        free(aux);
    }
    free(l);
}

int estaVzia(listaDupla *l)
{
    if (l != NULL)
    {
        if (l->inicio != NULL)
        {
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}

// int estaCheia(listaDupla *l);
int inserirInicio(listaDupla *l, filme p)
{
    if (l != NULL)
    {
        if (estaVzia(l))
        {
            no *novo = (no *)malloc(sizeof(no));
            novo->colecao = p;
            no *aux = l->inicio;

            if (l->inicio == NULL)
            {
                l->inicio = novo;
                novo->ant = NULL;
                novo->prox = NULL;
                return 1;
            }
            else
            {
                l->inicio = novo;
                novo->prox = aux;
                novo->ant = NULL;
                return 1;
            }
        }
        else
            return 0;
    }
    else
        return 0;
}

int inserirPosicao(listaDupla *l, filme p, int pos)
{
    if (l != NULL)
    {
        no *novo = (no *)malloc(sizeof(no));
        novo->colecao = p;
        int cont = 1;
        no *aux = l->inicio;
        if (l->inicio == NULL)
        {
            novo->ant = NULL;
            novo->prox = NULL;
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

int inserirFinal(listaDupla *l, filme p)
{
    if (l != NULL)
    {
        no *novo = (no *)malloc(sizeof(no));
        novo->colecao = p;
        novo->prox = NULL;
        no *aux = l->inicio;

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

int removerInicio(listaDupla *l, filme *p)
{
    if (l != NULL)
    {
        if (estaVzia(l))
        {
            no *aux = l->inicio;
            *p = aux->colecao;
            l->inicio = aux->prox;
            l->inicio->ant = NULL;
            free(aux);
            return 1;
        }
        return 0;
    }
    return 0;
}

int removerPosicao(listaDupla *l, filme *p, int pos)
{

    if (l != NULL)
    {
        if (estaVzia(l))
        {
            int cont = 1;
            no *ant, *atual = l->inicio;
            if (pos > 0 && pos < qtdeItens(l))
            {
                while (atual != NULL && cont != pos)
                {
                    ant = atual;
                    atual = atual->prox;
                    cont++;
                }

                ant->prox = atual->prox;
                *p = atual->colecao;
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

int removerFinal(listaDupla *l, filme *p)
{
    if (l != NULL)
    {
        if (estaVzia(l))
        {
            no *aux = l->inicio;
            while (aux->prox != NULL)
            {
                aux = aux->prox;
            }
            if (aux->ant == NULL) // remove primeiro e unico elemento
            {
                *p = aux->colecao;
                l->inicio = aux->prox;
            }
            else
            {
                *p = aux->colecao;
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

int pesquisarChave(listaDupla *l, filme chave, int *res) // res== resultado
{
    if (l != NULL)
    {
        if (estaVzia(l))
        {
            no *aux = l->inicio;
            int cont = 1;
            while (aux != NULL)
            {
                if (aux->colecao.nome == chave.nome)
                {
                    return 1;
                    *res = cont;
                }
                cont++;
                aux = aux->prox;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}

int pesquisarPosicao(listaDupla *l, int pos, filme *p)
{
    if (l != NULL)
    {
        if (estaVzia(l))
        {
            int cont = 1;
            no *aux = l->inicio;
            while (aux != NULL && cont < pos)
            {
                aux = aux->prox;
                cont++;
            }
            *p = aux->colecao;
            return 1;
        }
        return 0;
    }
    return 0;
}

int qtdeItens(listaDupla *l)
{
    if (l != NULL)
    {
        if (estaVzia(l))
        {
            int tam = 0;
            no *aux = l->inicio;
            while (aux != NULL)
            {
                tam++;
                aux = aux->prox;
            }
            return tam;
        }
        return 0;
    }
    return 0;
}

void imprimirLista(listaDupla *l)
{
    no *aux = l->inicio;

    printf("\n============== LISTA ==============\n");
    while (aux != NULL)
    {
        printf("\n////Nome do Filme: %s.\n\n  ", aux->colecao.nome);
        aux = aux->prox;
    }
    printf("\n============== LISTA ==============\n");
}

int inverterOrdem(listaDupla *l)
{
    if (l != NULL)
    {

        no *ant, *seg, *atual;
        
        atual = l->inicio;
        seg = NULL;
        ant = NULL;

        while (atual != NULL)
        {
            seg = atual->prox;

            // inverte os ponteiros
            atual->prox = ant;
            atual->ant = seg;

            ant = atual;
            atual = seg;
        }

        l->inicio = ant;

        // vou arrumar o erro e volto dps com o resultadooooo

        return 1;
    }
    else
        return 0;
}
