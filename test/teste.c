#include <stdio.h>
#include "cliente.h"
#include "estrutura.h"
#include "lista.h"
#include "node.h"

void imprime(Cliente *cliente) {
    printf("Nome      ; %40s\nBairro    : %40s\nQ Pessoas : %40d\nCriancas  : %40s\nRenda     : %40.2f\n\n",
           get_nome(cliente), get_bairro(cliente), get_pessoas(cliente),
           get_criancas(cliente) == 0 ? "Nao": "Sim", get_renda(cliente));
}

int main() {
    Cliente *cliente[10];
    cliente[0] = cria_cliente("Alberto", "Centro", 3, 1, 4500.00f);
    cliente[1] = cria_cliente("Bernardo", "Ingleses", 1, 0, 1800.00f);
    cliente[2] = cria_cliente("Amarilis", "Trindade", 2, 0, 2980.00f);
    cliente[3] = cria_cliente("Rodolfo", "Centro", 5, 1, 6500.00f);
    cliente[4] = cria_cliente("Maria", "Trindade", 2, 1, 15800.00f);
    cliente[5] = cria_cliente("Marta", "Trindade", 1, 0, 8000.00f);
    cliente[6] = cria_cliente("Vanessa", "Centro", 3, 1, 8300.00f);
    cliente[7] = cria_cliente("Gilberto", "Ingleses", 2, 0, 4000.00f);
    cliente[8] = cria_cliente("Simone", "Centro", 1, 0, 5000.00f);
    cliente[9] = cria_cliente("Antonio", "Trindade", 4, 1, 3500.00f);

    Estrutura *estrutura = cria_estrutura();
    for (int i = 0; i < 10; i++) {
        insere_cliente(estrutura, BUSCA_NOME, cliente[i]);
        insere_cliente(estrutura, BUSCA_BAIRRO, cliente[i]);
        insere_cliente(estrutura, BUSCA_PESSOAS, cliente[i]);
        insere_cliente(estrutura, BUSCA_CRIANCAS, cliente[i]);
        insere_cliente(estrutura, BUSCA_RENDA, cliente[i]);
    }

    Lista *lista = recupera_cliente(estrutura, BUSCA_NOME, 0, "Vanessa");
    if (get_quantidade(lista) > 0) {
        Node *cursor = get_inicio(lista);
        while (cursor != NULL) {
            imprime(get_data(cursor));
            cursor = get_next(cursor);
        }
    }

    destroi_lista(lista, 0);
    destroi_estrutura(estrutura);
    for (int i = 0; i < 10; i++) destroi_cliente(cliente[i]);
    return 0;
}
