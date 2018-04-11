
#include "Lista_Telefonica.h";


/* Fun��es e procedimentos */

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
{   /* um la�o de repeti�ao, iniciando em 0 at� o ultimo elemento da lista, exibe na tela os contatos inseridos */
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
        /* checar se existe espa�os dispon�veis para inserir um novo elemento */
        printf("\nLista cheia");
        return;
    }
    /* come�a do ultimo contato, at� o primeiro. Compara o ultimo contato com o novo contato inserido. Se retornar um valor >0, significa
    que o novo contato inserido(string2), � menor que o contato j� existente(string1). Aceito estas condi��es, ter� uma troca de �ndex.
    O contato de index(i-1) ser� copiado para um novo index ~i~ */
    for(i=l->nroElem; i>0 && strcmp(l->C[i-1].nome, contato.nome)>0 ; i--)
    {
        l->C[i] = l->C[i-1]; /* troca as posi��es */

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
    if(l->nroElem == 0) return -1; /*se n�o houver elemento na lista, nao faz a busca */

    while(i < l->nroElem)
    {
        /* Enquanto i < numero de elementos, vai fazer uma compara��o do ponteiro 'busca', que contem a string
        que desejo procurar. A fun��o strcmp vai comparar a string de busca com o contato da lista. Se retornar 0,
        significa que as strings comparadas s�o iguais,assim imprimindo as informa��es */

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
    Aqui, a compara��o de string vai correr enquanto a string de busca for diferente da string que a posi��o
    selecionou && enquanto a posi��o inicial for menor ou igual a final. */
    while(strcmp(busca, l->C[pos].nome) !=0 && inicial <= fim){
        if(strcmp(l->C[pos].nome, busca)<0){
            /* Aqui, se a compara��o do contato na posi��o resultada com a busca for menor que 0, significa
            que a string 1 � menor que a string 2 e assim, a variavel inicial ira receber a posi�ao antiga +1
            e depois repetir o la�o procurando o elemento para a direita da lista*/
            inicial = pos +1;
        }else{
            /* Sen�o, a compara��o ira resultar num numero > 0, significando que a string1 � maior que a string 2
            Assim, o fim se tornar� um n�mero menor que a posi��o antiga, procurando o contato pela esquerda
            da lista */
            fim = pos-1;
        }
        pos = (inicial + fim)/2;
    }
    /* se a compara��o da busca com a posi��o do contato for igual, retornar� a posi��o que foi encontrado */
    if(strcmp(busca,l->C[pos].nome)== 0){
        return pos;
    }
    return -1;
}

void excluiContato(LISTA *l, char* cont)
{
    int pos, j;
    pos = buscaBinaria(l, cont);
    /* Nesta fun��o de excluir, usaremos o procedimento da busca bin�ria, que retornar�
    a posi��o em que o contato foi encontrado. Com essa posi��o guardada numa vari�vel,
    verificaremos se ela existe na lista. Se existir, essa posi��o entrar� num la�o de repeti��o
    que percorre at� o fim da lista e que ir� somando e subscrevendo os valores do indice.
    Ao final � diminu�do o n�mero de elementos */

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
