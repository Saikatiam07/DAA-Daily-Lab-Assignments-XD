#include<stdio.h>
int min(int a, int b){
    return (a < b) ? a : b;
}
int main() {
    int a1[] = {3, 10, 12, 5, 7, 11, 2};
    int a2[] = {5, 11, 8, 9, 7, 8, 1};
    int t1[] = {2, 3, 1, 3, 4, 2};
    int t2[] = {2, 1, 2, 2, 1, 3};
    int e1 = 2, e2 = 4;
    int x1 = 3, x2 = 2;
    int n = 7;
    int f1[10], f2[10];
    f1[0] = e1 + a1[0];
    f2[0] = e2 + a2[0];
    for (int i = 1; i < n; i++){
        f1[i] = min(f1[i-1] + a1[i], f2[i-1] + t2[i-1] + a1[i]);
        f2[i] = min(f2[i-1] + a2[i], f1[i-1] + t1[i-1] + a2[i]);
    }
    int result = min(f1[n-1] + x1, f2[n-1] + x2);
    printf("Minimum Cost = %d\n", result);
    return 0;
}

/*
Output:
Minimum Cost = 38
*/