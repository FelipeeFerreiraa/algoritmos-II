#include <stdio.h>
#include <stdlib.h>

typedef struct ALUNO
{
    char nome[30];
    int m;
    float notas[3];
    float med;
} Aluno;

// Protótipos de funções
void preenche(Aluno *V, int t);
int qtd_aprov(Aluno *V, int t);
Aluno *apr(Aluno *V, int t);
Aluno maior_media(Aluno *V, int t);
void imprime(Aluno *A);

int main()
{
    int n;
    printf("Digite a quantidade de alunos: \n");
    scanf("%d", &n);

    //"Alocagem" dinâmica é como se fosse um vetor
    Aluno *A = (Aluno *)malloc(n * sizeof(Aluno)); // TypeCast pois malloc retorna ponteiro genérico
    preenche(A, n);

    int c = qtd_aprov(A, n);                        // Quantidade de aprovados
    Aluno *AP = (Aluno *)malloc(c * sizeof(Aluno)); // Criando vetor de aprovados
    AP = apr(A, n);
    Aluno maior;
    if (c > 0)
    {                               // Se tiver aprovados
        maior = maior_media(AP, c); // Maior média dos aprovados, melhorando eficiência
    }
    else
    {
        maior = maior_media(A, n); // Maior média de todos os alunos
    }
    printf("\nAluno com maior media: \n");
    imprime(&maior); // Passando o endereço de memória do aluno com maior média

    free(A);  // Liberando memória
    free(AP); // Liberando memória

    return 0;
}

// Funções
void preenche(Aluno *V, int t)
{ // Passando vetor para a função usando o asterisco
    for (int i = 0; i < t; i++)
    {
        float soma = 0;
        printf("Digite o nome do aluno: \n");
        setbuf(stdin, NULL);
        fgets(V[i].nome, 30, stdin);
        printf("Digite a matricula do aluno: \n");
        scanf("%d", &V[i].m);
        printf("Digite as 3 notas do aluno: \n");
        for (int j = 0; j < 3; j++)
        {
            scanf("%f", &V[i].notas[j]);
            soma += V[i].notas[j];
        }
        V[i].med = soma / 3;
    }
}

int qtd_aprov(Aluno *V, int t)
{
    int c = 0;
    for (int i = 0; i < t; i++)
    {
        if (V[i].med >= 6)
        {
            c++;
        }
    }
    return c;
}

Aluno *apr(Aluno *V, int t)
{
    int c = qtd_aprov(V, t); // Quantidade de aprovados
    int j = 0;
    Aluno *AP = (Aluno *)malloc(c * sizeof(Aluno));
    for (int i = 0; i < t; i++)
    {
        if (V[i].med >= 6)
        {
            AP[j] = V[i];
            j++;
        }
    }
    return AP; // Retorna o vetor de aprovados
}

Aluno maior_media(Aluno *V, int t)
{ // Retorna o aluno com maior média
    float maior_nota = V[0].med;
    int pos = 0;
    for (int i = 1; i < t; i++)
    {
        if (V[i].med > maior_nota)
        {
            maior_nota = V[i].med;
            pos = i;
        }
    }
    return V[pos];
}

void imprime(Aluno *A)
{
    printf("Nome: %s\n", A->nome);                                          // Acessando o campo nome
    printf("Matricula: %d\n", (*A).m);                                      // Outra forma de acessar o campo
    printf("Notas: %f - %f - %f\n", A->notas[0], A->notas[1], A->notas[2]); // Acessando o vetor de notas
    printf("\nMedia: %.2f\n", A->med);                                      // Acessando a média
}