#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct data
{
    int dia, mes, ano;
} data;

typedef struct pessoa
{
    char nome[MAX];
    data data;
} pessoa;

typedef struct no
{
    pessoa p;
    struct no *prox;
} no;

typedef struct pilha
{
    no *topo;
} pilha;

pilha *criarPilha(pilha *p);
void liberarPilha(pilha *p);
pilha empilhar(pilha *p);
pilha desempilhar(pilha *p);
int estahVazia(pilha *p);
int estahCheia(pilha *p);

int main()
{

    return 0;
}

pilha *criarPilha(pilha *p) {
    no *topo;
    
}

void liberarPilha(pilha *p);

pilha empilhar(pilha *p);

pilha desempilhar(pilha *p);

int estahVazia(pilha *p);

int estahCheia(pilha *p);

