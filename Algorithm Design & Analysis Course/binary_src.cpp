//binary search

#include <bits/stdc++.h>
using namespace std;

int binary_search(int a[], int size, int val )
{
    int start = 0;
    int end = size;
    
    while (start <= end)
    {
        int mid = (start + end ) / 2;

        if(a[mid]== val)
        {
            return mid;
        }
        else if(a[mid] < val)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
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

    int result = binary_search(arr, n, val);

    if(result != -1) cout<<"found "<<val<<" at index "<<result<<endl;
    else cout<<"not found "<<endl;

    return 0;
}