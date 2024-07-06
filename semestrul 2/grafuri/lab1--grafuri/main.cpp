#include <iostream>
#include <fstream>
using namespace std;


void matrice_adiacenta()
{
    int m_adiacenta[100][100]={0};
    ifstream fin ("../in.txt");
    int n, m;
    fin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x, y;
        fin>>x>>y;
        m_adiacenta[x][y]=m_adiacenta[y][x]=1;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<m_adiacenta[i][j]<<" ";
        cout<<"\n";
    }
    cout<<endl;
}

void matrice_incidenta()
{
    int m_incidenta[100][100]={0};
    ifstream fin ("../in.txt");
    int n, m;
    fin >> n;
    fin >> m;
    for(int i=1; i<=m; i++)
    {
        int x, y;
        fin>>x>>y;
        m_incidenta[x][i]=m_incidenta[y][i]=1;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            cout << m_incidenta[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void lista_adiacenta()
{
    int l_ad[100][100] = {0};
    ifstream fin ("../in.txt");
    int n, m;
    fin >> n;
    fin >> m;
    for(int i=1; i<=m; i++)
    {
        int x, y;
        fin>>x>>y;
        l_ad[x][1]++;
        l_ad[x][l_ad[x][1] + 1] = y;
        l_ad[y][1]++;
        l_ad[y][l_ad[y][1] + 1] = x;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<< l_ad[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}



int main() {
    matrice_adiacenta();
    matrice_incidenta();
    lista_adiacenta();

    return 0;
}
