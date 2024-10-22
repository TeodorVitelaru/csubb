#include <iostream>
#include<fstream>

using namespace std;

int a[101][101],n;
ifstream f("in.txt");

void Roy_Warshall(int a[101][101]) {
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (a[i][j] == 0)
                    a[i][j] = a[i][k] * a[k][j];
}

int main()
{
    int x, y;
    f>> n;
    while (f >> x >> y) {
        a[x][y] = 1;
        a[y][x] = 1;
    }
    Roy_Warshall(a);
    return 0;
}
