#include<stdio.h>

int sum(int a, int b);
int main(){

    int x,y,z;
    scanf("%d %d",&x,&y);

    z=sum(x,y);
    printf("%d",z);

    return 0;
}
int sum(int p,int q){
    return p+q;
}

