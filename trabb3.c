No *inserirInteiro(No *inicio, int valor) {
    No *novo;
    No *aux;
    int *numero;

    novo = (No *) malloc(sizeof(No));
    numero = (int *) malloc(sizeof(int));

    if (novo == NULL || numero == NULL) {
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
