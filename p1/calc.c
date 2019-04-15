#include <stdio.h>
int main (void){
	int a,b;
	char op;
	do{	
		printf("Digite a conta que será realizada:\n");
		scanf("%d",&a);
		scanf(" %c",&op);
		scanf("%d",&b);
		switch(op){
			case('+'):
				printf("%d\n",a+b);
				break;
			case('-'):
				printf("%d\n",a-b);
				break;
			case('*'):
				printf("%d\n",a*b);
				break;
			case('/'):
				if(!b){
					printf("Divisão por zero!!!\n");
					break;
				}else{
					printf("%d\n",a/b);
					break;
				}
			default:
				break;
		}
	}while(1);
}

