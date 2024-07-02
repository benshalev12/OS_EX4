#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>

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

#endif // GRAPH_H
