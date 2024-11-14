#include <stdio.h>
#include <math.h>

#define MAX 100

int a[MAX];
int check[MAX];
int cnt = 0;

void ghinhan(int n) {
    cnt++;
}

void Try(int k, int n) {
    if (k == n + 1) {
        ghinhan(n);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            int ok = 1;
            for (int j = 1; j < k; j++) {
                if (abs(k - j) == abs(i - a[j])) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                a[k] = i;
                check[i] = 1;
                Try(k + 1, n);
                check[i] = 0;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Try(1, n);
    printf("%d\n", cnt);
    return 0;
}

