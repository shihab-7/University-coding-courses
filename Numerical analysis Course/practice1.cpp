#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    return (2*pow(x,3))-(2*x)-5;
}

void Bisection(double a,double b, double e)
{
    if(f(a)*f(b)>=0)
    {
        cout<<"wrong value of a,b"<<endl;
        return;
    }
    int i=1;
    double c=(a+b)/2;
    while(abs(f(c))>=e)
    {
        c = (a+b)/2;
        cout<<"n = "<<i<<" ";
        i++;
        cout<<fixed<<setprecision(3);
        cout<<"a = "<<a<<" ";
        cout<<"b = "<<b<<" ";
        cout<<"f(a) = "<<f(a)<<" ";
        cout<<"f(b) = "<<f(b)<<" ";
        if(f(c)==0.0)
        {
            cout<<"c = "<<c<<" ";
            cout<<"f(c) = "<<f(c)<<" ";
            break;
        }
        else if(f(a)*f(c)<0)
        {
            cout<<"c = "<<c<<" ";
            cout<<"f(c) = "<<f(c)<<" ";
            b=c;
            cout<<"b = c"<<" ";
        }
        else
        {
            cout<<"c = "<<c<<" ";
            cout<<"f(c) = "<<f(c)<<" ";
            a=c;
            cout<<"a = c"<<" ";
        }
        cout<<endl;
    }
    cout<<"answer : "<<fixed<<setprecision(5)<<c<<endl;
}

int main()
{
    double a,b,e=0.001;
    cin>>a>>b;

    Bisection(a,b,e);
    return 0;
}
