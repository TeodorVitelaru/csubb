#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Edge {
    int city1, city2;
    double distance;

    bool operator<(const Edge& other) const {
        return distance < other.distance;
    }
};

struct City {
    int x, y;
};

double calculateDistance(const City& a, const City& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

std::vector<int> parent;

int find(int city) {
    if (city == parent[city]) {
        return city;
    }
    return parent[city] = find(parent[city]);
}

void unionCities(int city1, int city2) {
    city1 = find(city1);
    city2 = find(city2);
    if (city1 != city2) {
        parent[city2] = city1;
    }
}

double minimumSpanningTree(const std::vector<City>& cities) {
    int n = cities.size();
    std::vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges.push_back({i, j, calculateDistance(cities[i], cities[j])});
        }
    }
    std::sort(edges.begin(), edges.end());
    parent.resize(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    double totalDistance = 0;
    for (const Edge& edge : edges) {
        if (find(edge.city1) != find(edge.city2)) {
            unionCities(edge.city1, edge.city2);
            totalDistance += edge.distance;
        }
    }
    return totalDistance;
}

int main() {
    ifstream in("../input.txt");
    int n;
    in >> n;
    vector<City> cities(n);
    for (int i = 0; i < n; ++i) {
        in >> cities[i].x >> cities[i].y;
    }
    in.close();

    double totalDistance = minimumSpanningTree(cities);

    ofstream outputFile("../output.txt");
    outputFile << fixed << setprecision(3) << totalDistance;
    outputFile.close();

    return 0;
}