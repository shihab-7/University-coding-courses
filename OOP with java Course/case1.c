#include<stdio.h>

int test(int x, int *y, int z)
{
    return x+(*y)+z;

}

int main()
{
    int a =2 , b=3, c=4, result;

    result = test(a, &b, &c);

    printf("%d", result);

    return 0;
}