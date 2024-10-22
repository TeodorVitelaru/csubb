#include <iostream>
#include<fstream>

using namespace std;

//din matrice incidenta in matrice adiacenta
int a[101][101],n,b[101][101],d[101][101],nr_muchii=0;
ifstream f("in.txt");

using namespace std;

int main()
{
    f>>n;
    int x,y;
    while(f>>x>>y)
    {
        nr_muchii++;
        a[x][y]=a[y][x]=1;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= nr_muchii; j++)
            for (int z = 1; z <= n; z++)
                if (d[i][j] == 1 && d[z][j] == 1 && z != i)
                    a[i][z] = 1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j];
        cout<<endl;
    }
    return 0;
}
