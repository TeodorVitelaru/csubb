#include <iostream>
#include <iostream>
#include<fstream>

using namespace std;

//din lista in matrice adiacenta
int a[101][101],n,nr_muchii=0,b[101][101];
ifstream f("in.txt");

int main()
{
    int c[10];
    f>>n;
    int x,y;
    while(f>>x>>y)
        {
            nr_muchii++;
            a[x][y]=a[y][x]=1;
        }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= c[i]; j++)
            a[i][b[i][j]] = 1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j];
        cout<<endl;
    }
    return 0;
}
