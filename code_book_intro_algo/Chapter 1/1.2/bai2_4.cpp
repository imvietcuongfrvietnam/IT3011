#include<stdio.h>
#define n 4

int a[n] = {1,2,3,4};
int main(){
	//Thuat toan de hieu O(n2)
	int x = 4;
	int f = 0;
	for(int i = 0;i<4;i++){
		int ax = a[i];
		for(int j = 0;j<i;j++){
			ax *= x; 
		}
		f += ax;
	}
	printf("%d ",f);
	f = 0;
	
	//Horner O(n)
	int ax = 0;
	for(int i = n-1;i>=1;i--){
		ax = (ax+a[i]) * x; 
	}
	ax += a[0];
	printf("%d",ax);
	return 0;
}
