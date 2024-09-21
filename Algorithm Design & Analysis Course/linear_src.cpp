//linear search
#include<bits/stdc++.h>
using namespace std;

int linear_search(int a[], int size, int val)
{
    int flag = -1;
    for(int i = 0; i < size; i++)
    {
        if(a[i] == val)
        {
            flag = i;
            break;
        }
    }
    return flag;
}


int main()
{
    int n, val;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cin>>val;

    int result = linear_search(arr, n, val);

    if(result != -1) cout<<"found "<<val<<" at index "<<result<<endl;
    else cout<<"not found "<<endl;
    
    return 0;
}