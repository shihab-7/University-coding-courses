#include<iostream>
#include<iomanip>
using namespace std;

float f(float x)
{
    return 1/(1+(x*x));
}
int main()
{
    float a,b,h;
    int n;
    cout<<"Enter upper limit, lower limit and step size : \n";
    cin>>b>>a>>n;
    float X[n+1],Y[n+1];
    X[0]=a;
    Y[0]= f(X[0]);
    h = (b-a)/n;
    for(int i=1;i<=n;i++)
    {
        X[i] = X[i-1]+h;
        Y[i] = f(X[i]);
    }
    //written.
    for(int i=0; i<=n;i++)
    {
        cout<<fixed<<setprecision(6);
        cout<<'x'<<i<<"="<<X[i]<<"\t"<<'y'<<i<<"="<<Y[i]<<endl;
    }
    cout<<endl;
    float tmp = 0,odd_term_sum=0,even_term_sum=0,remaining_term=0,multiple_of_3_term=0;
    for(int i=1;i<n;i++)
    {
        tmp+=Y[i];
        if(i%2==0)
            even_term_sum+=Y[i];
        else
            odd_term_sum+=Y[i];
        if(i%3==0)
            multiple_of_3_term+=Y[i];
        else
           remaining_term+=Y[i];

    }
    float ans1 = (h/2)*((Y[0]+Y[n]) + 2*tmp);
    float ans2 = (h/3)*((Y[0]+Y[n])+ (4*odd_term_sum)+(2*even_term_sum));
    float ans3 =  ((3*h)/8)*((Y[0]+Y[n])+ 3*remaining_term + 2*multiple_of_3_term);
    cout<<"Using Trapezoidal rule Answer is : "<<ans1<<endl;
    if(n%2==0)
        cout<<"Using Simpson's 1/3 rule Answer is : "<<ans2<<endl;
    else
        cout<<"Total number of interval (n) is odd so Simpson's 1/3 rule is not applicable\n";
    if(n%3==0)
        cout<<"Using Simpson's 3/8 rule Answer is : "<<ans3<<endl;
    else
        cout<<"Total number of interval (n) is not a multiple of 3 so Simpson's 3/8 rule is not applicable\n";
    return 0;
}
