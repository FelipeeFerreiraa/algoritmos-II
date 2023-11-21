#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define totalCartas 54 // 52 cartas de 1 a 13, e 2 coringas por baralho

typedef struct carta
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
    no *topo;
} pilhaDeCompra;

typedef struct baralhoDesviradoMesa //'lista' de, cartas viradas na mesa
{
    no *inicio;
} baralhoDesviradoMesa;

typedef struct areaDeDescarte //'pilha' area de descarte, de cada jogador
{
    no *topo;
} areaDeDescarte;

typedef struct jogador
{
    char nome[30];
} jogador;

pilhaDeCompra *criarPilhaDeCompra();
baralhoDesviradoMesa *criarBaralhoDesviradoMesa();
areaDeDescarte **criarAreaDeDescarte(int qtdeJogadores);
// retornar um vetor de pilhas de descarte de cada jogador;

// inserindo todas pelo inicio
int inserirPilhaDeCompra(pilhaDeCompra *p, carta c);
int inserirBaralhoDesviradoMesa(baralhoDesviradoMesa *b, carta c);
int inserirAreaDeDescarte(areaDeDescarte *a, carta c);

// removendo todas pelo inicio
int removerPilhaDeCompra(pilhaDeCompra *p, carta *res);
int removerAreaDeDescarte(areaDeDescarte *a, carta *res);
int removerBaralhoDesviradoMesa(baralhoDesviradoMesa *b, carta *res);
int removerBaralhoDesviradoMesaPOS(baralhoDesviradoMesa *b, carta *res, int pos);

void criandoBaralho(carta *baralho, int tam, int qtdeBaralhos); // vetor de cartas
void embaralhar(carta *baralho, int tam);
void imprimirBaralho(carta *baralho, int tam);

void colocandoBaralhoPilhaCompra(carta *baralho, pilhaDeCompra *p1, int tam);
void qtdeCartasPilhaCompra(pilhaDeCompra *p);

void NomearJogadores(jogador *j1, int qtde);

int verificarCartasBaralhoMesa(carta *p, baralhoDesviradoMesa *b);
int verificarCartasDescarteJogadores(carta *p, areaDeDescarte **a, int qtdeJogadores);

int main()
{
    srand(time(NULL));

    int qtdeBaralhos, qtdeJogadores;

    printf("\nJogo Rouba-Monte!!!\n");

    //-----------quantidade de jogadores
    printf("\nQuantos Jogadores vao Jogaaar!\n");
    scanf("%d", &qtdeJogadores);
    jogador *jogadores = (jogador *)malloc(qtdeJogadores * sizeof(jogadores));
    NomearJogadores(jogadores, qtdeJogadores);

    //-----------quantidade de baralhos
    printf("\nCom quantos baaralhos vamos jogar? \n");
    scanf("%d", &qtdeBaralhos);
    int novoTotal = qtdeBaralhos * 54; // no minimo 1 baralho
    carta *baralhoooo = (carta *)malloc(novoTotal * sizeof(carta));

    //-----------criando e embaralhando
    criandoBaralho(baralhoooo, novoTotal, qtdeBaralhos);
    embaralhar(baralhoooo, novoTotal);
    // teste: imprimirBaralho(baralhoooo, novoTotal);

    //----------colocando as cartas na pilha de compraaa
    pilhaDeCompra *monteDeCompra = criarPilhaDeCompra();
    colocandoBaralhoPilhaCompra(baralhoooo, monteDeCompra, novoTotal);
    // teste: qtdeCartasPilhaCompra(monteDeCompra);

    //-----------'LISTA' baralho na mesa
    baralhoDesviradoMesa *baralhoNoCentro = criarBaralhoDesviradoMesa();

    //-----------vetor de 'PILHAS' de descarte para cada jogador
    areaDeDescarte **descarteDeMontes = criarAreaDeDescarte(qtdeJogadores);

    // int x = 0;
    carta cartaRetirada;
    no *auxMonteDeCompra = monteDeCompra->topo;
    int amontoando = 0;
    while (auxMonteDeCompra != NULL)
    {

        for (int x = 0; x < qtdeJogadores; x++)
        {
            do
            {

                printf("\nVez do jogador: %s\n", jogadores[x]);

                if (removerPilhaDeCompra(monteDeCompra, &cartaRetirada))
                {
                    printf("\nCarta retirada: valor: %d, naipe: %d\n", cartaRetirada.valor, cartaRetirada.naipe);
                }
                else
                {
                    printf("\nERRO\n");
                }

                no *auxBaralhoNoCentro = baralhoNoCentro->inicio;
                while (auxBaralhoNoCentro != NULL)
                {
                    if (cartaRetirada.valor == auxBaralhoNoCentro->cartaDaVez.valor)
                    {
                        // inserir cartaRetirada e auxBaralhoNoCentro->cartaDaVez na area de descarte do jogador[x]
                    }

                    auxBaralhoNoCentro = auxBaralhoNoCentro->prox;
                    amontoando = 1;
                }

                for (int y = 0; y < qtdeJogadores; y++)
                {
                    if (cartaRetirada.valor == descarteDeMontes[y]->topo->cartaDaVez.valor)
                    {
                        // inserir cartaRetirada e descarteDeMontes[y]->topo->cartaDaVez na area de descarte do jogador[x]
                    }
                    amontoando = 1;
                }

                if (cartaRetirada.valor != 0)
                {
                    // inserir cartaRetirada no baralhoCentro
                    amontoando = 0;
                }

            } while (amontoando != 0); // repete
        }
    }

    // funcao para verificar quem tem mais cartas no: descarteDeMontes

    free(baralhoooo);
    return 0;
}

