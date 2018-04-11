#ifndef LISTA_TELEFONICA_H_INCLUDED
#define LISTA_TELEFONICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Estruturas e protótipos */

#define TAM 50 /* definindo o tamanho da variavel */

typedef struct
{
    /* Criando a estrutura principal que contem o nome, telefone e endereço das pessoas */
    char nome[TAM];
    char telefone[TAM];
    char endereco[TAM];
}CONTATO;

typedef struct
{
    /* criando uma estrutura secundária que será a lista */
    CONTATO C[TAM];
    int nroElem;
}LISTA;

void inicializaLista(LISTA *l); /* inicializa a lista zerando o numero de elementos */
void tamanhoLista(LISTA *l); /* retorna o tamanho atual da lista */
void exibeLista(LISTA *l); /* exibe na tela os contatos já inseridos na lista */
void insereContato(LISTA *l, CONTATO contato); /* insere novos contatos, em ordem alfabética por nome */
void buscaSequencial(LISTA *l, char* busca); /* faz a busca na lista, pelo modo sequencial */
void excluiContato(LISTA *l, char* cont); /*exclui um contato da lista */
int buscaBinaria(LISTA *l, char* busca); /* faz a busca na lista, de modo binario */
void reinicializar(LISTA *l); /* Reinicia a lista */



#endif // LISTA_TELEFONICA_H_INCLUDED
