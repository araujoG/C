#include <stdio.h>
#include <stdlib.h>

int* junta(int *vet1, int *vet2, int n1, int n2, int *n3){
	int i = 0;
	int j = 0;
	int pos = 0;
	int n = n1 + n2;
	n3 = &n;
	printf("%d",vet1[0]);
	int *resp = (int*)malloc((n)*sizeof(int));
	while (i<n1 && j<n2){
		if (vet1[i]<vet2[j]){
			resp[pos] = vet1[i];
			i++;
		}else{
			resp[pos] = vet2[j];
			j++;
		}
		pos++;
	}
	if(n1==i){
		for(j = i-1; j < n2; j++){
			resp[pos] = vet2[j];
			pos++;
		}
	}else{
		for(i = j-1; i < n1; i++){
			resp[pos] = vet1[i];
			pos++;
		}
	}
	return resp;
}
int main(){
	do{
		int *n3 = (int *)malloc(sizeof(int));
		int n1,n2;
		int *resp;
		scanf("%d%d", &n1, &n2);
		if ((n1<1 && n2<1)) break;
		int vet1[n1], vet2[n2];
		for (int i = 0; i < n1; ++i){
			scanf("%d",&vet1[i]);
		}
		for (int i = 0; i < n2; ++i){
			scanf("%d",&vet2[i]);
		}
		resp = junta(vet1, vet2, n1, n2, n3);
		//printf("%d %d %d %d\n",resp[0],resp[1],resp[2],resp[3] );
	}while(1);

}