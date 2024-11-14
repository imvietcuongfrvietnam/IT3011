#include<stdio.h>

int binarySearch(int a[], int start, int end, int key){
	if(start >= end) return -1;
	int mid = (start+end)/2;
	if(a[mid]<key) 
	return binarySearch(a, mid, end, key);
	else if(a[mid] == key) return mid;
	else return binarySearch(a, start,mid, key);
}
int main(){
	int a[5] = {1,4,6,7,9};
	printf("%d", binarySearch(a,0,4,7));
	return 0;
}
