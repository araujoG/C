#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct NO{
    int info;
    struct NO * prox;
}TNO;

typedef struct fila{
    TNO *ini, *fim;
}TFILA;

void inseref(TFILA* f, int elem);
int retiraf(TFILA *f);
int vaziaf(TFILA *f);
void liberaf(TFILA *f);
void imprimef(TFILA *f);
TFILA* criaf(void);