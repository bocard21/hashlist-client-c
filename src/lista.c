#include <stdlib.h>
#include "lista.h"

struct lista {
    Node *inicio;
    int quantidade;
};

Lista *cria_lista() {
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (!l) return NULL;
    l->inicio = NULL;
    l->quantidade = 0;
    return l;
}

void destroi_lista(Lista *lista, int free_clientes) {
    if (!lista) return;
    Node *atual = lista->inicio;
    while (atual) {
        Node *prox = get_next(atual);
        if (free_clientes)
            destroi_cliente(get_data(atual));
        destroi_node(atual);
        atual = prox;
    }
    free(lista);
}

void insere_lista(Lista *lista, Cliente *cliente) {
    if (!lista) return;
    Node *n = cria_node(cliente);
    if (!n) return;
    set_next(n, lista->inicio);
    lista->inicio = n;
    lista->quantidade++;
}

Node *get_inicio(Lista *lista) {
    return lista ? lista->inicio : NULL;
}

int get_quantidade(Lista *lista) {
    return lista ? lista->quantidade : 0;
}

