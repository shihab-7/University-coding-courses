//selection sort

#include <bits/stdc++.h>
using namespace std;

void swapY(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void selection_srt(int a[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int mid_indx = i;
        for(int j= i+1  ; j < size ; j++)
        {
            if(a[j] < a[mid_indx])
            {
                mid_indx = j;
            }
        }
        if(mid_indx != i)
        {
            swapY(a[mid_indx], a[i]);
        }
    }
}

void print_ar(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] <<" ";
    }
    
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    selection_srt(arr,n);
    print_ar(arr,n);

    return 0;
}