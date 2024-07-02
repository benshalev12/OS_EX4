#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>

class Graph {
private:
    int V; // Number of vertices
    std::vector<std::list<int>> adj; // Adjacency list

public:
    Graph(int V); // Constructor

    // Function to add an edge to graph
    void addEdge(int v, int w);

    // Function to check if all non-zero degree vertices are connected
    bool isConnected();

    // Function to check if the graph has an Eulerian circuit
    bool hasEulerianCircuit();

    // Function to find and print Eulerian circuit
    void findEulerianCircuit();
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::isConnected() {
    // A function to check if the graph is connected
    // Start DFS from a vertex with a non-zero degree
    std::vector<bool> visited(V, false);
    int i;
    for (i = 0; i < V; i++) {
        if (adj[i].size() != 0)
            break;
    }

    // If there are no edges in the graph, return true
    if (i == V)
        return true;

    // Start DFS from vertex i
    std::list<int> stack;
    stack.push_back(i);
    while (!stack.empty()) {
        int v = stack.back();
        stack.pop_back();
        if (!visited[v]) {
            visited[v] = true;
            for (int adjV : adj[v]) {
                if (!visited[adjV])
                    stack.push_back(adjV);
            }
        }
    }

    // Check if all vertices with non-zero degree are visited
    for (i = 0; i < V; i++) {
        if (!visited[i] && adj[i].size() > 0)
            return false;
    }
    return true;
}

bool Graph::hasEulerianCircuit() {
    // Check if all non-zero degree vertices are connected
    if (!isConnected())
        return false;

    // Check if all vertices have even degree
    for (int i = 0; i < V; i++) {
        if (adj[i].size() & 1)
            return false;
    }
    return true;
}

void Graph::findEulerianCircuit() {
    if (!hasEulerianCircuit()) {
        std::cout << "Eulerian Circuit does not exist." << std::endl;
        return;
    }

    // Create a copy of the adjacency list
    std::vector<std::list<int>> tempAdj = adj;

    // Initialize stack and path
    std::list<int> stack;
    std::list<int> path;

    // Start from vertex 0
    stack.push_back(0);
    int curr;

    while (!stack.empty()) {
        curr = stack.back();

        // If current vertex has no neighbors, add it to path and remove from stack
        if (tempAdj[curr].empty()) {
            path.push_back(curr);
            stack.pop_back();
        } else {
            // Otherwise, find a neighbor and move to it
            int neighbor = tempAdj[curr].front();
            stack.push_back(neighbor);
            tempAdj[curr].remove(neighbor);
            tempAdj[neighbor].remove(curr);
        }
    }

    // Print Eulerian Circuit
    std::cout << "Eulerian Circuit: ";
    for (int vertex : path) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;
}
