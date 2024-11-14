#include<stdio.h>

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
        int tmp = source[position];
        source[position] = source[largest];
        source[largest] = tmp;
        heapify(source, heap_size, largest); 
    }
}

int main(){
    int A[15] = {0, 27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
    heapify(A, 14, 3); 
    
    for(int i = 1; i < 15; i++){
        printf("%d ", A[i]);
    }
    return 0;
}

