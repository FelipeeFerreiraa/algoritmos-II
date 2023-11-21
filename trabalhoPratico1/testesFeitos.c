

typedef struct monteDoJogador //'lista' cartas na mao do jogador
{
    no *inicio;
} monteDoJogador;

//-----------vetor de 'Listas', com as cartas na mao de cada jogador
monteDoJogador **monteNaMao = criarMonteDoJogador(qtdeJogadores);

monteDoJogador **criarMonteDoJogador(int qtdeJogadores); // retornar um vetor com o monte de cada jogador;

int inserirMonteDoJogador(monteDoJogador *m, carta c);
int removerMonteDoJogador(monteDoJogador *m, carta *res);

monteDoJogador **criarMonteDoJogador(int qtdeJogadores)
{
    monteDoJogador **m1 = (monteDoJogador **)malloc(qtdeJogadores * sizeof(monteDoJogador *));
    for (int x = 0; x < qtdeJogadores; x++)
    {
        m1[x] = (monteDoJogador *)malloc(sizeof(monteDoJogador));
        m1[x]->inicio = NULL;
    }
    return m1;
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