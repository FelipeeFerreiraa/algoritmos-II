/*

Faça um programa que armazene em um registro de dados (estrutura composta) os dados
de um funcionário de uma empresa, compostos de: Nome, Idade, Sexo (M/F), CPF, Data de
Nascimento, Código do Setor onde trabalha (0-99), Cargo que ocupa (string de até 30
caracteres) e Salário. Os dados devem ser digitados pelo usuário, armazenados na estrutura
e exibidos na tela.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data
{
    int dia, mes, ano;
} data;

typedef struct registro
{
    char nome[30], sexo, cargo[30];
    int idade, cpf, codSetor;
    float salario;
    data nascimento;
} registro;

int main()
{

    registro r1;

    printf("Forneca os dados para o registro: \n");
    printf("Nome: ");
    setbuf(stdin, NULL);
    fgets(r1.nome, 30, stdin);

    printf("Idade: ");
    scanf("%d", &r1.idade);

    printf("Sexo: ");
    scanf(" %c", &r1.sexo);

    printf("CPF: ");
    scanf("%d", &r1.cpf);

    printf("Data de nascimento: \n");
    printf("Dia: ");
    scanf("%d", &r1.nascimento.dia);
    printf("Mes: ");
    scanf("%d", &r1.nascimento.mes);
    printf("Ano: ");
    scanf("%d", &r1.nascimento.ano);

    printf("Codigo do setor: \n");
    scanf("%d", &r1.codSetor);

    printf("Cargo de ocupacao: \n");
    setbuf(stdin, NULL);
    fgets(r1.cargo, 30, stdin);

    printf("Salario: \n");
    scanf("%f", &r1.salario);

    printf("\n\n------------Dados Fornecidos---------\n");
    printf("Nome: %sIdade: %d\nSexo: %c\nCPF: %d\nData de nascimento : %d/%d/%d\nCodigo do setor: %d\nCargo ocupado: %sSalario: %.2f\n\n", r1.nome, r1.idade, r1.sexo, r1.cpf, r1.nascimento.dia, r1.nascimento.mes, r1.nascimento.ano, r1.codSetor, r1.cargo, r1.salario);

    return 0;
}
