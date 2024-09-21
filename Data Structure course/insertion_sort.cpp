#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter your array size : " ;
    int size;
    cin >> size;
    cout << endl;
    int array [ size ] ;
    cout << "Enter your array elements : " ;
    for(int i = 0 ; i < size ; i++)
    {
        cin >> array [ i ] ;
    }
    cout << endl ;
    // insertion sort 
    for(int step = 1 ; step < size ; step++)
    {
        int temp = array [ step ] ;
        int j = step - 1 ;
        while(j >= 0 && array[j] >= temp)
        {
            array [ j + 1 ] = array [ j ] ;
            j--;
        }
        array [ j + 1 ] = temp ;
    }
    cout << "Your array sorted with \"Insertion sort\" : " ;
    for(int i = 0 ; i < size ; i++)
    {
        cout << array [ i ] << " " ;
    }
    return 0 ;
}