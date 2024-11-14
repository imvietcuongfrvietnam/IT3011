#include<stdio.h>
#define MIN -1000000000
int max(int a,int b) {
	return a<b?b:a;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a[] = {1,2,-11,20,1,-14,3,8};
	int maxSum = -1000;
	int i=0;
	int ei = a[0];
	for(i = 1;i<8;i++){
		ei = max(ei+a[i],a[i]);
		if(maxSum<ei) maxSum = ei;
	}
	printf("%d",maxSum);
}

//luu giu vi tri i
//max tai day con tai vi tri thu i = max giua max cua day ket thuc tai i-1 hoac giua a[i] + max ket thuc tai vi tri thu i-1
//Max ket thuc tai 
