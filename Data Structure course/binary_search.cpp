#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter array size : " ;
    int size ;
    cin >> size;
    int array [ size ] ;
    cout << endl ;
    cout << "Enter array elements : " ;
    for( int i = 0 ; i < size ; i++)
    {
        cin >> array [ i ] ; // taking array input
    }
    cout << endl ;
    cout << "Enter your value you want to find : " ;
    int value ;
    cin >> value ;
    cout << endl ;
    int left = 0, right = size - 1 , index = 0 ;
    bool flag = false ;
    while( left <= right )
    {
        int mid = ( left + right) / 2;
        if( array [ mid ] == value )
        {
            index = mid ;
            flag = true ;
        }                                  // binary search implementation
        if( value > array [ mid ] )
        {
            left = mid + 1 ;
        }
        else
        {
            right = mid - 1 ;
        }
    }
    if ( flag ) cout << "Element found at index : " << index << endl ;
    else cout << "Element not found" << endl ;
    return 0;
}