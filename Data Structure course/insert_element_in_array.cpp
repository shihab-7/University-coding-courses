#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter array size : ";
    int n ;
    cin >> n ;
    int a[n] ;
    cout<<"Enter elements : ";
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i] ;  //taking array input
    }
    cout << "Your given array : ";
    cout << "[ ";
    for(int i = 0 ; i < n ; i++)
    {
        cout << a[i] << " "; // showing inputted array
    }
    cout << "]";
    cout << endl << "Insertion start >>> " << endl;
    cout << "Enter position and value : ";
    int pos , val;
    cin >> pos >> val;
    for(int i = n ; i >= pos-1 ; i--)
    {
        a[i] = a[i-1] ;
    }                   //insertion part
    n++ ;
    a[pos-1] = val ;
    cout << "Your array after insertion : [";
    for(int i = 0 ; i < n ; i++)
    {
        cout << a[i] << " " ; //showing output array after changing
    }
    cout << "]" ;
    cout << endl ;
    return 0 ;
}