#ifndef CLIENTE_H
#define CLIENTE_H

/**
 * Estrutura que representa um cliente.
 */
typedef struct cliente Cliente;

/*
 * Cria um novo cliente com as informacoes fornecidas.
 */
Cliente *cria_cliente(const char *nome, const char *bairro, int pessoas,
                      int criancas, float renda);

/* Libera a memoria associada ao cliente. */
void destroi_cliente(Cliente *cliente);

/* Funcoes de acesso aos campos do cliente */
const char *get_nome(const Cliente *cliente);
const char *get_bairro(const Cliente *cliente);
int get_pessoas(const Cliente *cliente);
int get_criancas(const Cliente *cliente);
float get_renda(const Cliente *cliente);

#endif /* CLIENTE_H */
