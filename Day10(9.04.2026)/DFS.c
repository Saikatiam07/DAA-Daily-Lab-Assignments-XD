#include<stdio.h>
int visited[10];
void dfs(int graph[10][10], int n, int v){
    printf("%d", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0){
            dfs(graph, n, i);
        }
    }
}
int main(){
    int n = 5;
    int graph[10][10]={
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    printf("DFS Traversal:");
    dfs(graph, n, 0);
    return 0;
}

/*
Output: 
DFS Traversal: 0 1 2 4 3
*/