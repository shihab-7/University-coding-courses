#include<stdio.h>

void swap(int *a, int *b)

{
    int d = *a;
    *a = *b;
    *b = d;
}

int main(void)

{
    int n1 = 5;
    int n2 = 15;

    printf("%d %d\n", n1, n2);
    
    swap(&n1, &n2);
    
    printf("%d %d\n", n1, n2);
    
    return 0;
}
