#include<stdio.h>
#define MAX 1000

int a[MAX];

int res[MAX];

int check[MAX]; //Luu vi tri cua phan tu tai chi so nao`

void ghinhan(int m){
	for(int i = 1;i<=m;i++){
		printf("%d ",res[i]);
	}
	printf("\n");
}

void Try(int k, int m, int n){
	if(k == m+1){
		ghinhan(m);
		return;
	}
	for(int i = check[k-1]+1;i<=n;i++){
		if(!check[i]){
			check[k] = i;
			res[k] = a[i];
			Try(k+1,m,n);
			check[k] = 0;
		}
	}		
	} 
int main(){
	int m,n;
	
	scanf("%d %d", &m, &n);

	for(int i = 1;i<=n;i++){
		scanf("%d",a+i);
	}	
	Try(1, m, n);

}
