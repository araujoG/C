#include <stdio.h>
#include <stdlib.h>

typedef struct intint{
  int num;
  struct intint *prox, *ant;
}tii;

typedef struct descritor{
    tii *prim, *ult;
    int ncarac;
    char sinal;
}tdesc;

tdesc* inicializa(); //aloca espaço para um num intint
tdesc* leituranum(); //lê a string e retorna o descritor da lista com aql num
tii* insere(tdesc *desc, int elem); //insere um elmento no inidio da lista apontada pelo descritor 
int ehzero(tdesc *desc); //vê se um numero intint é zero
tdesc* operacao(tdesc* numa, char *op, tdesc* numb); //seleciona a operação
void imprime(tdesc *desc); //imprime um número intint atraves do descritor
int intintcmp(tii *numa, tii *numb); //compara uma lista intint
int comparacao(tdesc *numa, tdesc *numb); //compara um numero intint pelo descritor
tdesc* intintcpy(tdesc *numb); // copia um numero intint para outro
void liblista(tdesc *l); //libera apenas a lista e preserva o descritor
void libtudo(tdesc *l); //Libera toda a estrutura
void somador(tdesc *numa); //equivalente ao i++
tdesc* soma(tdesc *numa,tdesc *numb); //soma 2 num intint
tdesc* subtracao(tdesc *numa,tdesc *numb); //subtrai 2 num intint
tdesc* multiplicacao(tdesc *numa,tdesc *numb); //multiplica 2 num intint
tdesc* divisao(tdesc *numa,tdesc *numb); //divide 2 num intint
void retira_zero(tdesc *desc); //retira os zeros iniciais de um número intint
int tamanho(tdesc *desc);

/*
  Gabriel Araujo: Função de entrada e divisão
  Jhonatan Azevedo : retirazero, subtração e multiplicação
  Lucas Amaral : main, soma, multiplicação
*/


