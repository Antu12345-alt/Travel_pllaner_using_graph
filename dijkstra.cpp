#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

int distArr[100];
int parent[100];

void dijkstra(int src, int n, int choice, int traffic) {

    for(int i = 0; i < n; i++) {
        distArr[i] = INT_MAX;
        parent[i] = -1;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    distArr[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for(auto edge : graph[u]) {

            int v = edge.node;
            int wt;

            if(choice == 1) wt = edge.distance;
            else if(choice == 2) wt = edge.time;
            else wt = edge.cost;

            if(traffic == 1) wt += 5;

            if(distArr[v] > distArr[u] + wt) {
                distArr[v] = distArr[u] + wt;
                parent[v] = u;
                pq.push({distArr[v], v});
            }
        }
    }
}

void printPath(int v) {
    if(v == -1) return;
    printPath(parent[v]);
    cout << v << " ";
}