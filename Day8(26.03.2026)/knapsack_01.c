#include<stdio.h>
int main() {
    int profit[] = {2, 4, 7, 10};
    int weight[] = {1, 3, 5, 7};
    int n = 4;
    int W = 10;
    int dp[5][11];
    for (int i = 0; i <= n; i++){
        for (int w = 0; w <= W; w++){
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i-1] <= w) {
                int include = profit[i-1] + dp[i-1][w - weight[i-1]];
                int exclude = dp[i-1][w];
                dp[i][w] = (include > exclude) ? include : exclude;
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    printf("Maximum Profit = %d\n", dp[n][W]);
    return 0;
}

/*
Output:
Maximum Profit = 14
*/