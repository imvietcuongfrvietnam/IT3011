#include<stdio.h>
#define MAX -1000
#include<math.h>

int a[1000];

int Max(int a, int b){
	if(a>b) return a;
	return b;
}

int main(){
	int max = MAX;
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",a+i);
	}	
	
	int ei = a[0];
	
	for(int i = 1;i<n;i++){
	ei = Max(ei+a[i], a[i]);
	max = Max(max, ei);
	}
	printf("%d",max);
	return 0;
}
