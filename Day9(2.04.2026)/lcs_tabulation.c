#include<stdio.h>
int max(int a, int b){
    return (a > b) ? a : b;
}
int main() {
    char s1[] = {'B','C','D','A','A','C','D'};
    char s2[] = {'A','C','D','B','A','C'};
    int m = 7;
    int n = 6;
    int dp[20][20];
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    printf("DP Table:\n");
    for (int j = 0; j < n; j++)
        printf(" %c ", s2[j]);
    printf("\n");
    for (int i = 0; i <= m; i++){
        if (i == 0)
            printf("  ");
        else
            printf("%c ", s1[i-1]);
        for (int j = 0; j <= n; j++){
            printf("%2d ", dp[i][j]);
        }
        printf("\n");
    }
    printf("\nLength of LCS = %d\n", dp[m][n]);
    return 0;
}

/*
Output: 

      A  C  D  B  A  C
   --------------------
0 |  0  0  0  0  0  0  0
B |  0  0  0  0  1  1  1
C |  0  0  1  1  1  1  2
D |  0  0  1  2  2  2  2
A |  0  1  1  2  2  3  3
A |  0  1  1  2  2  3  3
C |  0  1  2  2  2  3  4
D |  0  1  2  3  3  3  4

Length of LCS = 4
*/



