#include <stdio.h>
#include <stdlib.h>

// NÂO DA PRA TESTAR SEM O INSERE

typedef struct lista{
  int mat;
  char nome[81];
  float cr;
  struct lista *prox;
} TLSE;

void imprimel(TLSE *l){
  TLSE *p = l;
  while(p){
    printf("% d ", p->info);
    p = p->prox;
  } 
}

TLSE* inserel(TLSE *l, int elem){
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->prox = l;
  novo->info = elem;
  return novo;
}

int igual(TLSE *l1, TLSE *l2){
    if (l1 && l2){
        if (l1->mat == l2->mat){
            if (l1->cr == l2->cr){
                if (!(strcmp(l1->nome,l2->nome))){
                    l1 = l1->prox;
                    l2 = l2->prox;
                    igual(TLSE *l1, TLSE *l2);
                } else return 0;
            }else return 0;
        }else return 0;
    }else{
        if (!l1 && !l2){
            return 1;
        }else return 0;
    }
}


int main(){
    TLSE* lista = (TLSE*) malloc(sizeof(TLSE));
    lista = NULL;
    lista = inserel(lista,1);
    lista = inserel(lista,3);
    lista = inserel(lista,9);
    TLSE* lista1 = (TLSE*) malloc(sizeof(TLSE));
    lista1 = NULL;
    lista1 = inserel(lista,8);
    lista1 = inserel(lista,5);
    lista1 = inserel(lista,6);
    imprimel(lista);
    printf("\n");
    imprimel(lista1);
    printf("%d\n",igual(lista,lista1));
    return 0;
}