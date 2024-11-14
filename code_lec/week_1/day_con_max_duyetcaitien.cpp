#include<stdio.h>
#define MIN -1000

int main(){
	int i,j = 0;
	int a[]={1,2,-11,20,1,-14,3,8};
	int maxSum = MIN;
	for(i = 0;i<7;i++){
		int sum = 0;
		for(j = i;j<8;j++){
			sum += a[j];
			if(maxSum<sum) maxSum = sum;
		}
	}
	printf("%d",maxSum);
}
