#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct logradouro
{
    char rua[30], bairro[20];
    int numero;
} logradouro;

typedef struct pessoa
{

    char nome[30];
    int idade;
    logradouro pessoa;

} pessoa;

int main()
{

    pessoa p1;

    printf("Forneca o nome de uma pessoa: \n");
    fflush(stdin);
    fgets(p1.nome, 30, stdin);

    printf("Sua idade: \n");
    scanf("%d", &p1.idade);

    printf("Seu endereco: \n");
    printf("Rua: \n");
    fflush(stdin);
    fgets(p1.pessoa.rua, 30, stdin);

    printf("Bairro: \n");
    fflush(stdin);
    fgets(p1.pessoa.bairro, 20, stdin);

    printf("Numero: \n");
    scanf("%d", &p1.pessoa.numero);

    printf("\n\nInformacoes fornecidas:\n");
    printf("Nome: %s\nIdade: %d\nRua: %s\nBairro: %s\nNumero: %d\n", p1.nome, p1.idade, p1.pessoa.rua, p1.pessoa.bairro, p1.pessoa.numero);

    return 0;
}