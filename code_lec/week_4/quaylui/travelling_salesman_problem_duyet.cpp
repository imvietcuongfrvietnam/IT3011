#include<stdio.h>
#define MAX 40
int check[MAX];

int c[MAX][MAX];
int sum = 0;
int fotp = 100000;

int res[MAX];

int thutu[MAX];
void ghinhan(int n){
	sum = c[0][res[1]-1];
	for(int i = 2;i<n;i++){
		sum += c[res[i-1]-1][res[i]-1];
	}
	sum+=c[res[n-1]-1][0];
	if(sum < fotp) {fotp = sum;
	for(int i = 1;i<n;i++)
	thutu[i] = res[i];
}
}

void Try(int k, int n){
	if(k == n){
		ghinhan(n);
		return;
	}
	for(int i = 2;i<=n;i++){
		if(check[i] == 0){
			res[k] = i;
			check[i] = 1;
			Try(k+1, n);
			check[i] = 0;
		}
		else continue;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	Try(1,n);
	printf("%d",fotp);
	printf("\n1 ");
	for(int i = 1;i<n;i++)
		printf("%d ",thutu[i]);
}
