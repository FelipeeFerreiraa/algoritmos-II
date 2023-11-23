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

void imprimirBaralhoMesa(baralhoDesviradoMesa *b);
void imprimirTopoDescarte(areaDeDescarte **a, int qtdeJogadores, jogador *j1);

void colocarCartaAreaDescarteJogador(areaDeDescarte **a, int jogador, carta c);
void roubarMonte(areaDeDescarte **a, carta c, carta *retirada, int qtdeJogadores, int posNoVetorDePonteiros);

int main()
{
    srand(time(NULL));

    int qtdeBaralhos, qtdeJogadores;

    printf("\nJogo Rouba-Monte!!!\n");

    //-----------quantidade de jogadores
    printf("\nQuantos Jogadores vao Jogaaar!\n");
    scanf("%d", &qtdeJogadores);
    jogador *jogadores = (jogador *)malloc(qtdeJogadores * sizeof(jogador));
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

    carta cartaRetirada;
    no *auxMonteDeCompra = monteDeCompra->topo;
    int x = 0, teste;
    int escolha;
    while (auxMonteDeCompra != NULL)
    {

        printf("\nVez do jogador: %s \n", jogadores[x].nome);

        if (removerPilhaDeCompra(monteDeCompra, &cartaRetirada))
        {
            printf("\nCarta retirada: valor: %d, naipe: %d\n", cartaRetirada.valor, cartaRetirada.naipe);
        }
        else
        {
            printf("\nERRO\n");
        }

        imprimirBaralhoMesa(baralhoNoCentro);
        imprimirTopoDescarte(descarteDeMontes, qtdeJogadores, jogadores);

        printf("\nEscolha:\n[1] Pegar carta do baralho na mesa\n[2] Roubar o monte de algum jogador\n[3] Colocar carta no meu monte\n[4] Colocar carta no baralho da mesa, virada pra cima!\n");
        scanf("%d", &escolha);
        carta auxCase2;
        switch (escolha)
        {
        case 1:
            teste = verificarCartasBaralhoMesa(&cartaRetirada, baralhoNoCentro);
            if (teste != -1)
            {
                inserirAreaDeDescarte(descarteDeMontes[x], cartaRetirada);

                removerBaralhoDesviradoMesaPOS(baralhoNoCentro, &cartaRetirada, teste);

                inserirAreaDeDescarte(descarteDeMontes[x], cartaRetirada);
            }

            

            // imprimirTopoDescarte(descarteDeMontes, qtdeJogadores, jogadores);
            break;

        case 2:
//algo errado
            roubarMonte(descarteDeMontes, auxCase2, &cartaRetirada, qtdeJogadores, x);
            break;

        case 3:
            colocarCartaAreaDescarteJogador(descarteDeMontes, x, cartaRetirada);
            break;

        case 4:

            inserirBaralhoDesviradoMesa(baralhoNoCentro, cartaRetirada);
            x++;
            if (x >= qtdeJogadores)
            {
                x = 0;
            }
            break;

        default:
            break;
        }
    }

    printf("\nAcabou as cartas!!!1\n");

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

void imprimirBaralhoMesa(baralhoDesviradoMesa *b)
{
    no *aux;
    aux = b->inicio;

    printf("\n========== CARTAS NA MESA  ================\n\n");
    while (aux != NULL)
    {
        printf("[Valor %d, Naipe: %d ]  ", aux->cartaDaVez.valor, aux->cartaDaVez.naipe);
        aux = aux->prox;
    }
    printf("\n\n========== CARTAS NA MESA ================\n");
}

void imprimirTopoDescarte(areaDeDescarte **a, int qtdeJogadores, jogador *j1)
{

    printf("\n########### TOPO DOS JOGADORES  #############\n\n");
    for (int x = 0; x < qtdeJogadores; x++)
    {

        if (a[x]->topo != NULL)
        {
            printf("\n[Topo do %sValor %d, Naipe %d]\n  ", j1[x].nome, a[x]->topo->cartaDaVez.valor, a[x]->topo->cartaDaVez.naipe);
        }
    }
    printf("\n########### TOPO DOS JOGADORES  #############\n\n");
}

void colocarCartaAreaDescarteJogador(areaDeDescarte **a, int jogador, carta c)
{
    inserirAreaDeDescarte(a[jogador], c);
}

void roubarMonte(areaDeDescarte **a, carta c, carta *retirada, int qtdeJogadores, int posNoVetorDePonteiros)
{
    for (int x = 0; x < qtdeJogadores; x++)
    {
        if (a[x]->topo->cartaDaVez.valor == c.valor)
        {
            no *aux = a[x]->topo;
            while (aux != NULL)
            {
                removerAreaDeDescarte(a[x], &c);
                inserirAreaDeDescarte(a[posNoVetorDePonteiros], c);
                aux = aux->prox;
            }
        }
    }

    carta cartaDaVez = *retirada;

    inserirAreaDeDescarte(a[posNoVetorDePonteiros], cartaDaVez);
}