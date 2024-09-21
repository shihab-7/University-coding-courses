#include <stdio.h>
int sum(int x1, int *x2, int x3);
int main()
{
    int a1, a2, a3, result;
    scanf("%d %d %d", &a1, &a2, &a3);
    result = sum(a1, &a2, &a3);
    printf("%d", result);
    return 0;
}
int sum(int p1, int *p2, int p3)
{
    p1 = 5;
    *p2 = 7;
    p3 = 4;

    return (p1,*p2,p3);
}