pilhaDeCompra *criarPilhaDeCompra()
{
    pilhaDeCompra *p1 = (pilhaDeCompra *)malloc(sizeof(pilhaDeCompra));
    if (p1 != NULL)
    {
        p1->topo = NULL;
    }
    return p1;
}

baralhoDesviradoMesa *criarBaralhoDesviradoMesa()
{
    baralhoDesviradoMesa *b1 = (baralhoDesviradoMesa *)malloc(sizeof(baralhoDesviradoMesa));
    if (b1 != NULL)
    {
        b1->inicio = NULL;
    }
    return b1;
}

areaDeDescarte **criarAreaDeDescarte(int qtdeJogadores)
{
    areaDeDescarte **a1 = (areaDeDescarte **)malloc(qtdeJogadores * sizeof(areaDeDescarte *));
    for (int x = 0; x < qtdeJogadores; x++)
    {
        a1[x] = (areaDeDescarte *)malloc(sizeof(areaDeDescarte));
        a1[x]->topo = NULL;
    }
    return a1;
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

int removerBaralhoDesviradoMesaPOS(baralhoDesviradoMesa *b, carta *res, int pos)
{
    if (b != NULL)
    {
        no *ant, *atual = b->inicio;
        int cont = 1;

        while (cont != pos && atual != NULL)
        {
            ant = atual;
            atual = atual->prox;
            cont++;
        }
        ant->prox = atual->prox;
        *res = atual->cartaDaVez;
        free(atual);
        return 1;
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

void criandoBaralho(carta *baralho, int tam, int qtdeBaralhos) // vetor de cartas
{

    int valor[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int naipe[4] = {1, 2, 3, 4};

    int i = 0;

    // Adicionando as cartas
    while (i < tam - (2 * qtdeBaralhos))
    {
        for (int x = 0; x < 4; x++) // x < Naipes
        {
            for (int y = 0; y < 13; y++)
            {

                baralho[i].valor = valor[y];
                baralho[i].naipe = naipe[x];
                i++;
            }
        }
    }

    for (int w = i; w < tam; w++)
    {
        baralho[w].valor = valor[13];
        baralho[w].naipe = 5; // coringa tem naipe==5
    }
}

void embaralhar(carta *baralho, int tam)
{
    int x, y;
    carta aux;

    for (x = tam - 1; x > 0; x--)
    {
        y = rand() % (x + 1);

        aux = baralho[x];
        baralho[x] = baralho[y];
        baralho[y] = aux;
    }
}

void imprimirBaralho(carta *baralho, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf("%d de %d,, [%d]\n", baralho[i].valor, baralho[i].naipe, i + 1);
    }
}

void colocandoBaralhoPilhaCompra(carta *baralho, pilhaDeCompra *p1, int tam)
{

    for (int x = 0; x < tam; x++)
    {
        if (inserirPilhaDeCompra(p1, baralho[x]))
        {
            // printf("empilhado %d\n", x + 1);
        }
        else
            printf("ALGO ESTA DANDO ERRADO!!!");
    }
}

void qtdeCartasPilhaCompra(pilhaDeCompra *p)
{
    if (p != NULL)
    {
        no *aux = p->topo;
        int qtd = 0;
        while (aux != NULL)
        {
            aux = aux->prox;
            qtd++;
        }
        printf("\nqtd: %d \n", qtd);
    }
    else
        printf("ALGO ESTA DANDO ERRADO!!!");
}

void NomearJogadores(jogador *j1, int qtde)
{
    printf("\nForneca o nome dos jogadores: \n");
    for (int x = 0; x < qtde; x++)
    {
        printf("Jogador %d: ", x + 1);
        setbuf(stdin, NULL);
        fgets(j1[x].nome, 30, stdin);
    }
}

int verificarCartasBaralhoMesa(carta *p, baralhoDesviradoMesa *b)
{
    no *auxBaralhoMesa = b->inicio;

    int posDaCartaNaMesa = 1;

    while (auxBaralhoMesa != NULL)
    {
        if (p->valor == auxBaralhoMesa->cartaDaVez.valor)
        {
            return posDaCartaNaMesa;
            // remover carta por posicao
        }
        posDaCartaNaMesa++;
        auxBaralhoMesa = auxBaralhoMesa->prox;
    }

    return -1;
}

int verificarCartasDescarteJogadores(carta *p, areaDeDescarte **a, int qtdeJogadores)
{

    int posVetorPonteiros;

    for (int x = 0; x < qtdeJogadores; x++)
    {
        if (p->valor == a[x]->topo->cartaDaVez.valor)
        {
            posVetorPonteiros = x;
            return posVetorPonteiros;
        }
    }

    return -1;
}
