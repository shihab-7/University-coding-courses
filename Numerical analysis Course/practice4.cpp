#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double x[n],y[n],table[n][n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        table[i][0]=y[i];
    }
    for(int j=1;j<n;j++)
    {
        for(int i=0;i<n-j;i++)
        {
            table[i][j]= table[i+1][j-1] - table[i][j-1];
        }
    }
    cout<<"forward diff table : "<<endl;
    for(int j=0;j<n;j++)
    {
        cout<<x[j];
        for(int i=0;i<n-j;i++)
        {
            cout<<" "<<table[j][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
