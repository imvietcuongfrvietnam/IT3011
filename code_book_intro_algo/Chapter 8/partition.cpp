#include<stdio.h>

int partition(int source[], int start, int finish){
    int x = source[start];  // Use the first element as the pivot
    int i = start - 1;
    int j = finish + 1;

    while(1) {
        // Move j to the left, looking for a value smaller than the pivot
        do {
            j = j - 1;
        } while(source[j] > x);

        // Move i to the right, looking for a value larger than the pivot
        do {
            i = i + 1;
        } while(source[i] < x);

        // If i and j cross, the partition is complete
        if(i < j) {
            // Swap source[i] and source[j]
            int tmp = source[i];
            source[i] = source[j];
            source[j] = tmp;
        }
        else {
            return j;  // Return the partition index
        }
    }
}

int main() {
    int A[20] = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};  // Array of 12 elements
    int parti = partition(A, 0, 11);  // Partition the array

    // Print the array after partitioning
    for(int i = 0; i < 12; i++) {
        printf("%d ", A[i]);
    }
    printf("\nPartition index: %d\n", parti);

    return 0;
}

