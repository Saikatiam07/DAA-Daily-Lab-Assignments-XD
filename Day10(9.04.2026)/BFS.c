#include<stdio.h>
int queue[10], front = -1, rear = -1;
int visited[10];
void enqueue(int v){
    if (rear == 9)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}
int dequeue(){
    if (front == -1)
        return -1;
    int item = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return item;
}
void bfs(int graph[10][10], int n, int start){
    enqueue(start);
    visited[start] = 1;
    while (front != -1){
        int v = dequeue();
        printf("%d ", v);
        for (int i = 0; i < n; i++){
            if (graph[v][i] == 1 && visited[i] == 0){
                enqueue(i);
                visited[i] = 1;
            }
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
    printf("BFS Traversal: ");
    bfs(graph, n, 0);
    return 0;
}

/*
Output:
BFS Traversal: 0 1 2 3 4 
*/  