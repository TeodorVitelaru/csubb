#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>

using namespace std;

const int NMAX = 1005;
vector<vector<pair<int, int>>> G(NMAX), newG(NMAX);


vector<int> bellmanFord(int v, int source, int inf, int a[][10])
{
    vector<int> d(v+1);
    int p[v];

    for(int i = 0; i < v; ++i) {
        d[i] = inf;
        p[i] = -1;
    }
    d[source] = 0;
    for(int k=0; k<v-1; k++)
        for(int i=0; i<v; i++)
            for(int j=0; j<v; j++)
                if(a[i][j] && d[i]<inf)
                    if(d[j]>d[i]+a[i][j])
                        d[j]=d[i]+a[i][j], p[j]=i;
    return d;
}

vector<int> dijkstra(int source, int v, int inf, int a[][10]) {
    vector<bool> visited(v, false);
    vector<int> d(v+1);
    int p[v];

    for(int i = 0; i <= v; ++i) {
        d[i] = inf;
        p[i]=-1;
    }
    d[source] = 0;

    for (int count = 0; count < v - 1; count++) {
        int min = inf, min_index;

        for (int i = 0; i < v; i++)
            if (!visited[i] && d[i] <= min)
                min = d[i], min_index = i;

        int u = min_index;

        visited[u] = true;

        for (int i = 0; i < v; i++)
            if (!visited[i] && a[u][i] && d[u] != inf && d[u] + a[u][i] < d[i])
                d[i] = d[u] + a[u][i], p[i] = u;
    }
    return d;
}

void Johnson(int v, int inf, int a[][10]) {
    int aj[10][10];
    // Initialize aj with the weights from a
    for(int i = 0; i <= v; ++i) {
        for(int j = 0; j <= v; ++j) {
            if(i == v || j == v)
                aj[i][j] = 0;
            else
                aj[i][j] = a[i][j];
        }
    }

    // Run Bellman-Ford from the new vertex
    vector<int> h = bellmanFord(v, 0, inf, a);
    if(h.empty()) {
        cout << -1;
        return;
    }
    // Reweight the edges
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
            if(a[i][j] != inf)
                a[i][j] = a[i][j] + h[i] - h[j];

    // Print the reweighted graph only for the edges that existed in the original graph
    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++) {
            if(a[i][j] != 0)
                cout << i << " " << j << " " << aj[i][j] << '\n';
        }
    }

    // Run Dijkstra for all vertices
    for (int i = 0; i < v; i++) {
        vector<int> dist = dijkstra(i, v, inf, aj);
        for (int j = 0; j < v; ++j) {
            if (dist[j] == inf) {
                cout << "INF";
            } else {
                cout << dist[j];
            }
            cout << " ";
        }
        cout << '\n';
    }
}


//vector<int> d;
int a[10][10];
int main(int argc, char* argv[]) {
    int v, e, s;
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    fin>>v>>e;
    int x, y, w;
    vector<int> d(v);
    for(int i = 1;i <=e;i++)
    {
        fin>>x>>y>>w;
        a[x][y] = w;
    }
    int inf = 1000;
    /*
    // se face de la nodul sursa s, citit de la tastatura
    vector<int> new_bel = bellmanFord(v, s, inf, a);

    for(int i=0; i<v; i++)
        if(new_bel[i] != inf)
            fout<<"Drumul de la "<<s<<" la "<<i<<" este de cost "<<new_bel[i]<<'\n';
        else
            fout<<"Drumul de la "<<s<<" la "<<i<<" este de cost infinit"<<'\n';
    fout<<endl;

    vector<int> new_vec = dijkstra(s, v, inf, a);

    for(int i=0; i<v; i++)
        if(new_vec[i] != inf)
            fout<<"Drumul de la "<<s<<" la "<<i<<" este de cost "<<new_vec[i]<<'\n';
        else
            fout<<"Drumul de la "<<s<<" la "<<i<<" este de cost infinit"<<'\n';
    fout<<endl;
    */

    Johnson(v, inf, a);

    fin.close();
    fout.close();
    return 0;
}