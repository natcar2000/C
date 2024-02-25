#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int valor;
    struct No *proximo;
}No;

typedef struct Pilha{
    No *inicio;
    int tam;
}Pilha;


void push(Pilha *pilha, int valor){
    No *elemento = (No*) malloc(sizeof(No));
    elemento->valor = valor;
    
    if (pilha->inicio == NULL){
        elemento->proximo = NULL;
        pilha->inicio = elemento;
    }
    else{
        elemento->proximo = pilha->inicio;
        pilha->inicio = elemento;
    }
    pilha->tam++;
}


void pop(Pilha *pilha){
    No *elemento = NULL;
    if (pilha->inicio != NULL){
        elemento = pilha->inicio;
        pilha->inicio = elemento->proximo;
        pilha->tam--;
    }
}


void imprimir(Pilha *pilha){
    No *inicio = pilha->inicio;
    while (inicio != NULL){
        printf("%d\n", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n");
}

int main() {
    Pilha pilha;
    
    pilha.inicio = NULL;
    pilha.tam = 0;
    
    int opcao, valor;
    
    do{
    
    printf("1 - Inserir\n2 - Remover\n3 - Imprimir\n4 -  Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    
    switch(opcao){
        case 1:
            printf("Valor a ser inserido: ");
            scanf("%d", &valor);
            push(&pilha, valor);
            break;
        case 2:
            pop(&pilha);
            break;
        case 3:
            imprimir(&pilha);
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
