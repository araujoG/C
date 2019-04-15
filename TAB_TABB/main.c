#include "TAB_TABB.h"

int main(void){
    // TAB* a = NULL;
    // a = cria_ab(2,cria_ab(5,cria_ab(8,cria_ab(15,NULL,NULL),cria_ab(15,NULL,NULL)),cria_ab(8,cria_ab(15,NULL,NULL),cria_ab(15,NULL,NULL))),cria_ab(5,cria_ab(8,cria_ab(15,NULL,NULL),cria_ab(15,NULL,NULL)),cria_ab(8,cria_ab(15,NULL,NULL),NULL)));
    
    //Quando as arvores são grandes
    TAB* a1 = NULL;
    a1 = cria_ab(2,cria_ab(5,cria_ab(8,cria_ab(15,NULL,NULL),cria_ab(15,NULL,NULL)),cria_ab(8,cria_ab(15,NULL,NULL),cria_ab(15,NULL,NULL))),cria_ab(5,cria_ab(8,cria_ab(15,NULL,NULL),cria_ab(15,NULL,NULL)),cria_ab(8,cria_ab(15,NULL,NULL),NULL)));
    
    TAB* a2 = NULL;
    a2 = cria_ab(2,cria_ab(5,cria_ab(8,cria_ab(15,NULL,NULL),cria_ab(15,NULL,NULL)),cria_ab(8,cria_ab(15,NULL,NULL),cria_ab(15,NULL,NULL))),cria_ab(5,cria_ab(8,cria_ab(15,NULL,NULL),cria_ab(15,NULL,NULL)),cria_ab(8,cria_ab(15,NULL,NULL),NULL)));
      
    // TAB* a1 = NULL;
    // a1 = cria_ab(3, NULL,cria_ab(5,NULL,cria_ab(5,NULL,NULL)));

    // TAB* a2 = NULL;
    // a2 = cria_ab(3,NULL,cria_ab(5,NULL,cria_ab(3,NULL,NULL)));

    // TAB* a1 = NULL;
    // a1 = insere_abb(7, a1);
    // a1 = insere_abb(3, a1);
    // a1 = insere_abb(1, a1);
    // a1 = insere_abb(5, a1);
    // a1 = insere_abb(9, a1);
    // a1 = insere_abb(11, a1);
    // a1 = insere_abb(14, a1);

    imprime_ab(a1);
    printf("\n\n");
    imprime_ab(a2);
    
    // TLSE* l1 = (TLSE*) malloc(sizeof(TLSE));
	// l1 = NULL;
    // l1 = ancestrais(a1,14);
    // if (l1){
    //     printf("Os ancestrais do nó são: ");
    //     imprimel(l1);
    //     printf("\n");
    // }else printf("O nó não pertence a essa árvore...\n");
    
    // liberal(l1);

    // if (zz_rec(a1)) printf("A árvore é um zique zague! \n");
    // else printf("A árvore não é um zique zague... \n");
    
    // if (estbin(a1)) printf("A árvore é binária! \n");
    // else printf("A árvore não é binária... \n");

    if (mn(a1, a2)) printf("As árvores são iguais! \n");
    else printf("As árvores são diferenes... \n");
}