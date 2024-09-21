#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout << "\tBubble Sort Started ---> " << endl ;
    cout << endl << "Enter your array size : " ;
    int size ;
    cin >> size ;
    cout << endl ;
    int array [ size ] ;
    cout << "Enter your array elements : " ;
    for( int i = 0 ; i < size ; i++ )
    {
        cin >> array [ i ] ; // taking array input
    }
    cout << endl ;
    for( int step = 0 ; step < size - 1 ; step++ )
    {
        for( int i = 0 ; i < size - step - 1 ; i++)
        {
            if( array [ i ] > array [ i + 1 ] )  // bubble sort
            {
                swap( array [ i ] , array [ i + 1 ] ) ;
            }
        }
    }
    cout << "Your sorted array is : " ;
    for( int i = 0 ; i < size ; i++ )
    {
        cout << array [ i ] << " " ;
    }
    cout << endl ;
    return 0;
}