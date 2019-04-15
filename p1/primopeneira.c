#include <stdio.h>

int peneira(int *vet,int n){
	int i,j;
	for(i=0;i<n-1;i++){
		if (vet[i]){
			for(j=i+1;j<n-1;j++){
				if(!(vet[j]%vet[i])) vet[j] = 0;
			}
		} 
	}
	for(i=0;i<n-1;i++){
		if(vet[i]) printf("%d\n",vet[i]);
	}	
}

int main(void){
	int n,i;
	do{
		scanf("%d",&n);
		if (n<2) break;
		int vet[n-1];
		for(i=0;i<n-1;i++){
			vet[i]=i+2;
		}
		peneira(vet,n);
	}while(1);
}