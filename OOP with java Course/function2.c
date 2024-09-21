#include<stdio.h>

int square(int x)
{
    return x*x;
}

int main()
{
    int x = 5;

    printf("%d", square(x));
    
    return 0;
}