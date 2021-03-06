#include "TLSE.h"

TLSE* inserel(TLSE *l, int elem){
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->prox = l;
  novo->info = elem;
  return novo;
}

TLSE* inseref(TLSE *l, int elem){
  TLSE* inicio = l;
  if(l) {
    while(l->prox) l = l->prox;
    TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
    novo->prox = NULL;
    novo->info = elem;
    l->prox = novo;
  } else {
    return inserel(l,elem);
  }
  return inicio;
}


void imprimel(TLSE *l){
  TLSE *p = l;
  while(p){
    printf("% d ", p->info);
    p = p->prox;
  } 
}

void liberal(TLSE *l){
  TLSE *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  } 
}

TLSE* retiral(TLSE *l, int elem){
  TLSE *p = l, *ant = NULL;
  while((p) && (p->info != elem)){
    ant = p;
    p = p->prox;
  }
  if(!p) return l;
  if(!ant) l = l->prox;
  else ant->prox = p->prox;
  free(p);
  return l;
}

TLSE* buscal(TLSE *l, int elem){
  TLSE *p = l;
  while((p) && (p->info != elem)) p = p->prox; 
  return p;
}

