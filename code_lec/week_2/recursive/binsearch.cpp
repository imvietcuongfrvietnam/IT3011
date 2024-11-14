#include<stdio.h>
// Xep theo thu tu tang dan
// Giam dan thi dao 2 dong 9, 10
int binsearch(int low, int high, int S[], int key){
	printf("%d %d\n", low, high);
	if(low>high) return -1;
	int mid = (low + high) / 2;
	if(S[mid] == key) return mid;
	else if (S[mid] < key) return binsearch(mid + 1, high, S, key);
	else return binsearch(low, mid-1, S, key);
}
int main(){
	int key;
	scanf("%d", &key);
	int a[] = {3, 5 ,6 ,7 ,8 ,10, 15, 18, 25, 51};
	printf("%d ", binsearch(0, 9, a, key));
}
