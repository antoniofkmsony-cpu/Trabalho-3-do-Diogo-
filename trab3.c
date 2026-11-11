#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    struct No *proximo;
    int tipo;
    void *dados;
} No;

No *inserirInteiro(No *inicio, int valor) {
    No *novo;
    No *aux;
    int *numero;

    novo = (No *) malloc(sizeof(No));
    numero = (int *) malloc(sizeof(int));

    if (novo == NULL || numero == NULL) {
        printf("Erro ao alocar memoria.\n");
        return inicio;
    }

    *numero = valor;
    novo->tipo = 1;
    novo->dados = numero;
    novo->proximo = NULL;

    if (inicio == NULL) {
        return novo;
    }

    aux = inicio;

    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }

    aux->proximo = novo;

    return inicio;
}

void imprimirLista(No *inicio) {
    No *aux;

    aux = inicio;

    while (aux != NULL) {
        if (aux->tipo == 1) {
            printf("Inteiro: %d\n", *((int *) aux->dados));
        }

        aux = aux->proximo;
    }
}

void liberarLista(No *inicio) {
    No *aux;

    while (inicio != NULL) {
        aux = inicio;
        inicio = inicio->proximo;

        free(aux->dados);
        free(aux);
    }
}

int main() {
    No *inicio;

    inicio = NULL;

    inicio = inserirInteiro(inicio, 10);
    inicio = inserirInteiro(inicio, 20);
    inicio = inserirInteiro(inicio, 30);

    printf("Lista de inteiros:\n");
    imprimirLista(inicio);

    liberarLista(inicio);

    return 0;
}
