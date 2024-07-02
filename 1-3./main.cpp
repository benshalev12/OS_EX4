#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "Graph.h"

void generateRandomGraph(Graph &g, int V, int E) {
    std::srand(std::time(0));
    for (int i = 0; i < E; i++) {
        int v = std::rand() % V;
        int w = std::rand() % V;
        g.addEdge(v, w);
    }
}

int main(int argc, char *argv[]) {
    int V = 0;
    int E = 0;
    int seed = 0;

    int opt;
    while ((opt = getopt(argc, argv, "v:e:s:")) != -1) {
        switch (opt) {
        case 'v':
            V = std::atoi(optarg);
            break;
        case 'e':
            E = std::atoi(optarg);
            break;
        case 's':
            seed = std::atoi(optarg);
            std::srand(seed);
            break;
        default:
            std::cerr << "Usage: " << argv[0] << " -v vertices -e edges -s seed" << std::endl;
            return 1;
        }
    }

    if (V == 0 || E == 0) {
        std::cerr << "Vertices and edges must be greater than 0" << std::endl;
        return 1;
    }

    Graph g(V);
    generateRandomGraph(g, V, E);

    g.findEulerianCircuit();

    return 0;
}
//for running this code you can use the following command
//make
//./eulerian -v 5 -e 20 -s 42