#include<stdio.h>
#define MAX 100

int n = 11;
int k = 7;

int B[MAX], C[MAX];

void counting_sort(int A[], int B[], int k, int lenA){
	for(int i = 0;i<=k;i++){
		C[i] = 0;
	}
	
	for(int j = 0;j<lenA;j++){
		C[A[j]] += 1;
	}
	
	for(int i = 1 ;i<=k;i++){
		C[i] = C[i] + C[i-1];
	}
	
	for(int i = lenA;i>=1;i--){
		B[C[A[i]]] = A[i];
		C[A[i]] --;
	}
	
}
int main(){
	int A[11] = {6, 1, 3, 1, 2, 4, 5, 7, 2, 4, 3};
	counting_sort(A, B, 7, 11);
	for(int i = 1;i<=11;i++){
		printf("%d ",B[i]);
	}
	return 0;
}
