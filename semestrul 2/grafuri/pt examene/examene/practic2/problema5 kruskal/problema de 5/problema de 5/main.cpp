#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, cost;
};

struct UnionFind {
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false;
        }

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        }
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }
};

bool sortByCost(const Edge& e1, const Edge& e2) {
    return e1.cost < e2.cost;
}

vector<Edge> findMinimumSpanningTree(vector<Edge>& edges, int numNodes) {
    sort(edges.begin(), edges.end(), sortByCost);

    UnionFind uf(numNodes);
    vector<Edge> minSpanningTree;
    for (const auto& edge : edges) {
        if (uf.unite(edge.u, edge.v)) {
            minSpanningTree.push_back(edge);
            if (minSpanningTree.size() == numNodes - 1) {
                break;
            }
        }
    }

    return minSpanningTree;
}

int main() {
    ifstream inputFile("apm.in"); // Deschide fisierul de intrare
    ofstream outputFile("apm.out"); // Deschide fisierul de iesire

    int numNodes, numEdges;
    inputFile >> numNodes >> numEdges; // Citeste numarul de noduri si muchii

    vector<Edge> edges(numEdges);
    for (int i = 0; i < numEdges; ++i) {
        inputFile >> edges[i].u >> edges[i].v >> edges[i].cost; // Citeste fiecare muchie
    }

    vector<Edge> minSpanningTree = findMinimumSpanningTree(edges, numNodes); // Gaseste arborele partial de cost minim

    int minCost = 0;
    for (const auto& edge : minSpanningTree) {
        minCost += edge.cost; // Calculeaza costul total al arborelui partial
    }

    outputFile << minCost << endl; // Scrie costul in fisierul de iesire
    outputFile << minSpanningTree.size() << endl; // Scrie numarul de muchii din arbore in fisierul de iesire
    for (const auto& edge : minSpanningTree) {
        outputFile << edge.u << " " << edge.v << endl; // Scrie capetele muchiilor din arbore in fisierul de iesire
    }

    inputFile.close(); // inchide fisierul de intrare
    outputFile.close(); // inchide fisierul de iesire

    return 0;
}
