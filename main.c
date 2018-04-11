/* Nome: Leonardo Garbelotti Gonçalves

RA: 120157

Trabalho sobre listas sequenciais estáticas adaptada para uma lista telefônica, da matéria de Estrutura de Dados. */

#include "Lista_Telefonica.h"

int main()
{
    LISTA lista;
    CONTATO contato;
    CONTATO busca;

    inicializaLista(&lista); /* inicializando a lista */

    /* INFORMAÇÕES DOS USUÁRIOS */
    strcpy(contato.nome, "Zaeli");
    strcpy(contato.telefone, "3341-2132");
    strcpy(contato.endereco, "San Fernando");
    insereContato(&lista, contato);

    strcpy(contato.nome, "Kaik");
    strcpy(contato.telefone, "3341-2598");
    strcpy(contato.endereco, "San Pierro");
    insereContato(&lista, contato);

    strcpy(contato.nome, "Joao");
    strcpy(contato.telefone, "3341-8899");
    strcpy(contato.endereco, "San Bernardo");
    insereContato(&lista, contato);

    strcpy(contato.nome, "Amanda");
    strcpy(contato.telefone, "3341-2658");
    strcpy(contato.endereco, "San Felipe");
    insereContato(&lista, contato);

    strcpy(contato.nome, "Abelardo");
    strcpy(contato.telefone, "3341-1020");
    strcpy(contato.endereco, "San Toro");
    insereContato(&lista, contato);

     strcpy(contato.nome, "Natasha");
    strcpy(contato.telefone, "3341-0020");
    strcpy(contato.endereco, "San Toro");
    insereContato(&lista, contato);

    exibeLista(&lista); /* imprimir a lista */

    printf("\n----------BUSCA SEQUENCIAL----------------");
    buscaSequencial(&lista, "Amanda"); /* busca, passando como argumento o endereço da lista e a string a ser procurada */


    printf("\n----------BUSCA BINARIA----------------");
    int posicao = 0;
    posicao = buscaBinaria(&lista, "Kaik"); /* busca, passando como argumento o endereço da lista e a string a ser procurada */
    /* a busca binária retornara o valor da posição que o objeto foi encontrado, se a posição estiver na lista
    irá imprimir as informações */
    if(posicao != 1) {
        printf("\n pos =[ %d], [nome = %s], [telefone = %s], [endereco = %s]", posicao, lista.C[posicao].nome, lista.C[posicao].telefone, lista.C[posicao].endereco);
    } else {
        printf("\nNão encontrado!");
    }


    printf("\n\n----------EXCLUIR----------------");
    excluiContato(&lista, "Natasha");

    exibeLista(&lista);

    printf("\n\n----------REINICIALIZAR----------------");
    reinicializar(&lista);

    exibeLista(&lista);
    return 0;
}
