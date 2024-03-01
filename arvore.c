#include <stdio.h>
#include <stdlib.h>


typedef struct Arvore{
    int valor;
    struct Arvore *esquerda, *direita;
}Arvore;


Arvore *inserir(Arvore *raiz, int valor){
    if (raiz == NULL){
        Arvore *aux = (Arvore*) malloc(sizeof(Arvore));
        aux->valor = valor;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if (valor < raiz->valor){
            raiz->esquerda = inserir(raiz->esquerda, valor);
        }
        else{
            raiz->direita = inserir(raiz->direita, valor);
        }
        return raiz;
    }
}


void imprimir(Arvore *raiz){
    if (raiz){
        printf("%d\n", raiz->valor);
        imprimir(raiz->esquerda);
        imprimir(raiz->direita);
    }
}


int main(){
    Arvore *raiz = NULL;
    
    int opcao, valor;
    
    do{
        printf("1 - Inserir\n2 - Imprimir\n3 - Encerrar\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                printf("Valor a inserir: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            case 2:
                imprimir(raiz);
                break;
            case 3:
                printf("... Encerrando ...");
                break;
            default:
                printf("Valor inválido");
        }
        
    }while (opcao != 3);
    
    return 0;
}
