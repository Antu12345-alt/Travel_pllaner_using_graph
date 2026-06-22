#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

struct Edge {
    int node;
    int distance;
    int time;
    int cost;
};

extern vector<Edge> graph[100];

void addEdge(int u, int v, int d, int t, int c);

#endif