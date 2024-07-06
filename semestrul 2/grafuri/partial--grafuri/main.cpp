#include <iostream>
#include <fstream>
using namespace std;

int adj[100][100];
bool v[100];
int stack[100], top = -1;

void DFS(int node, int n) {
    v[node] = true;
    stack[++top] = node;
    while (top != -1) {
        int current_node = stack[top--];
        for (int i = 1; i <= n; i++) {
            if (adj[current_node][i] && !v[i]) {
                v[i] = true;
                stack[++top] = i;
            }
        }
    }
}

bool isConnected(int n) {
    for (int i = 1; i <= n; i++)
        v[i] = false;
    DFS(1, n);
    for (int i = 1; i <= n; i++)
        if (!v[i])
            return false;
    return true;
}

int main() {
    ifstream fin ("../input.txt");
    int n, m;
    fin >> n >> m;
    int x, y;
    for(int i=1; i<=m; i++)
    {
        fin>>x>>y;
        adj[x][y]= adj[y][x]=1;
    }
    int muchie_a, muchie_b;
    cout<<"Intrduce muchia a: ";
    cin>>muchie_a;
    cout<<"Intrduce muchia b: ";
    cin>>muchie_b;
    adj[muchie_a][muchie_b]=adj[muchie_b][muchie_a]=0;
    if (!isConnected(n)) {
        cout << "NU!";
    } else {
        cout << "DA!";
    }
    return 0;
}
