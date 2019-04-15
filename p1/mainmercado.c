#include "mercado.h"

int main(void){
  int n;
  scanf("%d", &n);
  if(n <= 0) return 0;

  TPROD **vet = aloca(n);
  leitura(vet, n);
  printf("Antes da ordenacao...\n");
  escrita(vet, n);
  if(n == 1){
    libera(vet, n); 
    return 0;
  }

  ordena1(vet, n);
  printf("Depois da ordenacao 1...\n");
  escrita(vet, n);
  ordena2(vet, n);
  printf("Depois da ordenacao 2...\n");
  escrita(vet, n);

//   ordena_geral(vet, n, cmpf1);
//   printf("Depois da ordenacao geral 1...\n");
//   escrita(vet, n);
//   ordena_geral(vet, n, cmpf2);
//   printf("Depois da ordenacao geral 2...\n");
  escrita(vet, n);

  libera(vet, n);
  return 0;
}
