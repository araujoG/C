#include <stdio.h>

void derivar(int *vet, int grau,int i){
	int deriv[grau];
	printf("Derivada =");
	for(i=1;i<grau+1;i++){
		deriv[i-1] = vet[i] * i;
		if (deriv[i-1]<0){
			printf(" %dX^%d",deriv[i-1],(i-1));
		}else {
			printf(" +%dX^%d",deriv[i-1],(i-1));
		}
		
	}
	printf("\n");
}

void integrar(int *vet){}

int main(void){
	do{
		int grau,i;
		scanf("%d",&grau);
		if (grau<1) break;
		int vet[grau+1];
		for(i=0;i<grau+1;i++){
			scanf("%d",&vet[i]);
		}
		derivar(vet,grau,i);
		//integrar(vet,grau,i)
	}while(1);

}