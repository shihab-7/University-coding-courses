#include<stdio.h>

int sum(int a, int b);

int main()
{
    int p = 4, q = 5;

    int total = sum(p , q);

    printf("%d", total);
     
    return 0;
}


int sum(int x, int y)
{
    int ans = x + y ;
    return ans;
}