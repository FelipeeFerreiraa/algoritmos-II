#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define totalCartas 54 // 52 cartas de 1 a 13, e 2 coringas por baralho

typedef struct carta // equivalente a um NO/elemento/celula
{
    int valor; // 1=ás , J=12, Q=11, K=13, joker=14
    int naipe; // 1-ouros, 2-paus, 3-espadas, 4-copas, 5-joker
               // struct carta *proxCarta;
} carta;

typedef struct no
{
    struct no *prox;
    carta cartaDaVez;
} no;

typedef struct pilhaDeCompra //'pilha' de cartas para 'comprar'
{
    carta *topo;
} pilhaDeCompra;

typedef struct baralhoDesviradoMesa //'lista' de, cartas viradas na mesa
{
    carta *inicio;
} baralhoDesviradoMesa;

typedef struct areaDeDescarte //'pilha' area de descarte, de cada jogador
{
    carta *topo;
} areaDeDescarte;

typedef struct monteDoJogador //'lista' cartas na mao do jogador
{
    carta *inicio;
} monteDoJogador;

typedef struct jogador
{
    char nome[30];
} jogador;

pilhaDeCompra *criarPilhaDeCompra();
baralhoDesviradoMesa *criarBaralhoDesviradoMesa();
areaDeDescarte *criarAreaDeDescarte();
monteDoJogador **criarMonteDoJogador(int qtdeJogadores); // retornar um vetor com o monte de cada jogador;

// inserindo todas pelo inicio
int inserirPilhaDeCompra(pilhaDeCompra *p, carta c);
int inserirBaralhoDesviradoMesa(baralhoDesviradoMesa *b, carta c);
int inserirAreaDeDescarte(areaDeDescarte *a, carta c);
int inserirMonteDoJogador(monteDoJogador *m, carta c);

// removendo todas pelo inicio
int removerPilhaDeCompra(pilhaDeCompra *p, carta *res);
int removerBaralhoDesviradoMesa(baralhoDesviradoMesa *b, carta *res);
int removerAreaDeDescarte(areaDeDescarte *a, carta *res);
int removerMonteDoJogador(monteDoJogador *m, carta *res);

void criandoBaralho(carta *baralho); // vetor de cartas
void embaralhar(carta *baralho);
void imprimirBaralho(carta *baralho);

int main()
{
    srand(time(NULL));

    ////// ============ testeeeeeee --=-=-=--=-
    carta baralhoooo[54];
    criandoBaralho(baralhoooo);
    embaralhar(baralhoooo);
    imprimirBaralho(baralhoooo);
    ////// ============ FIM testeeeeeee --=-=-=--=-

    return 0;
}

pilhaDeCompra *criarPilhaDeCompra()
{
    pilhaDeCompra *p1 = (pilhaDeCompra *)malloc(sizeof(pilhaDeCompra));
    if (p1 != NULL)
    {
        p1->topo = NULL;
        return p1;
    }
}

baralhoDesviradoMesa *criarBaralhoDesviradoMesa()
{
    baralhoDesviradoMesa *b1 = (baralhoDesviradoMesa *)malloc(sizeof(baralhoDesviradoMesa));
    if (b1 != NULL)
    {
        b1->inicio = NULL;
        return b1;
    }
}

areaDeDescarte *criarAreaDeDescarte()
{
    areaDeDescarte *a1 = (areaDeDescarte *)malloc(sizeof(areaDeDescarte));
    if (a1 != NULL)
    {
        a1->topo = NULL;
        return a1;
    }
}

monteDoJogador **criarMonteDoJogador(int qtdeJogadores)
{
    monteDoJogador *m1 = (monteDoJogador *)malloc(sizeof(monteDoJogador));
    if (m1 != NULL)
    {
        m1->inicio = NULL;
        return m1;
    }
}

int inserirPilhaDeCompra(pilhaDeCompra *p, carta c)
{
    if (p != NULL)
    {
        no *novo = (no *)malloc(sizeof(no));
        if (novo == NULL)
        {
            return 0;
        }

        novo->cartaDaVez = c;
        if (p->topo == NULL)
        {
            novo->prox = NULL;
            p->topo = novo;
            return 1;
        }
        else
        {
            no *aux;
            aux = novo;
            aux->prox = p->topo;
            p->topo = aux;
            return 1;
        }
    }
    else
        return 0;
}

