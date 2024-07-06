#include <iostream>
#include <fstream>
using namespace std;

void noduri_izolate()
{
    int n, m;
    ifstream fin ("../in.txt");
    fin>>n>>m;
    int x, y;
    int v[100]={0};
    for(int i=1; i<=m; i++)
    {
        fin>>x>>y;
        v[x]=v[y]=1;
    }
    cout<<"Nodurile izolate sunt: ";
    bool ok = false;
    for(int i=1; i<=n; i++)
        if(v[i]==0)
        {
            cout<<i<<" ";
            ok = true;
        }
    if(!ok)
        cout<<"Nu exista";
    cout<<endl;
}

bool graf_regular()
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
    int cnt = l_ad[1][1];
    for(int i=2; i<=n; i++)
    {
        if(l_ad[i][1] != cnt)
            return false;
    }
    return true;

}

void matricea_distantelor()
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
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(m_adiacenta[i][j]!=0 && m_adiacenta[i][k]!=0 && m_adiacenta[k][j]!=0)
                    m_adiacenta[i][j]=min(m_adiacenta[i][j],m_adiacenta[i][k]+m_adiacenta[k][j]);
                else if(m_adiacenta[i][k]!=0 && m_adiacenta[k][j]!=0 && i!=j)
                    m_adiacenta[i][j]=m_adiacenta[i][k]+m_adiacenta[k][j];

    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=n;j++)
            cout<<m_adiacenta[i][j]<<' ';
    cout<<endl<<endl;
}

bool graf_conex()
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
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(m_adiacenta[i][j]!=0 && m_adiacenta[i][k]!=0 && m_adiacenta[k][j]!=0)
                    m_adiacenta[i][j]=min(m_adiacenta[i][j],m_adiacenta[i][k]+m_adiacenta[k][j]);
                else if(m_adiacenta[i][k]!=0 && m_adiacenta[k][j]!=0 && i!=j)
                    m_adiacenta[i][j]=m_adiacenta[i][k]+m_adiacenta[k][j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<i; j++)
            if(m_adiacenta[i][j] == 0)
                return false;
    return true;
}

int main() {
    noduri_izolate();
    if(graf_regular())
    {
        cout<<"Este graf regular"<<endl;
    } else
    {
        cout<<"NU este graf regular"<<endl;
    }
    matricea_distantelor();
    if(graf_conex())
    {
        cout<<"Graful este convex";
    } else
    {
        cout<<"Graful nu este conex";
    }
    return 0;
}
