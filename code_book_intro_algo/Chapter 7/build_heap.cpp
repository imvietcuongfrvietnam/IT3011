#include<stdio.h>

void build_heap(int source[], int length){
	int heap_size = length;
	for(int i = heap_size/2;i>0;i--){
		heapify(source, heap_size, i);
	}
}

