#include<stdio.h>

int partition(int source[], int start, int finish){
    int x = source[start]; 
    int i = start - 1;
    int j = finish + 1;

    while(1) {
        do {
            j = j - 1;
        } while(source[j] > x);

        do {
            i = i + 1;
        } while(source[i] < x);


        if(i < j) {
            int tmp = source[i];
            source[i] = source[j];
            source[j] = tmp;
        }
        else {
            return j;  // Return the partition index
        }
    }
}

void quick_sort(int A[], int start, int finish){
	if(start>=finish) return;
	int q = partition(A, start, finish);
	quick_sort(A, start, q);
	quick_sort(A, q+1, finish);
}
int main(){
	int A[12] = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
	quick_sort(A, 0 , 11);
	for(int i = 0;i < 12; i++){
		printf("%d ", A[i]);
	}
}
