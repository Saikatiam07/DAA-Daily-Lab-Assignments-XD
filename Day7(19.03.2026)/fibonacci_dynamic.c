#include<stdio.h>
int main() {
    int n = 6;
    int dp[100];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    printf("Fibonacci series up to %d:\n", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", dp[i]);
    }
    return 0;
}

/*
Output:
Fibonacci series up to 6:
0 1 1 2 3 5 8 
*/  