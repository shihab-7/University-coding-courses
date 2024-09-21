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

    //selection sort started
    for(int step = 0 ; step < size - 1; step++)
    {
        int minimum_index = step;
        for(int j = step + 1 ; j < size ; j++)
        {
            if(array[j] < array[minimum_index])
            {
                minimum_index = j ;
            }
            int temp = array [ minimum_index ] ;
            array [ minimum_index ] = array [ step ] ; // swaping position 
            array [ step ] = temp ;
        }
    }
    cout << "Your array sorted with \"Selection sort\" : " ;
    for(int i = 0 ; i < size ; i++)
    {
        cout << array [ i ] << " " ;
    }
    return 0;
}