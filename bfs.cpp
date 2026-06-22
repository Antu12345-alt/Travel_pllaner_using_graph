#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

void bfs(int src, int n) {

    vector<bool> visited(n, false);
    queue<int> q;

    q.push(src);
    visited[src] = true;

    cout << "BFS Traversal: ";

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for(auto edge : graph[u]) {
            if(!visited[edge.node]) {
                visited[edge.node] = true;
                q.push(edge.node);
            }
        }
    }
    cout << endl;
}