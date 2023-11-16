#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct produto
{
    int codProd, qtdeEstoque;
    char nomeProd[10];
    float valor;
} produto;

typedef struct no
{
    struct no *prox, *ant;
    produto armazen; // no armazen eu terei produtos com: cod,nome,valor,qtd
} no;

typedef struct listaDupla
{
    no *inicio;
} listaDupla;

listaDupla *criarLista();
void liberarLista(listaDupla *l);
int estaVzia(listaDupla *l);
// int estaCheia(listaDupla *l);
int inserirInicio(listaDupla *l, produto p);
int inserirPosicao(listaDupla *l, produto p, int pos);
int inserirFinal(listaDupla *l, produto p);

int removerInicio(listaDupla *l, produto *p);
int removerPosicao(listaDupla *l, produto *p, int pos);
int removerFinal(listaDupla *l, produto *p);

int pesquisarChave(listaDupla *l, produto p, int *res); // res== resultado
int pesquisarPosicao(listaDupla *l, int pos, produto *p);

int qtdeItens(listaDupla *l);
void imprimirLista(listaDupla *l);

produto inserirProduto(produto p);
void imprimirProduto(produto p);

int main()
{
    // system("color B4");

    int opcao, pos, res;
    listaDupla *l1 = NULL;
    produto p1;

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
            p1 = inserirProduto(p1);
            if (inserirFinal(l1, p1))
            {
                printf("\nproduto inserido com Sucessso!!\n");
            }
            else
            {
                printf("\nFalha ao inserir produto!\n");
            }
            break;

        case 3:
            p1 = inserirProduto(p1);
            if (inserirInicio(l1, p1))
            {
                printf("\nproduto inserido com Sucessso!!\n");
            }
            else
            {
                printf("\nFalha ao inserir produto!\n");
            }
            break;

        case 4:
            printf("Informe em qual posicao deseja inserir: \n");
            scanf("%d", &pos);
            p1 = inserirProduto(p1);
            if (inserirPosicao(l1, p1, pos))
            {
                printf("\nproduto inserido com Sucessso!!\n");
            }
            else
            {
                printf("\nFalha ao inserir produto!\n");
            }
            break;

        case 5:
            if (removerFinal(l1, &p1))
            {
                printf("\nProduto removido com sucesso!!");
                imprimirProduto(p1);
            }
            else
            {
                printf("\nFalha ao remover numero!!\n");
            }
            break;

        case 6:
            if (removerInicio(l1, &p1))
            {
                printf("\nProduto removido com sucesso!!");
                imprimirProduto(p1);
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
                printf("\nProduto removido com sucesso!!");
                imprimirProduto(p1);
            }
            else
            {
                printf("\nFalha ao remover numero!!\n");
            }
            break;

        case 8:
            printf("Informe qual produto voce deseja pesquisar se tem na lista: \n");
            inserirProduto(p1);

            if (pesquisarChave(l1, p1, &res))
            {
                printf("\nO produto informado esta na posicao %d da lista\n", res);
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
                imprimirProduto(p1);
            }

            break;

        case 10:

            printf("\nA lista contem %d produtos\n", qtdeItens(l1));

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

produto inserirProduto(produto p)
{
    printf("\nDigite o codigo do produto: ");
    scanf("%d", &p.codProd);
    printf("\nDigite o nome do produto: (10letras)");
    fflush(stdin);
    fgets(p.nomeProd, 10, stdin);
    printf("\nDigite o valor do produto: ");
    scanf("%f", &p.valor);
    printf("\nForneca a quantidade de itens no estoque: ");
    scanf("%d", &p.qtdeEstoque);
    return p;
}

void imprimirProduto(produto p)
{
    printf("Codigo: %d \n", p.codProd);
    printf("Nome: %s \n", p.nomeProd);
    printf("Valor: %.2f \n", p.valor);
    printf("Estoque: %d \n\n", p.qtdeEstoque);
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
int inserirInicio(listaDupla *l, produto p)
{
    if (l != NULL)
    {
        if (estaVzia(l))
        {
            no *novo = (no *)malloc(sizeof(no));
            novo->armazen = p;
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

int inserirPosicao(listaDupla *l, produto p, int pos)
{
    if (l != NULL)
    {
        no *novo = (no *)malloc(sizeof(no));
        novo->armazen = p;
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

int inserirFinal(listaDupla *l, produto p)
{
    if (l != NULL)
    {
        no *novo = (no *)malloc(sizeof(no));
        novo->armazen = p;
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

int removerInicio(listaDupla *l, produto *p)
{
    if (l != NULL)
    {
        if (estaVzia(l))
        {
            no *aux = l->inicio;
            *p = aux->armazen;
            l->inicio = aux->prox;
            l->inicio->ant = NULL;
            free(aux);
            return 1;
        }
        return 0;
    }
    return 0;
}

int removerPosicao(listaDupla *l, produto *p, int pos)
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
                *p = atual->armazen;
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

int removerFinal(listaDupla *l, produto *p)
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
                *p = aux->armazen;
                l->inicio = aux->prox;
            }
            else
            {
                *p = aux->armazen;
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

int pesquisarChave(listaDupla *l, produto chave, int *res) // res== resultado
{
    if (l != NULL)
    {
        if (estaVzia(l))
        {
            no *aux = l->inicio;
            int cont = 1;
            while (aux != NULL)
            {
                if (aux->armazen.codProd == chave.codProd)
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

int pesquisarPosicao(listaDupla *l, int pos, produto *p)
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
            *p = aux->armazen;
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
        printf("\n////Codigo do produto: [%d]\nNome do produto: %s.\nValor do produto: %.2f.\nQuantidade no estoque: %d.////\n\n  ", aux->armazen.codProd, aux->armazen.nomeProd, aux->armazen.valor, aux->armazen.qtdeEstoque);
        aux = aux->prox;
    }
    printf("\n============== LISTA ==============\n");
}
