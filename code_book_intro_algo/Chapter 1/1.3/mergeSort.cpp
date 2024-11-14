#include<stdio.h>

void merge(int a[], int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	
	// Create temporary arrays
	int left[n1], right[n2];
	
	// Copy data to temporary arrays
	for(int i = 0; i < n1; i++)
		left[i] = a[p + i];
	for(int j = 0; j < n2; j++)
		right[j] = a[q + 1 + j];

	// Merge the temporary arrays back into a[p..r]
	int i = 0, j = 0, k = p;
	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			a[k] = left[i];
			i++;
		} else {
			a[k] = right[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of left[], if any
	while (i < n1) {
		a[k] = left[i];
		i++;
		k++;
	}

	// Copy the remaining elements of right[], if any
	while (j < n2) {
		a[k] = right[j];
		j++;
		k++;
	}
}

void mergeSort(int a[], int start, int finish){
	if(start < finish)
	{
		int mid = start + (finish - start) / 2;
		mergeSort(a, start, mid);      // Sort first half
		mergeSort(a, mid + 1, finish); // Sort second half
		merge(a, start, mid, finish);  // Merge the two halves
	}
}

int main(){
	int a[4] = {4, 2, 5, 1};
	mergeSort(a, 0, 3);
	for(int i = 0; i < 4; i++)
		printf("%d ", a[i]);
	return 0;
}

