#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter total number of data sets : ";
    cin>>n;
    cout<<"\nEnter a value of X data set then a value of Y data set : \n";
    int X[n],Y[n],table[n][n];
    for(int i=0;i<n;i++)
    {
        cin>>X[i]>>Y[i];
        table[i][0]=Y[i];
    }
    for(int j=1;j<n;j++)
    {
        for(int i=0;i<n-j;i++)
        {
            table[i][j]=table[i+1][j-1] - table[i][j-1];
        }
    }
    cout<<endl;
    cout<<"The table is : \n";
    for(int i=0;i<n;i++)
    {
        cout<<X[i];
        for(int j=0;j<n-i;j++)
        {
            cout<<" "<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
