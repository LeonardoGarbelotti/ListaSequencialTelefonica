
#include "Lista_Telefonica.h";


/* Funções e procedimentos */

void inicializaLista(LISTA *l)
{
    /* inicializa a lista zerando o numero de elementos */
    l->nroElem = 0;
}

void tamanhoLista(LISTA *l)
{
    /* retorna o tamanho atual da lista */
    return (l->nroElem);

}

void exibeLista(LISTA *l)
{   /* um laço de repetiçao, iniciando em 0 até o ultimo elemento da lista, exibe na tela os contatos inseridos */
    printf("\n\n----------EXIBIR LISTA----------------");
    int i;
    for(i=0; i<l->nroElem; i++)
    {
        printf("\n pos =[ %d], [nome = %s], [telefone = %s], [endereco = %s]", i, l->C[i].nome, l->C[i].telefone, l->C[i].endereco);
    }
}

void insereContato(LISTA *l, CONTATO contato)
{
    int i;

    if (l->nroElem >= TAM)
    {
        /* checar se existe espaços disponíveis para inserir um novo elemento */
        printf("\nLista cheia");
        return;
    }
    /* começa do ultimo contato, até o primeiro. Compara o ultimo contato com o novo contato inserido. Se retornar um valor >0, significa
    que o novo contato inserido(string2), é menor que o contato já existente(string1). Aceito estas condições, terá uma troca de índex.
    O contato de index(i-1) será copiado para um novo index ~i~ */
    for(i=l->nroElem; i>0 && strcmp(l->C[i-1].nome, contato.nome)>0 ; i--)
    {
        l->C[i] = l->C[i-1]; /* troca as posições */

      /* Equivalente a linha de cima
        strcpy(l->C[i].nome, l->C[i-1].nome);
        strcpy(l->C[i].telefone, l->C[i-1].telefone);
        strcpy(l->C[i].endereco, l->C[i-1].endereco); */

    }
    strcpy(l->C[i].nome, contato.nome); /*atribui o valor inserido na main para o novo index */
    strcpy(l->C[i].telefone, contato.telefone);
    strcpy(l->C[i].endereco, contato.endereco);
    l->nroElem = l->nroElem+1; /* incrementa o numero de elementos da lista */

    return 1;
}

void buscaSequencial(LISTA *l, char* busca)
{
    int i=0;
    if(l->nroElem == 0) return -1; /*se não houver elemento na lista, nao faz a busca */

    while(i < l->nroElem)
    {
        /* Enquanto i < numero de elementos, vai fazer uma comparação do ponteiro 'busca', que contem a string
        que desejo procurar. A função strcmp vai comparar a string de busca com o contato da lista. Se retornar 0,
        significa que as strings comparadas são iguais,assim imprimindo as informações */

        if(strcmp(busca, l->C[i].nome) ==0 || strcmp(busca, l->C[i].telefone) ==0 || strcmp(busca, l->C[i].endereco) ==0)
        {
            printf("\n pos =[ %d], [nome = %s], [telefone = %s], [endereco = %s]", i, l->C[i].nome, l->C[i].telefone, l->C[i].endereco);

            return i;
        }

        i++;
    }
    return -1;
}

int buscaBinaria(LISTA *l, char* busca)
{
    int inicial = 0;
    int fim = l->nroElem;
    int pos = (inicial + fim)/2;

    /* Define uma variavel para o inicio e para o fim da lista. Acha-se o meio da lista.
    Aqui, a comparação de string vai correr enquanto a string de busca for diferente da string que a posição
    selecionou && enquanto a posição inicial for menor ou igual a final. */
    while(strcmp(busca, l->C[pos].nome) !=0 && inicial <= fim){
        if(strcmp(l->C[pos].nome, busca)<0){
            /* Aqui, se a comparação do contato na posição resultada com a busca for menor que 0, significa
            que a string 1 é menor que a string 2 e assim, a variavel inicial ira receber a posiçao antiga +1
            e depois repetir o laço procurando o elemento para a direita da lista*/
            inicial = pos +1;
        }else{
            /* Senão, a comparação ira resultar num numero > 0, significando que a string1 é maior que a string 2
            Assim, o fim se tornará um número menor que a posição antiga, procurando o contato pela esquerda
            da lista */
            fim = pos-1;
        }
        pos = (inicial + fim)/2;
    }
    /* se a comparação da busca com a posição do contato for igual, retornará a posição que foi encontrado */
    if(strcmp(busca,l->C[pos].nome)== 0){
        return pos;
    }
    return -1;
}

void excluiContato(LISTA *l, char* cont)
{
    int pos, j;
    pos = buscaBinaria(l, cont);
    /* Nesta função de excluir, usaremos o procedimento da busca binária, que retornará
    a posição em que o contato foi encontrado. Com essa posição guardada numa variável,
    verificaremos se ela existe na lista. Se existir, essa posição entrará num laço de repetição
    que percorre até o fim da lista e que irá somando e subscrevendo os valores do indice.
    Ao final é diminuído o número de elementos */

    if(pos == -1){
        printf("\n Nao foi possivel excluir!");
        return;
    }
    for(j = pos; j < l->nroElem-1; j++){
        l->C[j] = l->C[j+1];
    }
    l->nroElem=l->nroElem-1;
    printf("\nO contato foi excluido!");
}

void reinicializar(LISTA *l)
{
    /* este procedimento ira zerar o tamanho da lista */
    l->nroElem = 0;
}
