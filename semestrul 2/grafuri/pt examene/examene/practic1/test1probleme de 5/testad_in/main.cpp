#include<iostream>
#include<fstream>

using namespace std;

int matrice_adiacenta[101][101], nr_muchii=0, n, matrice_incidenta[101][101];
ifstream f("in.txt");

int main()
{
    f>>n;
    int x,y;
    while(f>>x>>y)
    {
        nr_muchii++;
        matrice_adiacenta[x][y]=matrice_adiacenta[y][x]=1;
    }

    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (matrice_adiacenta[i][j] == 1 && i<j)
            {
                k = k + 1;
                matrice_incidenta[i][k] = 1;
                matrice_incidenta[j][k] = 1;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=nr_muchii;j++)
            cout<<matrice_incidenta[i][j];
        cout<<endl;
    }
    return 0;
}
