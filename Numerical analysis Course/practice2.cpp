#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    return (2*pow(x,3))-(2*x)-5;
}

void FalsePosition(double a, double b, double e)
{
    if(f(a)*f(b)>=0)
    {
        cout<<"invalid a,b"<<endl;
        return;
    }
    int i=1;
    double c = ((a*f(b))-(b*f(a)))/(f(b)-f(a));
    while(abs(f(c))>=e)
    {
        cout<<fixed<<setprecision(5);
        cout<<"n = "<<i<<" ";
        i++;
        cout<<"a = "<<a<<" ";
        cout<<"b = "<<b<<" ";
        cout<<"f(a) = "<<f(a)<<" ";
        cout<<"f(b) = "<<f(b)<<" ";

        c = ((a*f(b))-(b*f(a)))/(f(b)-f(a));
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
    cout<<"answer :  " <<fixed<<setprecision(5)<<c<<endl;
}

int main()
{
    double a,b,e=0.001;
    cin>>a>>b;
    FalsePosition(a,b,e);
    return 0;
}