int inserirBaralhoDesviradoMesa(baralhoDesviradoMesa *b, carta c)
{
    if (b != NULL)
    {
        no *novo = (no *)malloc(sizeof(no));
        if (novo == NULL)
        {
            return 0;
        }
        novo->cartaDaVez = c;
        if (b->inicio == NULL)
        {
            novo->prox = NULL;
            b->inicio = novo;
            return 1;
        }
        else
        {
            novo->prox = b->inicio;
            b->inicio = novo;
            return 1;
        }
    }
    else
        return 0;
}

int inserirAreaDeDescarte(areaDeDescarte *a, carta c)
{
    if (a != NULL)
    {
        no *novo = (no *)malloc(sizeof(no));
        if (novo == NULL)
        {
            return 0;
        }

        novo->cartaDaVez = c;
        if (a->topo == NULL)
        {
            novo->prox = NULL;
            a->topo = novo;
            return 1;
        }
        else
        {
            no *aux;
            aux = novo;
            aux->prox = a->topo;
            a->topo = aux;
            return 1;
        }
    }
    else
        return 0;
}

int inserirMonteDoJogador(monteDoJogador *m, carta c)
{
    if (m != NULL)
    {
        no *novo = (no *)malloc(sizeof(no));
        if (novo == NULL)
        {
            return 0;
        }
        novo->cartaDaVez = c;
        if (m->inicio == NULL)
        {
            novo->prox = NULL;
            m->inicio = novo;
            return 1;
        }
        else
        {
            novo->prox = m->inicio;
            m->inicio = novo;
            return 1;
        }
    }
    else
        return 0;
}

int removerPilhaDeCompra(pilhaDeCompra *p, carta *res)
{
    if (p != NULL)
    {
        no *aux = p->topo;
        *res = aux->cartaDaVez;
        p->topo = aux->prox;
        free(aux);
        return 1;
    }
    else
        return 0;
}

int removerBaralhoDesviradoMesa(baralhoDesviradoMesa *b, carta *res)
{
    if (b != NULL)
    {
        no *aux = b->inicio;
        *res = aux->cartaDaVez;
        b->inicio = aux->prox;
        free(aux);
        return 1;
    }
    else
        return 0;
}

int removerAreaDeDescarte(areaDeDescarte *a, carta *res)
{
    if (a != NULL)
    {
        no *aux = a->topo;
        *res = aux->cartaDaVez;
        a->topo = aux->prox;
        free(aux);
        return 1;
    }
    else
        return 0;
}

int removerMonteDoJogador(monteDoJogador *m, carta *res)
{
    if (m != NULL)
    {
        no *aux = m->inicio;
        *res = aux->cartaDaVez;
        m->inicio = aux->prox;
        free(aux);
        return 1;
    }
    else
        return 0;
}

void criandoBaralho(carta *baralho) // vetor de cartas
{
    int valor[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int naipe[4] = {1, 2, 3, 4};

    int i = 0;

    // Adicionando as cartas
    for (int x = 0; x < 4; x++) // x < Naipes
    {
        for (int y = 0; y < 13; y++)
        {
            baralho[i].valor = valor[y];
            baralho[i].naipe = naipe[x];
            i++;
        }
    }

    for (int w = i; w < totalCartas; w++)
    {
        baralho[w].valor = valor[13];
        baralho[w].naipe = 5; // coringa tem naipe==5
    }
}

void embaralhar(carta *baralho)
{
    int x, y;
    carta aux;

    for (x = totalCartas - 1; x > 0; x--)
    {
        y = rand() % (x + 1);

        aux = baralho[x];
        baralho[x] = baralho[y];
        baralho[y] = aux;
    }
}

void imprimirBaralho(carta *baralho)
{
    int i;

    for (i = 0; i < totalCartas; i++)
    {
        printf("%d de %d,, [%d]\n", baralho[i].valor, baralho[i].naipe, i + 1);
    }
}