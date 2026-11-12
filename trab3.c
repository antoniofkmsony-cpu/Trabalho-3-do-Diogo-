#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

No *inserirTexto(No *inicio, char texto[]) {
    No *novo;
    No *aux;
    char *palavra;

    novo = (No *) malloc(sizeof(No));
    palavra = (char *) malloc((strlen(texto) + 1) * sizeof(char));

    if (novo == NULL || palavra == NULL) {
        printf("Erro ao alocar memoria.\n");
        return inicio;
    }

    strcpy(palavra, texto);

    novo->tipo = 2;
    novo->dados = palavra;
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
        else if (aux->tipo == 2) {
            printf("Texto: %s\n", (char *) aux->dados);
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
    inicio = inserirTexto(inicio, "Maria");
    inicio = inserirInteiro(inicio, 20);

    printf("Lista:\n");
    imprimirLista(inicio);

    liberarLista(inicio);

    return 0;
}
