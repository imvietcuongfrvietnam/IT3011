#include<stdio.h>
#define num 6
int check[num] = {0};  // Initialize check array to track visited numbers
int source[num];       // To store the permutation

void print_sol() {
    for (int i = 1; i <= num-1; i++) {
        printf("%d", source[i]);
    }
    printf("\n");
}

void Try(int k) {76
    if (k == num) {  // Base case: when k is 10, we've filled all 9 positions
        print_sol();
        return;
    }
    for (int i = 1; i <= num-1; i++) {
        if (!check[i]) {         // If number i has not been used yet
            check[i] = 1;        // Mark it as used
            source[k] = i;       // Assign the number to the current position
            Try(k + 1);          // Recurse to fill the next position
            check[i] = 0;        // Backtrack: unmark the number
        }
    }
}

int main() {
    Try(1);  // Start filling the permutation from position 1
    return 0;
}

