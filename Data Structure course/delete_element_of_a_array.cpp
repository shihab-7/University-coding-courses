#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter array size : ";
    int n;
    cin >> n;
    int a[n];
    cout << "Enter your elements : ";
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i] ;  //taking array input
    }
    cout << "Your given array : ";
    cout << "[ ";
    for(int i = 0 ; i < n ; i++)
    {
        cout << a[i] << " ";  // showing inputted array
    }
    cout << "]";  
    cout << endl << "Deletion start >>>" << endl;
    cout << "Enter your position to delete : ";
    int p;
    cin >> p ;
    for(int i = p-1 ; i <= n ; i++)
    {
        a[i] = a[i+1] ; //deletion is occuring
    }
    n-=1;
    cout << endl << "Your array after Deletion : ";
    cout << "[ ";
    for(int i = 0 ; i < n ; i++)
    {
        cout << a[i] << " "; // outputting final array after deletion
    }
    cout << "]";
    cout<<endl;
    return 0;
}