// adjecency matrix

#include <bits/stdc++.h>
using namespace std;

const int N = 1000; 

int adjmatrix[N][N];

int main()
{
    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        int u,v;
        //weights o deowa thakle u,v er sathe w o input neowa lagto r index a 1 er jaygate w assign kora lagto
        cin>> u >> v;
        adjmatrix[u][v] = 1;
        adjmatrix[v][u] = 1; // undirected graph thakle ei 2 ta line ei

        // r directed graph er jonno sudhu adjmatrix[u][v] = 1 dilei hobe  
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<adjmatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}