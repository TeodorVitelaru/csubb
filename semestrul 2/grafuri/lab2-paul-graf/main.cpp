#include <fstream>
#include <queue>
#include <iostream>

using namespace std;

ifstream fin("dfs.txt");

void reset_vector(int v[],int n){
    for(int i=1;i<=n;i++)
        v[i]=0;
}

void DFS(int a[][101],int v[],int n,int nod){
    cout<<nod<<' ';
    v[nod]=1;
    for(int i=1;i<=n;i++)
        if(v[i]==0 && a[nod][i]==1)
            DFS(a,v,n,i);
}

void BFS(int a[][101],int v[],int p[],int n,int nod){
    queue<int> q;
    v[nod]=1;
    q.push(nod);
    while(!q.empty()){
        int u=q.front();
        cout<<u<<' ';
        q.pop();
        for(int i=1;i<=n;i++)
            if(v[i]==0 && a[u][i]==1){
                q.push(i);
                v[i]=1;
                p[i]=u;
            }
    }
}

void inchidere_tranzitiva(int a[][101],int n){
    for(int i=1;i<=n;i++)
        a[i][i]=1;
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (a[i][j] == 0 && a[k][j] == 1 && a[i][k] == 1)
                    a[i][j] = 1;
    }
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<' ';
}

int main(){
    int a[101][101],v[101],p[101],d[101],x,n,m;
    fin>>n>>m>>x;
    while(m){
        int i,j;
        fin>>i>>j;
        a[i][j]=a[j][i]=1;
        m--;
    }
    //dfs
    reset_vector(v,n);
    cout<<"Nordurile parcurse prin dfs de la nodul "<<x<<" sunt: ";
    DFS(a,v,n,x);
    cout<<endl;
    //bfs
    reset_vector(v,n);
    reset_vector(p,n);
    reset_vector(d,n);
    cout<<"Nordurile parcurse prin bfs de la nodul "<<x<<" sunt: ";
    BFS(a,v,p,n,x);
    cout<<". Nordurile parinti sunt: ";
    for(int i=1;i<=n;i++)
        cout<<p[i]<<' ';
    cout<<".Distantele sunt: ";
    for(int i=1;i<=n;i++)
        cout<<d[i]<<' ';
    //inchiderea tranzitiva
    cout<<endl;
    inchidere_tranzitiva(a,n);

    return 0;
}