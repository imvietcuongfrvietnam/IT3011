#include<stdio.h>
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


void build_heap(int source[], int length){
	int heap_size = length;
	for(int position = heap_size/2;position>0;position--){
		heapify(source, heap_size, position);
	}
}

void heap_sort(int source[], int length){
	while(length>0){
	build_heap(source, length);
	swap(source+1, source+length);
	length -= 1;
	}
}

int main(){
    int A[15] = {0, 27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
    heap_sort(A, 14);
    
    for(int i = 1; i < 15; i++){
        printf("%d ", A[i]);
    }
    return 0;
}

