#include<stdio.h>
//So fibonaci thu n bang de quy

int Fibo(int n){
	if(n == 1) return 0;
	if(n == 2) return 1;
	 else return Fibo(n-1) + Fibo(n-2);
}

int Fibo_no_rec(int n){
	int i = 0;
	int j = 1;
	for(int k = 0;k<=n-2;k++){
		j = i + j;
		i = j - i;
	}
	return i;
}
int main(){
	int n;
	scanf("%d",&n);
	printf("So fibo thu %d la %d",n,Fibo(n));
	printf("\nSo fibo thu %d la %d",n, Fibo_no_rec(n));
	return 1;
}
