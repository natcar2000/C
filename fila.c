#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int valor;
    struct No *proximo;
}No;

typedef struct Fila{
    No *inicio;
    No *fim;
    int tam;
}Fila;


void push(Fila *fila, int valor){
    No *elemento = (No*) malloc(sizeof(No));
    elemento->valor = valor;
    
    if (fila->inicio == NULL){
        elemento->proximo = NULL;
        fila->inicio = elemento;
        fila->fim = elemento;
    }
    else{
        fila->fim->proximo = elemento;
        fila->fim = elemento;
    }
    fila->tam++;
}


void pop(Fila *fila){
    No *elemento = NULL;
    if (fila->inicio != NULL){
        elemento = fila->inicio;
        fila->inicio = elemento->proximo;
        fila->tam--;
    }
}


void imprimir(Fila *fila){
    No *inicio = fila->inicio;
    while (inicio != NULL){
        printf("%d\n", inicio->valor);
        inicio = inicio->proximo;
    }
}


int main() {
    Fila fila;
    
    fila.inicio = NULL;
    fila.tam = 0;
    
    int opcao, valor;
    
    do{
    
    printf("1 - Inserir\n2 - Remover\n3 - Imprimir\n4 -  Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    
    switch(opcao){
        case 1:
            printf("Valor a ser inserido: ");
            scanf("%d", &valor);
            push(&fila, valor);
            break;
        case 2:
            pop(&fila);
            break;
        case 3:
            imprimir(&fila);
            break;
        case 4:
            printf("... Encerrando ...");
            break;
        default:
            printf("Opção inválida.");
    }
    
    } while (opcao != 4);
    
    return 0;
}
