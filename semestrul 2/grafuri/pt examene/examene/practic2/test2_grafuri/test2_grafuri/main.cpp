#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structura pentru a reprezenta o muchie în graf
struct Edge {
    int source, destination;
    int capacity, flow;

    Edge(int source, int destination, int capacity)
        : source(source), destination(destination), capacity(capacity), flow(0) {}
};

// Funcția pentru adăugarea unei muchii în rețea
void addEdge(vector<vector<int>>& adjacencyList, vector<Edge>& edges, int source, int destination, int capacity) {
    Edge forwardEdge(source, destination, capacity);
    Edge backwardEdge(destination, source, 0);

    // Muchia înainte și muchia înapoi formează un flux nesaturat
    adjacencyList[source].push_back(edges.size());
    edges.push_back(forwardEdge);

    adjacencyList[destination].push_back(edges.size());
    edges.push_back(backwardEdge);
}

// Algoritmul Ford-Fulkerson pentru găsirea fluxului maxim
int fordFulkerson(vector<vector<int>>& adjacencyList, vector<Edge>& edges, int numNodes, int source, int destination) {
    vector<int> parent(numNodes, -1);    // Vector pentru păstrarea drumului de creștere

    int maxFlow = 0;    // Fluxul maxim inițializat cu 0

    // Cat timp exista un drum de crestere de la sursa la destinatie
    while (bfs(adjacencyList, edges, numNodes, source, destination, parent)) {
        int pathFlow = numeric_limits<int>::max();

        // Găsim fluxul minim pe drumul de creștere găsit
        for (int node = destination; node != source; node = edges[parent[node]].source) {
            int edgeIdx = parent[node];
            pathFlow = min(pathFlow, edges[edgeIdx].capacity - edges[edgeIdx].flow);
        }

        // Actualizăm capacitățile muchiilor și fluxurile corespunzătoare
        for (int node = destination; node != source; node = edges[parent[node]].source) {
            int edgeIdx = parent[node];
            edges[edgeIdx].flow += pathFlow;
            edges[edgeIdx ^ 1].flow -= pathFlow;
        }

        // Adăugăm fluxul minim găsit la fluxul maxim total
        maxFlow += pathFlow;
    }

    return maxFlow;
}

// Funcția pentru a verifica dacă există un drum de creștere folosind BFS
bool bfs(vector<vector<int>>& adjacencyList, vector<Edge>& edges, int numNodes, int source, int destination, vector<int>& parent) {
    vector<bool> visited(numNodes, false);    // Vector pentru a marca nodurile vizitate
    queue<int> q;

    // Adăugăm sursa în coadă și o marcam ca vizitată
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    // BFS pentru găsirea unui drum de creștere
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Parcurgem vecinii nodului curent
        for (int edgeIdx : adjacencyList[current]) {
            Edge& edge = edges[edgeIdx];
            int next = edge.destination;

            // Verificam daca nu am vizitat vecinul și dacă mai există capacităte neutilizată pe muchie
            if (!visited[next] && edge.capacity > edge.flow) {
                q.push(next);
                parent[next] = edgeIdx;
                visited[next] = true;
            }
        }
    }

    // Returnam daca am gasit sau nu un drum de crestere
    return visited[destination];
}

int main() {
    ifstream inputFile("input.in");
    ofstream outputFile("output.out");

    int numNodes, numEdges;
    inputFile >> numNodes >> numEdges;

    vector<vector<int>> adjacencyList(numNodes);
    vector<Edge> edges;

    // Citim muchiile și capacitatea lor din intrare
    for (int i = 0; i < numEdges; i++) {
        int source, destination, capacity;
        inputFile >> source >> destination >> capacity;
        addEdge(adjacencyList, edges, source, destination, capacity); // Se utilizeaza indexare de la 0
    }

    int source = 0;              // Nodul sursă (S)
    int destination = numNodes-1;    // Nodul destinație (D)

    // Calculam fluxul maxim utilizand algoritmul Ford-Fulkerson
    int maxFlow = fordFulkerson(adjacencyList, edges, numNodes, source, destination);

    // Scriem rezultatul în fișierul de ieșire
    outputFile << maxFlow << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
