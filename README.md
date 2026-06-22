# Travel_pllaner_using_graph
DSA based travel planner project using graph algorithems for shortest path in c++
1. Introduction

This Travel Planner project implements a city‑to‑city route‑planning system using graph data structures and Dijkstra’s shortest‑path algorithm. The program reads a CSV file containing city‑pair routes with distance, time, and cost, and constructs an undirected weighted graph. Then, it answers user queries to find the shortest, fastest, or cheapest route between two cities.

The project demonstrates core DSA concepts such as graph representation, shortest‑path algorithms, and priority‑queue‑based optimization.

2. Problem Statement

Design and implement a console‑based Travel Planner that:

- Loads a road‑network dataset (cities and routes) from a CSV file.
- Stores the data as a weighted graph where each edge has:
  - Distance
  - Time
  - Cost
- Finds the optimal route between two cities based on user‑selected criteria:
  - Shortest distance
  - Fastest time
  - Cheapest cost
- Supports traffic simulation (adds a penalty to edge weights).
- Displays the path and optimal value (min distance/time/cost) to the user.

3. Data Structures Used

3.1 Graph Representation
- Each node represents a city (assigned a unique integer ID).
- City names are mapped to IDs using:
  unordered_map<string, int> cityToId;
  unordered_map<int, string> idToCity;
- The graph is stored as an adjacency list:
  vector<Edge> graph[100];
  where Edge is:
  struct Edge {
      int node;
      int distance;
      int time;
      int cost;
  };

3.2 Dijkstra’s Support Arrays
- distArr[100] – stores the shortest distance from source to each node.
- parent[100] – stores the parent node for path reconstruction.
- priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq – min‑heap used to efficiently select the next node.

3.3 BFS Support
- vector<bool> visited – tracks visited nodes.
- queue<int> q – standard BFS queue for level‑by‑level traversal.

4. Algorithms Implemented

4.1 Dijkstra’s Shortest‑Path Algorithm

The dijkstra(src, n, choice, traffic) function:

- Initializes distArr[i] = INT_MAX and parent[i] = -1 for all nodes.
- Uses a min‑heap (priority_queue) to always pick the node with the smallest current distance.
- For each edge, it selects the weight:
  - choice == 1 → distance
  - choice == 2 → time
  - otherwise → cost
- If traffic == 1, it adds +5 to the edge weight (simulating congestion).
- If distArr[v] > distArr[u] + wt, it updates:
  distArr[v] = distArr[u] + wt;
  parent[v] = u;
  pq.push({distArr[v], v});
This is the standard Dijkstra’s algorithm for single‑source shortest path in a non‑negative weighted graph.

4.2 Path Reconstruction

The printCityPath and printPath functions:

- Use the parent array to recursively print the path from source to destination.
- printCityPath converts node IDs back to city names using idToCity, so the user sees:
  Path: Delhi Jaipur Mumbai Bangalore

4.3 BFS Traversal

The bfs(src, n) function:

- Uses a queue and visited array to traverse all reachable nodes level‑by‑level.
- Useful for:
  - Graph connectivity checking
  - Exploring which cities are reachable from a given city (e.g., “Which cities are reachable from Delhi?”).

5. Time and Space Complexity

Operation                     Time Complexity (approx.)        Space Complexity (approx.)
----------------------------------------------------------------------------------------
Graph build (CSV loading)    O(E)                             O(V + E)
Dijkstra’s algorithm         O((V + E) log V)                 O(V)
BFS traversal                O(V + E)                         O(V)
City‑ID mapping              O(C) per insertion               O(C)

Here:
- V = number of nodes (cities)
- E = number of edges (routes)
- C = number of distinct cities

These complexities are standard for such routing systems and are efficient for small to medium‑scale city networks.

6. Key Features

- Multi‑objective routing:
  - Choose shortest distance, fastest time, or cheapest cost.
- Traffic simulation:
  - optional traffic = 1 adds +5 penalty to edge weights.
- CSV‑based data input:
  - Routes stored in data.csv; easy to edit and extend.
- User‑friendly console menu:
  - 1. Find Route (Dijkstra)
  - 2. BFS Traversal
  - 3. Exit
- City‑name mapping:
  - Users type city names; the program auto‑maps them to IDs.

7. Sample Run (Example I/O)

----- MENU -----
1. Find Route (Dijkstra)
2. BFS Traversal
3. Exit
Enter choice: 1

Enter source city: Delhi
Enter destination city: Bangalore
1. Distance  2. Time  3. Cost: 1
Traffic (0 = No, 1 = Yes): 0

Optimal Value: 10
Path: Delhi Jaipur Mumbai Bangalore

(You can paste actual runs from your program here.)

8. Applications

- Mini‑navigation system for small road networks (college‑level projects).
- Teaching tool for DSA concepts:
  - Graph modeling
  - Shortest‑path algorithms
  - Multi‑criterion optimization (distance vs time vs cost).
- Foundation for:
  - Public‑transport route planning
  - Logistics and delivery‑route optimization

9. Future Scope

- GUI‑based planner (Tkinter, Qt, or web‑based map) to show routes on an actual map.
- Real‑time traffic integration (dynamic weights based on live traffic data).
- Multi‑criteria shortest path:
  - Balance between time and cost (Pareto‑optimal paths).
- Support for directed graphs:
  - Model one‑way roads and highways.

10. Conclusion

This Travel Planner project successfully integrates graph data structures, Dijkstra’s shortest‑path algorithm, and BFS traversal into a single, practical application. It shows how classic DSA algorithms can solve real‑world routing problems and provides a strong foundation for building larger navigation and logistics systems.

