#include<stdio.h>

int n = 10;

void sol(int source[], int length){
	for(int i = 0;i < length;i++){
		printf("%d ",source[i]);
	}
	printf("\n");
}

void Try(int source[], int k){
	if(k == n) {
	sol(source, n);
	return;}
	for(int i = 0;i<=1;i++){
		source[k] = i;
		Try(source,k+1);
	}
}
int main(){
	int source[n];
	Try(source,0);
	return 0;
}
