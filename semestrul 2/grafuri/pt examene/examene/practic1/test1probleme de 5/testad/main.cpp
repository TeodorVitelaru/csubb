#include <iostream>
#include<fstream>

using namespace std;

//din matrice adiacenta in lista
int a[101][101],n,b[101][101],nr_muchii=0;
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
    {
        int k = 1;
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 1)
            {
                k = k + 1;
                b[i][k] = j;
            }
    }
    for (int i = 1; i <= n; i++)
        b[i][1] = i;

    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cout<<b[i][j];
            cout<<endl;
        }
    return 0;
}
