#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct agenda
{
    int num;
    char nome[30], email[50];
} agenda;

typedef struct no
{
    struct no *prox, *ant;
    agenda contato; // no contato eu terei numero ,nome,emaiil
} no;

typedef struct listaDupla
{
    no *inicio;
} listaDupla;

listaDupla *criarLista();
void liberarLista(listaDupla *l);
int estaVzia(listaDupla *l);
// int estaCheia(listaDupla *l);
int inserirInicio(listaDupla *l, agenda p);
int inserirPosicao(listaDupla *l, agenda p, int pos);
int inserirFinal(listaDupla *l, agenda p);

int removerInicio(listaDupla *l, agenda *p);
int removerPosicao(listaDupla *l, agenda *p, int pos);
int removerFinal(listaDupla *l, agenda *p);

int pesquisarChave(listaDupla *l, agenda p, int *res); // res== resultado
int pesquisarPosicao(listaDupla *l, int pos, agenda *p);

int qtdeItens(listaDupla *l);
void imprimirLista(listaDupla *l);

agenda inserirContato(agenda p);
void imprimirContato(agenda p);

int main()
{
    // system("color B4");

    int opcao, pos, res;
    listaDupla *l1 = NULL;
    agenda p1;

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
            p1 = inserirContato(p1);
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
            p1 = inserirContato(p1);
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
            p1 = inserirContato(p1);
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
                imprimirContato(p1);
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
                imprimirContato(p1);
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
                imprimirContato(p1);
            }
            else
            {
                printf("\nFalha ao remover numero!!\n");
            }
            break;

        case 8:
            printf("Informe qual Contato voce deseja pesquisar se tem na lista: \n");
            inserirContato(p1);

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
                imprimirContato(p1);
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

        default:
            printf("\nNumero invalido digite outro!!!\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}

agenda inserirContato(agenda p)
{
    printf("\nDigite o Numero do contato: ");
    scanf("%d", &p.num);
    printf("\nDigite o nome do contato: (30letras)");
    fflush(stdin);
    fgets(p.nome, 30, stdin);
    printf("\nDigite o Email do contato: ");
    fflush(stdin);
    fgets(p.email, 50, stdin);
    return p;
}

void imprimirContato(agenda p)
{
    printf("Numero: %d \n", p.num);
    printf("Nome: %s \n", p.nome);
    printf("Email: %s \n", p.email);
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
int inserirInicio(listaDupla *l, agenda p)
{
    if (l != NULL)
    {
        if (estaVzia(l))
        {
            no *novo = (no *)malloc(sizeof(no));
            novo->contato = p;
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

int inserirPosicao(listaDupla *l, agenda p, int pos)
{
    if (l != NULL)
    {
        no *novo = (no *)malloc(sizeof(no));
        novo->contato = p;
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

int inserirFinal(listaDupla *l, agenda p)
{
    if (l != NULL)
    {
        no *novo = (no *)malloc(sizeof(no));
        novo->contato = p;
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

int removerInicio(listaDupla *l, agenda *p)
{
    if (l != NULL)
    {
        if (estaVzia(l))
        {
            no *aux = l->inicio;
            *p = aux->contato;
            l->inicio = aux->prox;
            l->inicio->ant = NULL;
            free(aux);
            return 1;
        }
        return 0;
    }
    return 0;
}

int removerPosicao(listaDupla *l, agenda *p, int pos)
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
                *p = atual->contato;
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

int removerFinal(listaDupla *l, agenda *p)
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
                *p = aux->contato;
                l->inicio = aux->prox;
            }
            else
            {
                *p = aux->contato;
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

int pesquisarChave(listaDupla *l, agenda chave, int *res) // res== resultado
{
    if (l != NULL)
    {
        if (estaVzia(l))
        {
            no *aux = l->inicio;
            int cont = 1;
            while (aux != NULL)
            {
                if (aux->contato.num == chave.num)
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

int pesquisarPosicao(listaDupla *l, int pos, agenda *p)
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
            *p = aux->contato;
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
        printf("\n////Numero do contato: [%d]\nNome do contato: %s.\nEmail do contato: %s.\n\n  ", aux->contato.num, aux->contato.nome, aux->contato.email);
        aux = aux->prox;
    }
    printf("\n============== LISTA ==============\n");
}
