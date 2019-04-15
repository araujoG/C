#include <stdio.h>
int main(void){
	do{
		int limite,base,pot,parou;
		scanf("%d",&base);
		scanf("%d",&limite);
		if (base<2 && base>-2) return 0;
		printf("1\n");
		printf("%d\n",base);
		pot = base;
		while (1){
			pot *= base;
			if (pot<=limite){
				printf("%d\n",pot);
			}else break;
		}
	}while(1);
}