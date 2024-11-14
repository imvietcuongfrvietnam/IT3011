#include<stdio.h>
#define first 1

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(int source[], int heap_size, int position){
    if(position > heap_size) return; 
    int left = position << 1;  
    int right = left + 1;     
    int largest = position;   
    
    if(left <= heap_size && source[left] > source[position])
        largest = left;
    
    if(right <= heap_size && source[right] > source[largest])
        largest = right;
    
    if(largest != position){
       	swap(source+position, source+largest);
        heapify(source, heap_size, largest); 
    }
}

int heap_extract_max(int source[], int heap_size){
	if(heap_size<1){
		printf("heap overflow");
		return -1;
	}
	int max = source[first];
	source[first] = source[heap_size];
	heapify(source, heap_size-1, first);
	return max;
}

int main(){
	int A[15] = {0, 27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
	printf("%d", heap_extract_max(A, 14));
	return 0;
}
