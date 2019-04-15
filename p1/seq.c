#include <stdio.h>

int main(void){
	int tamanho, num,numr,contr,cont=1;
	int i = 0;
	scanf("%d",&tamanho);
	scanf("%d",&numr);
	cont = contr= 0;
	while(i<tamanho-1){
		scanf("%d",&num);
		if (numr<num){
			cont+=1;
		}
		if(cont>contr && !(numr<num)){
			contr=cont;
		}
		numr = num;
		i++;
	}
	if (cont>contr){
		contr=cont;
	}
	printf("%d\n",contr);
}