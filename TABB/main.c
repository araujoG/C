#include "TABB.h"
#include <stdio.h>

int main(void){
	TAB* a = inicializa();
    a = cria(4,cria(3,cria(1,cria(0,NULL,NULL),NULL),cria(5,NULL,NULL)),cria(9,cria(7,cria(8,NULL,NULL),NULL),cria(10,NULL,NULL)));
    int x;
    scanf("%d",&x);
    imp_pos(a);
    retira(a, x);
    printf("\n");
    imp_pos(a);
    printf("\n");
    // retira(a, 3);
    // imp_pos(a);
    // printf("\n");
    libera(a);
}