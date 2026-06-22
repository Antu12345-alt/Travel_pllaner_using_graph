#include <iostream>
#include <climits>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "graph.h"
#include "dijkstra.h"
#include "bfs.h"
using namespace std;


unordered_map<string, int> cityToId;
unordered_map<int, string> idToCity;
int idCounter = 0;

// GET OR CREATE CITY ID 
int getCityId(string city) {
    if(cityToId.find(city) == cityToId.end()) {
        cityToId[city] = idCounter;
        idToCity[idCounter] = city;
        idCounter++;
    }
    return cityToId[city];
}

//  LOAD CSV FUNCTION 
void loadFromCSV(string filename) {
    ifstream file(filename);
    string line;

    if(!file.is_open()) {
        cout << "Error: Cannot open CSV file\n";
        return;
    }

    getline(file, line); // skip header

    while(getline(file, line)) {
        stringstream ss(line);
        string temp;

        string city1, city2;
        int d, t, c;

        getline(ss, city1, ',');
        getline(ss, city2, ',');
        getline(ss, temp, ','); d = stoi(temp);
        getline(ss, temp, ','); t = stoi(temp);
        getline(ss, temp, ','); c = stoi(temp);

        int u = getCityId(city1);
        int v = getCityId(city2);

        addEdge(u, v, d, t, c);
    }

    file.close();
}

//  PRINT PATH WITH CITY NAMES 
void printCityPath(int node) {
    if(parent[node] == -1) {
        cout << idToCity[node] << " ";
        return;
    }
    printCityPath(parent[node]);
    cout << idToCity[node] << " ";
}

//MAIN 
int main() {

    
    // int n;
    // cout << "Enter number of nodes: ";
    // cin >> n;

    loadFromCSV("data.csv");

    int n = idCounter; 

    int ch = 0;

    while(true) {

        cout << "\n----- MENU -----\n";
        cout << "1. Find Route (Dijkstra)\n";
        cout << "2. BFS Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        if(!(cin >> ch)) {
            cout << "Invalid input. Exiting...\n";
            break;
        }

        if(ch == 3) break;

        if(ch == 1) {
            string srcCity, destCity;
            int choice, traffic;

            cout << "Enter source city: ";
            cin >> srcCity;

            cout << "Enter destination city: ";
            cin >> destCity;

            if(cityToId.find(srcCity) == cityToId.end() ||
               cityToId.find(destCity) == cityToId.end()) {
                cout << "Invalid city name!\n";
                continue;
            }

            int src = cityToId[srcCity];
            int dest = cityToId[destCity];

            cout << "1. Distance  2. Time  3. Cost: ";
            cin >> choice;

            cout << "Traffic (0 = No, 1 = Yes): ";
            cin >> traffic;

            dijkstra(src, n, choice, traffic);

            if(distArr[dest] == INT_MAX) {
                cout << "No path exists\n";
            } else {
                cout << "Optimal Value: " << distArr[dest] << endl;
                cout << "Path: ";
                printCityPath(dest);
                cout << endl;
            }
        }

        else if(ch == 2) {
            string srcCity;

            cout << "Enter starting city: ";
            cin >> srcCity;

            if(cityToId.find(srcCity) == cityToId.end()) {
                cout << "Invalid city name!\n";
                continue;
            }

            int src = cityToId[srcCity];
            bfs(src, n);
        }

        else {
            cout << "Invalid choice\n";
        }
    }

    cout << "Program Ended.\n";
    return 0;
}
