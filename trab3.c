#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* tipo 1 = inteiro; tipo 2 = texto */
typedef struct No {
    struct No *proximo;
    int tipo;
    void *dados;
} No;

int main() {
    No *inicio = NULL;

    if (inicio == NULL) {
        printf("Lista vazia.\n");
    }

    return 0;
}
