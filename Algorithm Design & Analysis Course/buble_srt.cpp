//buble sort

#include <bits/stdc++.h>
using namespace std;

void print_ar(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << a[i] <<" ";
    }
}
void swapY(int  &x, int &y)
{
    int tmp = x;
    x=y;
    y=tmp;
}

void buble_srt(int a[], int size)
{
    bool flag;
    for(int i = 0; i<size - 1; i++)
    {
        flag = false;
        for(int j = 0; j < size-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                swapY(a[j], a[j+1]);
                flag = true;
            }
        }
        if(flag==false)
        {
            break;
        }
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
    buble_srt(arr,n);
    print_ar(arr,n);
    return 0;
}