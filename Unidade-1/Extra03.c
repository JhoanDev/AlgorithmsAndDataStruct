#include <stdio.h>

void  inverte(int vet [], int n);

int main (){
	int n;
	printf("insira o tamanho do seu vetor: ");
	scanf("%d",&n);
	int vet[n];
	printf("vetor inicial:");
	for(int i=0; i<n; i++){
		vet[i] = i;
		printf("%d ",vet[i]);
	}
	printf("\n");
	inverte(vet,n);
	return 0;
}

void inverte(int vet [], int n){
	n = n-1;
	int j = n;
 	for(int i=0; i<=n/2 ; i++){
 		int b = vet[j];
 		vet[j] = vet[i];
 		vet[i] = b;
 		j--;
	}
	for(int i=0; i<=n; i++){
		printf("%d ",vet [i]);
	}
}
