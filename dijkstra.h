#ifndef DIJKSTRA_H
#define DIJKSTRA_H

void dijkstra(int src, int n, int choice, int traffic);
void printPath(int v);

extern int distArr[100];
extern int parent[100];

#endif