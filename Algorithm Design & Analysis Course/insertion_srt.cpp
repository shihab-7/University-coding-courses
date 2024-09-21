//insertion sort

#include <bits/stdc++.h>
using namespace std;

void insertion_srt(int a[], int size)
{
    for(int i=1;i<size;i++)
    {
        int key = a[i];
        int j = i-1;
        while( j>=0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}


void print_ar(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << a[i] <<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    insertion_srt(arr,n);
    print_ar(arr,n);

    return 0;
}