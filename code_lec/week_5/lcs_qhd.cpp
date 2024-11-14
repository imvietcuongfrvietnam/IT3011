#include<stdio.h>
#define MAX 100

int max(int i, int j){
	if(i>j) return i;
	return j;
}
int lcs_array[30][30];

char a[MAX] = {'K', 'J', 'C', 'D', 'E', 'F', 'G'};
char b[MAX] = {'C', 'C', 'E', 'D', 'E', 'G', 'F'};

int check[30][30];
int lcs(int i, int j){
	
	if(i == -1) return 0;
	
	if(j == -1) return 0;
	if(!check[i][j]){
	if(a[i] == b[j]){
		lcs_array[i][j] = lcs(i-1, j-1) +1;
		check[i][j] = 1;
	}
	else{
		lcs_array[i][j] =  max(lcs(i-1, j),lcs(i, j-1));
		check[i][j] = 1;
	}
}		
	return lcs_array[i][j];
}

int main(){	
	printf("%d", lcs(6,6));
}
