#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct data
{
    int dia, mes, ano;
} data;

typedef struct pessoa
{
    char nome[MAX];
    data data; // data de nascimento da pessoa
} pessoa;

typedef struct no
{
    pessoa p;
    struct no *prox;
} no;

pessoa lerPessoa();
void imprimirPessoa(pessoa p);
void liberarMemoria(no *topo);
no *empilhar(no *topo);
no *desmpilhar(no **topo);
void imprimirPilha(no *topo);

int main()
{

    no *remover, *topo = NULL;

    int opcao;
    do
    {
        printf("[0] - Sair\n[1] - Empilhar\n[2] - Desempilhar\n[3] - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            break;

        case 1:
            topo = empilhar(topo);
            break;

        case 2:
            remover = desmpilhar(&topo);
            if (remover != NULL)
            {
                printf("Elemento removido: \n");
                imprimirPessoa(remover->p);
            }
            else
            {
                printf("Sem NO para remover!!\n");
            }
            break;

        case 3:
            imprimirPilha(topo);
            break;
        }
    } while (opcao != 0);

    liberarMemoria(topo);

    return 0;
}

pessoa lerPessoa()
{
    pessoa p;

    printf("Digite o nome da pesssoa a data de nascimento: (dd mm aa)\n: ");
    // fgets(p.nome, 50, stdin);
    // scanf(" %s", &p.nome);
    //  printf("Digite a data de nascimento: (dd mm aa)\n");
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';
    scanf("%d%d%d", &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

void imprimirPessoa(pessoa p)
{
    printf("\n\nNome:  %s\nData: %d/%d/%d\n\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

void imprimirPilha(no *topo)
{
    printf("------------- Pilha --------------\n\n");

    while (topo != NULL)
    {
        imprimirPessoa(topo->p);
        topo = topo->prox;
    }

    printf("----------- Fim Pilha ------------\n\n");
}

void liberarMemoria(no *topo)
{
    free(topo);
}

// funcao para empilhar
no *empilhar(no *topo)
{
    no *novo;
    novo = (no*) malloc(sizeof(no));

    if (novo != NULL)
    {
        novo->p = lerPessoa();
        novo->prox = topo;
        return novo;
    }
    else
        printf("Erro na alocacao de memoria!!! (pNovo)\n");
    return NULL;
}

no *desmpilhar(no **topo)
{

    if (*topo != NULL)
    {
        no *remover = *topo;
        *topo = remover->prox;
        return remover;
    }
    else
    {
        printf("Pilha vazia!!!\n");
        return NULL;
    }
}