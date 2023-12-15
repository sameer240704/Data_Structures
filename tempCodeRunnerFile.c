#include<conio.h>
#include<stdio.h>
#define MAX 2

int bfs(int adj[][MAX], int visited[], int start) {
	int queue[MAX], front = -1, rear = -1, i;
	queue[++rear] = start;
	visited[start] = 1;
	while(rear != front) {
		start = queue[++front];
		if(start == 4)
			printf("5\t");
		else 
			printf("%c", start+65);
		for(i=0 ; i<MAX ; i++) {
			if(adj[start][i] == 1 && visited[i] == 0) {
				queue[++rear] = i;
				visited[i] = 1;
			}
		}
	}
}

int main() {
	int adj[MAX][MAX], i, j;
	int visited[MAX] = {0};
	printf("\nEnter the adjacency matrix : ");
	for(i=0 ; i<MAX ; i++) {
		for(j=0 ; j<MAX ; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
	bfs(adj, visited, 0);
	return 0;
}