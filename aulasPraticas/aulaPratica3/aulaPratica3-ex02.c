#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno
{
    char nome[30];
    int matricula, notas[3];
    float media;
} aluno;

void inserindoDados(aluno *vet, int tam);
void imprimindoDados(aluno *vet, int tam);
int buscaSequencial(int chave, int *vet, int tam);

int main()
{
    int qtdAlunos;

    aluno *vetorAlunos;

    printf("Digite quantos alunos deseja inserir: \n");
    scanf("%d", &qtdAlunos);

    vetorAlunos = (aluno *)malloc(qtdAlunos * sizeof(int));

    inserindoDados(vetorAlunos, qtdAlunos);

    imprimindoDados(vetorAlunos, qtdAlunos);

    return 0;
}

void inserindoDados(aluno *vet, int tam)
{

    int soma = 0;
    for (int x = 0; x < tam; x++)
    {
        printf("Aluno %d: \n", x + 1);

        printf("Nome: ");
        // fgets(vet[x].nome, 30, stdin);
        scanf(" %c", &vet[x].nome);

        printf("Numero da matricula: ");
        scanf("%d", &vet[x].matricula);

        for (int y = 0; y < 3; y++)
        {
            printf("Nota %d: ", y + 1);
            scanf("%d", &vet[x].notas[y]);

            soma = soma + vet[x].notas[y];
        }

        vet[x].media = soma / 3;
    }
}

int buscaSequencial(int chave, int *vet, int tam)
{
    for (int x = 0; x < tam; x++)
    {
        if (vet[x] == chave)
        {
            return x;
        }
        else
        {
            return -1;
        }
    }
}

void imprimindoDados(aluno *vet, int tam)
{
    for (int x = 0; x < tam; x++)
    {
        printf("Aluno %d\n", x + 1);
        printf(" %c \n", vet[x].nome);
        printf("Matricula: %d \n", vet[x].matricula);

        for (int y = 0; y < 3; y++)
        {
            printf("Nota %d: %d", y + 1, vet[x].notas[y]);
        }
        printf("Media: %f \n", vet[x].media);
    }
}
