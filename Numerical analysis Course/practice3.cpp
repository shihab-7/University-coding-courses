#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    //return 1/(1+pow(x,2));
    return sqrt(1+pow(x,2));
}

int main()
{
    double a,b,h;
    int n;
    cin>>a>>b>>n;
    double X[n+1],Y[n+1];
    h = (b-a)/n;
    X[0]= a;
    Y[0] = f(X[0]);
    for(int i=1;i<=n;i++)
    {
        X[i]= X[i-1]+h;
        Y[i]=f(X[i]);
    }
    cout<<fixed<<setprecision(6);
    for(int i=0;i<=n;i++)
    {
        cout<<"x"<<i<<" = "<<X[i]<<" "<<"y"<<i<<" = "<<Y[i]<<endl;
    }
    double tmp=0,even_terms=0,odd_terms=0,remainings=0,mul_of_3=0;
    for(int i=1;i<n;i++)
    {
        tmp+=Y[i];
        if(i%2==0) even_terms+=Y[i];
        else odd_terms+=Y[i];
        if(i%3==0) mul_of_3+=Y[i];
        else remainings+=Y[i];
    }
    double ans1 = (h/2) * ((Y[0]+Y[n])+ (2*tmp));
    double ans2 = (h/3) * ((Y[0]+Y[n]) + (4*odd_terms)+ (2*even_terms));
    double ans3 = ((3*h)/8) * ((Y[0]+Y[n]) + (3*remainings)+(2*mul_of_3));
    cout<<"Trapezoidal : "<<ans1<<endl;
    if(n%2==0)cout<<"Simpson 1/3 : "<<ans2<<endl;
    if (n%3==0)cout<<"Simpson 3/8 : "<<ans3<<endl;
    return 0;
}
