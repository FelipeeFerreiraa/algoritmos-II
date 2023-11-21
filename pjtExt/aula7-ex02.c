
/*
Construa uma estrutura aluno com nome, número de matrícula e curso. Leia do usuário a
informação de 5 alunos, armazene em vetor dessa estrutura e imprima os dados na tela
*/

#include <stdio.h>
#include <string.h>

typedef struct aluno
{
    char nome[50], curso[50];
    int matricula;
} aluno;

int main()
{

    aluno a[5];

    printf("Forneça os dados de cinco alunos: \n");
    for (int x = 0; x < 5; x++)
    {
        printf("\nAluno %d: \n", x + 1);

        printf("Nome: ");

        setbuf(stdin, NULL);
        fgets(a[x].nome, 50, stdin);

        printf("Curso: ");
        setbuf(stdin, NULL);
        fgets(a[x].curso, 50, stdin);

        printf("Matricula: ");
        scanf("%d", &a[x].matricula);
    }

    printf("\n\nDados dos alunos: \n");
    for (int x = 0; x < 5; x++)
    {
        printf("\nAluno %d: \n", x + 1);

        printf("Nome: %s", a[x].nome);

        printf("Curso: %s ", a[x].curso);

        printf("Matricula: %d \n\n", a[x].matricula);
    }

    return 0;
}