#include<stdio.h>
#include<string.h>
void swap(int first, int second){
	int tmp = first;
	first = second;
	second = tmp;
}

void insertionSort(int *a, int n){
	int key;
	for(int i = n-1;i>=1;i--){
		key = i;
		int j = i-1;
		while(j>=0){
		if(a[j]>a[key]) key = j;
		j--;
		}
	int tmp = a[i];
	a[i] = a[key];
	a[key] = tmp;
		
	}	
}
int main(){
	int a[] = {31,41,59,26,41,58};
	insertionSort(a, 6);
	for(int i = 0;i<6;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
