#include<stdio.h>
#define parent(i) i>>1
#define right(i) i>>1
#define left (i) i<<1

void heap_insert(int key, int source[], int heap_size){
	heap_size = heap_size + 1;
	int n = heap_size;
	while(n>1 && source[parent(n)]key)
		n = parent(n);
	A[n] = key;
	
}
int main(){
	
}
