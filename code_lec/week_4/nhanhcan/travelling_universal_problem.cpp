#include<stdio.h>
#define MAX 100000
int c[MAX][MAX];

int visited[MAX];

int x[MAX];

const int cmin = 3;

int n = 5;

long fopt = MAX;

long f = 0;


void travel_min_distance(int k, int n){
for(int i = 2;i<=n;i++){
	if(!visited[i]){
		visited[i] = 1;
		f = f + c[x[k-1]-1][i-1];
		if( k == n){
			f += c[x[n]-1][0];
			if(f < fopt) fopt = f;
		}
		else {
			if(f += (n-k)*cmin > fopt) return;
		};
		travel_min_distance(k+1,n);
		f -= c[x[k-1]-1][i-1];
		visited[i] = 0;
	}		 
}	
}
int main(){
	x[1] = 1;
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			scanf("%d", &c[i][j]);
		}
	}
	travel_min_distance(1, n);
	printf("%ld", fopt);
}
