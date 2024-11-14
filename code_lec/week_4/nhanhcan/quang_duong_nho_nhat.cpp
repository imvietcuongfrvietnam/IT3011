#include <bits/stdc++.h>
#include <limits.h>  // Thu vi?n d? s? d?ng LONG_MAX

#define MAX 100
int c[MAX][MAX];
int visited[MAX];
int x[MAX];
const int cmin = 3;

long fopt = LONG_MAX;  // Kh?i t?o fopt v?i giá tr? r?t l?n
long f = 0;

void travel_min_distance(int k, int n) {
    for(int i = 2; i <= n; i++) {
        if(!visited[i]) {
            visited[i] = 1;
            f = f + c[x[k-1] - 1][i - 1];

            if(k == n) {
                f += c[x[n] - 1][0];
                if(f < fopt) {
                    fopt = f;
                }
                f -= c[x[n] - 1][0];
            } else {
                if(f + (n - k) * cmin >= fopt) {
                    f -= c[x[k-1] - 1][i - 1];
                    visited[i] = 0;
                    continue;
                }
                travel_min_distance(k + 1, n);
            }
            f -= c[x[k-1] - 1][i - 1];
            visited[i] = 0;
        }
    }
}

int main() {
    x[0] = 1;  // Ð?t di?m b?t d?u là 1
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    travel_min_distance(1, n);
    printf("%ld", fopt);
    return 0;
}

