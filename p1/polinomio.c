#include <stdio.h>

void derivar(int *vet, int grau, int *derivada){
	int n;
	for(n=1;n<grau+1;n++){
		derivada[n-1]=vet[n]*n;
	}
}
void integrar(int *vet, int grau, int *integral){
	int m;
	integral[0] = 0;
	for(m=0;m<grau+2;m++){
		integral[m+1] = vet[m]/(m+1);
	}
}
int main(void){
	do{
		int grau;
		scanf("%d",&grau);
		if (grau<=0) return 0;
		int vet[grau+1],i;
		int derivada[grau];
		int integral[grau+2];
		for (i=0 ; i<grau+1 ; i++){
			printf("pos=%d\n",i );
			scanf("%d",&vet[i]);
		}
		derivar(vet,grau,derivada);
		integrar(vet,grau,integral);
		printf("%d\n",*derivada);
	}while(1);
}