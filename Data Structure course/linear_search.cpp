#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter your Array size : ";
    int size ;
    cin>> size ;
    int array[size];
    cout<<endl;
    cout<<"Enter array elements : ";
    for(int i=0;i<size;i++)
    {
        cin>>array[i];
    }
    cout<<endl;
    cout<<"Your array : ";
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter an element you want to find : ";
    int element;
    cin>>element;
    bool found = false;
    int index ;
    for(int i=0;i<size;i++)
    {
        if(element == array[i])  // linear search 
        {
            found = true;
            index = i;
        }
    }
    if(found) cout<<"Your element found at index : "<<index+1<<endl;
    else cout<<"Not found"<<endl;
    
    return 0;
}