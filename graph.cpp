#include "graph.h"

vector<Edge> graph[100];

void addEdge(int u, int v, int d, int t, int c) {
    graph[u].push_back({v, d, t, c});
    graph[v].push_back({u, d, t, c});
}