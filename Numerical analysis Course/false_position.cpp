//Program for False Position Method in C++

#include <bits/stdc++.h>

using namespace std;

double e = 0.001;

// Function used is x^3 - x - 1
double f(double x)
{
    return x * x * x - x - 1;
}

// false position user-defined function
void FalsePosition(double a, double b)
{
    if (f(a) * f(b) >= 0)
    {
        cout << "Incorrect value of a and b" << endl;
        return;
    }
    int i = 1;
    double c = (a*f(b) - b*f(a))/ (f(b)-f(a)); // step-2 (i)
    while (abs(f(c)) >= e)   // step-4
    {
        cout << "s = " << i << " ";
        i++;
        cout << "a = " << fixed << setprecision(3) << a << " ";
        cout << "b = " << fixed << setprecision(3) << b << " ";
        cout << "f(a) = " << fixed << setprecision(3) << f(a) << " ";
        cout << "f(b) = " << fixed << setprecision(3) << f(b) << " ";

        c = (a*f(b) - b*f(a))/ (f(b)-f(a));// step-2 (ii)

        if (f(c) == 0.0)   // step-3 (i)
        {
            cout << "c = " << fixed << setprecision(3) << c << " ";
            cout << "f(c) = " << fixed << setprecision(5) << f(c) <<"\t";
            break;
        }
        else if (f(c) * f(a) < 0)     // step-3 (ii)
        {
            cout << "c = " << fixed << setprecision(3) << c << " ";
            cout << "f(c) = " << fixed << setprecision(5) << f(c) <<"\t";
            b = c;
            cout << "b = c ";
        }
        else     // step-3 (iii)
        {
            cout << "c = " << fixed << setprecision(3) << c << " ";
            cout << "f(c) = " << fixed << setprecision(5) << f(c) <<"\t";
            a = c;
            cout << "a = c ";
        }
        cout << endl;
    }
    cout << "\nAccurate Root calculated is = " << fixed << setprecision(5) << c << endl;
}

int main()
{
    double a = 1, b = 2; // step-1
    cout << "The function used is x^3 - x - 1" << endl;
    cout << "Initial a = " <<fixed<<setprecision(6)<< a << "\t";
    cout << "Initial b = " <<fixed<<setprecision(6)<< b << endl << endl;
    FalsePosition(a, b);
    return 0;
}
