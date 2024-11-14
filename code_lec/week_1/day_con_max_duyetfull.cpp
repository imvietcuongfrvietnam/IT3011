#include<stdio.h>
#define MIN -1000
int main(){
	int a[]={1,2,-11,20,1,-14,3,8};
	int maxSum = MIN;
	int i,j,k = 0;
	for(i = 0;i<7;i++){
		for(j = i;j<8;j++){
			int sum = 0;
			for(k = i;k<=j;k++){
				sum += a[k];
			}
			if(maxSum<sum) maxSum = sum;
		}
	}
	printf("%d",maxSum);
}
