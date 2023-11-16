#include <stdio.h>
#include <string.h>

// Definição da estrutura da pilha
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Função para criar uma pilha
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Função para verificar se a pilha está vazia
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Função para empilhar um caractere na pilha
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Função para desempilhar um caractere da pilha
char pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

// Função para inverter as letras de cada palavra em um texto
void reverseWords(char* texto) {
    int length = strlen(texto);
    struct Stack* stack = createStack(length);

    for (int i = 0; i < length; i++) {
        if (texto[i] != ' ' && texto[i] != '.') {
            push(stack, texto[i]);
        } else {
            while (!isEmpty(stack)) {
                printf("%c", pop(stack));
            }
            printf("%c", texto[i]);
        }
    }
    free(stack);
}

int main() {
    char texto[] = "ESTE EXERCICIO E MUITO FACIL.";
    
    printf("Texto invertido:\n");
    reverseWords(texto);
    
    return 0;
}