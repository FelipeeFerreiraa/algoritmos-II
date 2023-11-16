#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct parOrdenado
{
    int x, y;
} parOrdenado;

parOrdenado iniciaPassando(int a, int b);
void iniciaLendo(parOrdenado *a);
int analisarQuadrante(parOrdenado a);
int verificaPontoNoQuadrante(parOrdenado a, int b);
void alterandoValores(parOrdenado *a, int b, int c);
float distanciaEntreDoisPontos(parOrdenado a, parOrdenado b);
int maiorValorDoPonto(parOrdenado a);

int main()
{

    parOrdenado coordenada0, coordenada2;
    int quadrante;

    printf("----Inicializacao Passando Parametros\n");
    coordenada2 = iniciaPassando(4, 5);
    printf("X: %d, Y: %d \n", coordenada2.x, coordenada2.y);
    printf("\n\n");

    printf("----Inicializacao Fazendo Leitura \n");
    iniciaLendo(&coordenada0);
    printf("X: %d, Y: %d \n", coordenada0.x, coordenada0.y);
    printf("\n\n");

    printf("----Analisando Quadrante \n");
    quadrante = analisarQuadrante(coordenada0);
    printf("Ponto passado esta no quadrante: %d", quadrante);
    if (quadrante == 0)
    {
        printf("\nEixo X ou Eixo Y = 0\n");
    }
    printf("\n\n");

    printf("----Verificando Um Ponto No Quadrante\n");
    int verificacao1;

    verificacao1 = verificaPontoNoQuadrante(coordenada0, 2); // verifica se coordenada00 esta no ponto 2

    if (verificacao1 == 0)
    {
        printf("Falso nao esta no quadrante 2.\n");
    }
    if (verificacao1 == 1)
    {
        printf("Verdadeiro esta no quadrante 2.\n");
    }
    printf("\n\n");

    printf("----Alterando Valores De Um Ponto Via Parametro\n");
    alterandoValores(&coordenada0, 2, -3);
    printf("X: %d, Y: %d \n", coordenada0.x, coordenada0.y);
    printf("\n\n");

    printf("----Distancia Entre Dois Pontos\n");
    float distancia;
    distancia = distanciaEntreDoisPontos(coordenada0, coordenada2);
    printf("Distancia entre os pontos: %.2f\n", distancia);
    printf("\n\n");

    printf("----Maior Valor Do Ponto\n");
    int maiorValor;
    maiorValor = maiorValorDoPonto(coordenada0);
    printf("Maior valor do ponto fornecido eh = %d\n", maiorValor);
    printf("\n\n");

    return 0;
}

parOrdenado iniciaPassando(int a, int b)
{

    parOrdenado coordenada1;

    coordenada1.x = a;
    coordenada1.y = b;

    return coordenada1;
}

void iniciaLendo(parOrdenado *a)
{

    printf("Digite um valor para X: \n");
    scanf("%d", &(*a).x);
    printf("Digite um valor para Y: \n");
    scanf("%d", &(*a).y);
}

int analisarQuadrante(parOrdenado a)
{

    int quadrante;
    if (a.x > 0 && a.y > 0)
    {
        quadrante = 1;
    }

    if (a.x > 0 && a.y < 0)
    {
        quadrante = 4;
    }

    if (a.x < 0 && a.y < 0)
    {
        quadrante = 3;
    }

    if (a.x < 0 && a.y > 0)
    {
        quadrante = 2;
    }

    if (a.x == 0 && (a.y > 0 || a.y < 0))
    {
        // printf("Eixo X = 0\n");
        quadrante = 0;
    }

    if (a.y == 0 && (a.x > 0 || a.x < 0))
    {
        // printf("Eixo Y = 0\n");
        quadrante = 0;
    }

    return quadrante;
}

int verificaPontoNoQuadrante(parOrdenado a, int b)
{

    int verificacao; // 1-verdadeeiro , 0-falso
    if (analisarQuadrante(a) == b)
    {
        verificacao = 1;
    }

    if (analisarQuadrante(a) != b)
    {
        verificacao = 0;
    }

    return verificacao;
}

void alterandoValores(parOrdenado *a, int b, int c)
{

    (*a).x = b;
    (*a).y = c;
}

float distanciaEntreDoisPontos(parOrdenado a, parOrdenado b)
{

    float distancia, quadrado1, quadrado2, soma;

    quadrado1 = pow((b.x - a.x), 2);
    quadrado2 = pow((b.y - a.y), 2);
    soma = quadrado1 + quadrado2;
    distancia = sqrt(soma);

    return distancia;
}

int maiorValorDoPonto(parOrdenado a)
{

    int maiorValor;

    if (a.x >= a.y)
    {
        maiorValor = a.x;
    }
    else if (a.y >= a.x)
    {
        maiorValor = a.y;
    }

    return maiorValor;
}
