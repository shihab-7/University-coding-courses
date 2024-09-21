#include<stdio.h>
void swapc(int x, int y)
{

    printf("x = %p y = %p \n", &x, &y);
    int box;
    box=x;
    x=y;
    y=box;
}

int main()
{
    int a, b;

    // printf("%p",&a);

    scanf("%d %d",&a,&b);
    swapc(a,b);
    printf("a=%p b=%p",&a,&b);
    


    return 0;
}