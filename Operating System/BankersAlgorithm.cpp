#include <bits/stdc++.h>
using namespace std;

void Bankers_algorithm(vector<vector<int>> &am, vector<vector<int>> &nm,vector<int>&a,int n, int m)
{
    vector<bool> finish(n,0);
    vector<int> safe_sequence(n);
    vector<int> work(m);
    for(int i=0;i<m;i++) work[i]=a[i];
    int cnt=0;
    while(cnt<n)
    {
        bool found=0;
        for(int i=0; i<n;i++)
        {
            if(!finish[i])
            {
                int j;
                for(j=0; j<m; j++)
                {
                    if(nm[i][j]>work[j]) break;
                }
                if(j==m)
                {
                    for(int k=0; k<m; k++)
                    {
                        work[k]+=am[i][k];
                    }
                    safe_sequence[cnt++]=i;
                    finish[i]=1;
                    found=1;
                }
            }
        }
        if(!found)
        {
            cout<<"system is in unsafe state\n";
            return;
        }
    }
    cout<<"System is in a safe state.\nSafe sequence is: ";
    for(int i=0; i<n; i++)
    {
        cout<<"P"<<safe_sequence[i]<<" ";
        if(i!=n-1)
        {
            cout<<"-> ";
        }
    }
    cout<<endl;
}

int main()
{
    int n,m;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "\nEnter the number of resources: ";
    cin >> m;
    vector<vector<int>> Allocation_matrix(n,vector<int>(m)), Max_matrix(n,vector<int>(m)), Need_matrix(n,vector<int>(m));vector<int>Available(m);
    cout << "\nEnter the Allocation matrix:\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> Allocation_matrix[i][j];
        }
    }
    cout << "\nEnter the Max matrix:\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> Max_matrix[i][j];
        }
    }
    cout << "\nEnter the Available resources :\n";
    for(int i=0; i<m; i++) cin >> Available[i];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            Need_matrix[i][j] = Max_matrix[i][j] - Allocation_matrix[i][j];
        }
    }
    Bankers_algorithm(Allocation_matrix, Need_matrix, Available, n, m);
    return 0;
}