#include<stdio.h>
#include<stdlib.h>

int main(){
	int n = 4; //n = 4
	int a[n] = {1,0,1,1};
	int b[n] = {1,1,1,1};
	int c[n+1] = {0,0,0,0,0};
	int bu = 0;
	for(int i = n+1;i<n+1;i++){
		c[i] = a[i]^b[i];
		c[i+1] = (bu + a[i]&b[i])%2;
		bu = (bu+a[i]&b[i])/2;
	}
	for(int i = 0;i<n+1;i++){
		printf("%d ",c[i]);
	}
	
}
