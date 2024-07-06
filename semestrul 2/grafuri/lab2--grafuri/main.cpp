#include <iostream>
#include <fstream>
#include <queue>

using namespace std;


void citire_graf(int &n, int &m, int m_adiacenta[100][100]) {
    ifstream fin("../in.txt");
    fin >> n;
    int x, y;
    while ( fin >> x >> y ) {
        m_adiacenta[x][y] = 1;
        //m_adiacenta[y][x] = 1;
        m ++;
    }
}

void moore_alg(int nod_sursa, int n, int m_adiacenta[100][100], int lungimi[100], int parinti[100]) {
    lungimi[nod_sursa] = 0;
    queue<int> q;
    q.push(nod_sursa);
    while ( q.empty() == 0 ) {
        int nod_curent = q.front(); q.pop();
        for ( int i = 1 ; i <= n ; i ++ )
            if (lungimi[i] == -1 && m_adiacenta[nod_curent][i] == 1) {
                parinti[i] = nod_curent;
                lungimi[i] = lungimi[nod_curent] + 1;
                q.push(i);
            }
    }
    for ( int i = 1 ; i <= n ; i ++ )
        cout << lungimi[i] << ' ';
    cout << endl;
    for ( int i = 1 ; i <= n ; i ++ )
        cout << parinti[i] << ' ';
}

void inchidere_tranzitiva(int a[][100],int n){
    for(int i=1;i<=n;i++)
        a[i][i]=1;
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (a[i][j] == 0 && a[k][j] == 1 && a[i][k] == 1)
                    a[i][j] = 1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
}

void reset_vector(int v[],int n){
    for(int i=1;i<=n;i++)
        v[i]=0;
}

void bfs_parcurgere() {
    int n, m = 0, m_ad[100][100] = {0}, sursa;
    ifstream fin("../in.txt");
    fin >> n;
    int x, y;
    while ( fin >> x >> y ) {
        m_ad[x][y] = 1;
        m ++;
    }
    cout << "\nVarful sursa pentru bfs: "; cin >> sursa; cout <<endl;
    bool parcurs[100] = {false};
    int distanta[100] = {0};
    queue<int> q;
    q.push(sursa);
    parcurs[sursa] = true;
    distanta[sursa] = 0;
    while (q.empty() == 0) {
        int nod = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (m_ad[nod][i] == 1 && !parcurs[i]) {
                q.push(i);
                distanta[i] = distanta[nod] + 1;
                parcurs[i] = true;
            }
        }
    }
    cout<<"Distantele sunt: ";
    for ( int i = 1; i <=n ; i ++ )
        cout <<distanta[i];
    cout<<endl;
}

void dfs_visit(int ma[100][100], int n, int varf, int parinti[100], int culoare[100], int distanta[100], int final[100], int &timp) {
    timp ++;
    distanta[varf] = timp;
    culoare[varf] = 1;
    for ( int i = 1; i <= n; i ++ )
        if (culoare[i] == 0 && ma[varf][i] == 1) {
            parinti[i] = varf;
            dfs_visit(ma, n, i, parinti, culoare, distanta, final, timp);
        }
    culoare[varf] = 2;
    timp++;
    final[varf] = timp;
}

void dfs_parcurgere() {
    int n, m = 0, m_ad[100][100] = {0}, sursa;
    ifstream fin("../in.txt");
    fin >> n;
    int x, y;
    while ( fin >> x >> y ) {
        m_ad[x][y] = 1;
        m++;
    }
    int parinti[100] = {-1}, culoare[100] = {0}; //0-alb; 1-gri; 2-negru
    int timp = 0, distanta[100] = {0}, final[100]= {0};
    for ( int i = 1; i <= n ; i ++ )
        if ( culoare[i] == 0)
            dfs_visit(m_ad, n, i, parinti, culoare, distanta, final, timp);
    cout<<endl;
    cout << "Distantele sunt: ";
    for ( int i = 1; i <= n ; i ++ )
        cout << distanta[i];
    cout<<endl;
}
int main() {

    int n, m, m_adiacenta[100][100], lungimi[100], parinti[100];
    citire_graf(n, m, m_adiacenta);
    cout << "Introduceti nodul sursa: ";
    int nod_sursa;
    cin >> nod_sursa; cout << endl;
    if (nod_sursa > n ) return 9999;
    for ( int i = 1 ; i <= n ; i ++ )
        lungimi[i] = -1;
    moore_alg(nod_sursa, n, m_adiacenta, lungimi, parinti);
    cout<<endl;
    cout<<endl;
    //inchdere tranzitiva
    inchidere_tranzitiva(m_adiacenta, n);
    //dfs
    dfs_parcurgere();
    //bfs
    bfs_parcurgere();

    return 0;
}