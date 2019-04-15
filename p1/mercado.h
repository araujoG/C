#include <stdio.h>
#include <stdlib.h>

typedef struct data{
    int mes, ano;
}TD;

typedef struct prod{
    int cod;
    float peso, preco;
    TD *valid;
}TPROD;

TPROD **aloca(int n);
void libera (TPROD **prat, int n);
void leitura (TPROD **prat, int n);
void escrita (TPROD **prat, int n);
int cmpf1 (TPROD *p1, TPROD *p2);
void ordena1 (TPROD **prat, int n);
int cmpf2 (TPROD *p1, TPROD *p2); 
void ordena2 (TPROD **prat, int n);
