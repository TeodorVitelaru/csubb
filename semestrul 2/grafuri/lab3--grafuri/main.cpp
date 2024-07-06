#include <iostream>
#include <fstream>

using namespace std;

int v,e,s,a[10][10],x,y,w,d[10],p[10];

void djaikstras()
{

}

int main(int argc,char * argv[]) {
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    fin>>v>>e>>s;
    for(int i = 1;i <=e;i++)
    {
        fin>>x>>y>>w;
        a[x][y] = w;
    }
    int inf = 10000;
    for(int i=0; i<v; i++)
    {
        d[i]=inf;
        p[i]=-1;
    }
    d[s]=0;
    for(int k=0; k<v-1; k++)
        for(int i=0; i<v; i++)
            for(int j=0; j<v; j++)
                if(a[i][j] && d[i]<inf)
                    if(d[j]>d[i]+a[i][j])
                        d[j]=d[i]+a[i][j], p[j]=i;
    for(int i=0; i<v; i++)
        if(d[i] != inf)
            fout<<"Drumul de la "<<s<<" la "<<i<<" este de cost "<<d[i]<<'\n';
        else
            fout<<"Drumul de la "<<s<<" la "<<i<<" este de cost infinit"<<'\n';
    fout<<endl;
    fin.close();
    fout.close();
    return 0;
}