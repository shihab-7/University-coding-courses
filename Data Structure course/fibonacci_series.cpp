#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter your number : ";
    int num ;
    cin >> num ;
    if(num == 0) cout << "Your Fibonacci series : " << 0 << endl ;
    else if(num == 1) cout << "Your Fibonacci series : " << 1 << endl ;
    else
    {
        int arr[num] ;
        arr[0] = 0 ;
        arr[1] = 1 ;
        for(int i = 2 ; i < num ; i++)
        {
            arr[i] = arr[i-1] + arr[i-2] ;  // fibonacci implementation
        }
        cout << "Your Fibonacci series : ";
        for(int i = 0 ; i < num ; i++)
        {
            cout << arr[i] <<" " ;
        }
    }
    return 0;
}