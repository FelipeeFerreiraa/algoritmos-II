#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    char nome[30];
    int matricula, nota[3];
    float media;
} aluno;

int buscaSequencial(int chave, int *vet, int tam);
int buscaBinaria(int chave, int *vet, int tam);
void ordenacao(int *a, int tam);
aluno inserindoDados(aluno *vet, int tam);
void imprimindoDados(aluno *vet, int tam);
int buscaSequencialMatricula(int chave, aluno *vet, int tam);
int buscaBinariaMatricula(int chave, aluno *vet, int tam);
void ordenacaoMatricula(aluno *a, int tam);

int main()
{

    int *vetor, qtd, qtdAlunos, chaveTest, resultadoTest, chaveMatricula, resMatricula;
    aluno *vetorAlunos;
    /*
      printf("Digite quantos numeros tera o vetor: \n");
      scanf("%d", &qtd);

      vetor = (int *) malloc(qtd * sizeof(int));

      printf("Agora forneca os elementos do vetoooor: \n");
      for(int x=0; x<qtd; x++) {
        printf("numero %d: ", x+1);
        scanf("%d", &*(vetor + x));
      }

      printf("Digite um numero/chave: \n");
      scanf("%d", &chaveTest);

      resultadoTest =  buscaSequencial(chaveTest, vetor, qtd);
      printf("Resultado busca sequencial = %d \n", resultadoTest);

      resultadoTest =  buscaBinaria(chaveTest, vetor, qtd);
      printf("Resultado busca Binaria = %d \n", resultadoTest);
      */

    printf("Digite quantos alunos voce deseja inserir: \n");
    scanf("%d", &qtdAlunos);

    vetorAlunos = (aluno *)malloc(qtdAlunos * sizeof(int));

    inserindoDados(vetorAlunos, qtdAlunos);

    for (int x = 0; x < qtdAlunos; x++)
    {
        printf("-----Aluno %d: \n", x + 1);
        printf("Nome: %s \n", vetorAlunos[x].nome);
        printf("Matricula: %d \n", vetorAlunos[x].matricula);
        for (int y = 0; y < 3; y++)
        {
            printf("Nota %d: %d \n", y + 1, vetorAlunos[x].nota[y]);
        }
        printf("Media: %.2f \n", vetorAlunos[x].media);
    }

    printf("Digite a Matricula que deseja encontrar: \n");
    scanf("%d", &chaveMatricula);

    //resMatricula = buscaSequencialMatricula(chaveMatricula, vetorAlunos, qtdAlunos);

    resMatricula = buscaBinariaMatricula(chaveMatricula, vetorAlunos, qtdAlunos);

    if (resMatricula != -1)
    {
        printf("----Nome: %s \n", vetorAlunos[resMatricula].nome);
        printf("----Matricula: %d \n", vetorAlunos[resMatricula].matricula);
        for (int y = 0; y < 3; y++)
        {
            printf("----Nota %d: %d \n", y + 1, vetorAlunos[resMatricula].nota[y]);
        }
        printf("----Media: %f \n", vetorAlunos[resMatricula].media);
    }
    else
    {
        printf("##Erro-MatriculaNaoEncontrada!!!");
    }

    imprimindoDados(vetorAlunos, qtdAlunos);
    
    return 0;
}

int buscaSequencial(int chave, int *vet, int tam)
{

    for (int x = 0; x < tam; x++)
    {
        if (vet[x] == chave)
        {
            return x;
        }
    }
    return -1;
}

int buscaBinaria(int chave, int *vet, int tam)
{
    ordenacao(vet, tam);
    int i, esq = 0, dir = tam - 1;
    do
    {

        i = (esq + dir) / 2; // posicao

        if (chave > vet[i])
        {
            esq = i + 1;
        }
        else
        {
            dir = i - 1;
        }

    } while (chave != vet[i] && esq <= dir);
    if (chave == vet[i])
    {
        return i;
    }
    else
    {
        return -1;
    }
}

void ordenacao(int *a, int tam)
{
    int aux;
    for (int j = tam - 1; j < 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (a[i + 1] < a[i])
            {
                // trocar a[i] com a[i+1]
                aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
            }
        }
    }
}

void ordenacaoMatricula(aluno *a, int tam)
{
    int aux;
    for (int j = tam - 1; j < 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (a[i + 1].matricula < a[i].matricula)
            {
                // trocar a[i] com a[i+1]
                aux = a[i].matricula;
                a[i].matricula = a[i + 1].matricula;
                a[i + 1].matricula = aux;
            }
        }
    }
}

aluno inserindoDados(aluno *vet, int tam)

{
    int soma = 0;
    for (int x = 0; x < tam; x++)
    {
        printf("Digite o nome do aluno: \n");
        // fgets(vet[x].nome, 30, stdin);
        scanf(" %s", &vet[x].nome);

        printf("Digite a matricula do alunoo: \n");
        scanf("%d", &vet[x].matricula);

        printf("Digite as notas do aluno: \n");
        for (int y = 0; y < 3; y++)
        {
            printf("Nota %d: ", y + 1);
            scanf("%d", &vet[x].nota[y]);
            soma = soma + *(vet[x].nota + y);
        }
        vet[x].media = soma / 3;
    }

    return *vet;
}

int buscaSequencialMatricula(int chave, aluno *vet, int tam)
{
    for (int x = 0; x < tam; x++)
    {
        if (vet[x].matricula == chave)
        {
            return x;
        }
    }
    return -1;
}

int buscaBinariaMatricula(int chave, aluno *vet, int tam)
{
    ordenacaoMatricula(vet, tam);

    int i, esq = 0, dir = tam - 1;
    do
    {

        i = (esq + dir) / 2; // posicao

        if (chave > vet[i].matricula)
        {
            esq = i + 1;
        }
        else
        {
            dir = i - 1;
        }

    } while (chave != vet[i].matricula && esq <= dir);
    if (chave == vet[i].matricula)
    {
        return i;
    }
    else
    {
        return -1;
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
            printf("Nota %d: %d", y + 1, vet[x].nota[y]);
        }
        printf("Media: %f \n", vet[x].media);
    }
}
