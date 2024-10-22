#include <iostream>
#include<fstream>

using namespace std;
//din lista in matrice incidenta

int a[101][101],n,d[101][101],nr_muchii=0;
ifstream f("in.txt");

int main()
{
    f>>n;
    int x,y;
    while(f>>x>>y)
        {
            nr_muchii++;
            a[x][y]=a[y][x]=1;
        }
    int k=0;
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                if(a[i][j]==1 && i<j)
                    {
                        k=k+1;
                        d[i][k]=1;
                        d[j][k]=1;
                    }
        }
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=nr_muchii;j++)
                cout<<d[i][j];
            cout<<endl;
        }
    return 0;
}
