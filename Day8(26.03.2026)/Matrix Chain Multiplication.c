#include<stdio.h>
int main() {
    int p[] = {5, 7, 9, 12, 15};
    int n = 4;
    int m[5][5];
    int i, j, k, L, q;
    for(i = 1; i<= n; i++) {
        m[i][i] = 0;
    }
    for(L = 2; L <= n; L++) {
        for(i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = m[i][i] + m[i+1][j] + p[i-1]*p[i]*p[j];
            for(k = i + 1; k < j; k++) {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }
    printf("DP Table:\n");
    printf("i\\j\t1\t2\t3\t4\n");
    for(i = 1; i <= n; i++) {
        printf("%d\t", i);
        for(j = 1; j <= n; j++) {
            if(j < i)
                printf("X\t");
            else
                printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\nMinimum Multiplications = %d\n", m[1][n]);
    return 0;
}

/*
Output:

DP Table:
i\j	1	2	3	4
1	0	315	855	1755	
2	X	0	756	2016	
3	X	X	0	1620	
4	X	X	X	0

Minimum Multiplications = 1755
*/