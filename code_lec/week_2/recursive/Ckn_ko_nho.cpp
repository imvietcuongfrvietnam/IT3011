#include<stdio.h>

//Tinh Ckn bang de quy

int C(int k, int n){
	if(k == n || k == 0) return 1;
	else return C(k-1,n-1) + C(k,n-1);
}

int main(){
	int n, k;
	scanf("%d%d",&k,&n);
	printf("Ckn = %d",C(k,n));
	return 0;
}
