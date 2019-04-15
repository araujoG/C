#include <stdio.h>
#include <stdlib.h>

typedef struct lsec{
  int info;
  struct lsec *prox;
} TLSEC;

TLSEC* ins_ordem1(TLSEC *l, int info){
  TLSEC* novo = (TLSEC*) malloc (sizeof(TLSEC));
  novo->info = info;
  if(!l){
    novo->prox = novo;
    return novo;
  }
  novo->prox = l->prox;
  l->prox = novo;
  return l;
}


TLSEC* ins_fim(TLSEC *l, int info){
  if((!l) || (l->prox == l)) return ins_ordem1(l, info);

  TLSEC *p = l->prox;
  while(p->prox != l) p = p->prox;

  TLSEC *novo = (TLSEC*) malloc (sizeof(TLSEC));
  novo->info = info;
  novo->prox = l;
  p->prox = novo;
  return l;
}


TLSEC* retira(TLSEC *l, int info){
  if((!l) || ((l->prox == l) && (l->info == info))){
    if(l) free(l);
    return NULL;
  }

  TLSEC *p = l->prox, *ant = l;
  while((p != l) && (p->info != info)){
    ant = p;
    p = p->prox;
  }

  if((p == l) && (l->info != info)) return l;
  if(p == l) l = l->prox;
  ant->prox = p->prox;
  free(p);
  return l;
}
 

void imprime(TLSEC *l){
  if(l){
    printf("%d ", l->info);
    TLSEC *p = l->prox;
    while(p != l){
      printf("%d ", p->info);
      p = p->prox;
    }
    printf("\n");
  }
}


void libera(TLSEC *l){
  if(l){
    TLSEC *p = l->prox;
    while(p != l){
      TLSEC *temp = p;
      p = p->prox;
      free(temp);
    }
    free(l);
  }
}


TLSEC* desloca (TLSEC *l, int i){
    TLSEC* fim = l->prox;
    TLSEC* inicio = l->prox;
    if(i%2){
        while(inicio->prox != l){
            fim = fim->prox;
            inicio = inicio->prox;
        }
    }
    fim = fim->prox;
    TLSEC* resp = (TLSEC*)malloc(sizeof(TLSEC));
    resp = NULL;
    while(1){
        resp = ins_fim(resp, inicio->info);
        inicio = inicio->prox;
        if (inicio->prox == fim) break;
    }
    return resp;
}

int main(){
    TLSEC* lista = (TLSEC*)malloc(sizeof(TLSEC));
    lista = NULL;
    lista = ins_fim(lista, 1);
    lista = ins_fim(lista, 2);
    lista = ins_fim(lista, 3);
    lista = ins_fim(lista, 4);
    imprime(lista);
    printf("\n");
    TLSEC* resp = desloca(lista,3);
    imprime(resp);
    printf("\n");
}