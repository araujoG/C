#include "TLSE.h"

int main(void){
	int i,n,elem;
	TLSE* l1 = (TLSE*) malloc(sizeof(TLSE));
	l1 = NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("%d: ",n-i);
		scanf("%d",&elem);
		l1 = inserel(l1,elem);
	}
	//l1 = inverteB(l1);
	int x;
	scanf("%d",&x);
	miscA(l1,x);
	// l1 = misc(l1,x);
	//inverteA(l1);
	// ordenaB(l1);
	// printf("Antes da ordenação: \n");
	// imprimel(l1);
	// printf("\n");
	// printf("Depois da ordenação: \n");
	// ordenaA(l1);
	// imprimel(l1);
	// printf("\n");

}