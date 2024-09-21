#include<stdio.h>

int sum(int a, int *b, int c);
int main(){
    int x,y,z,result;
    scanf("%d %d %d",&x,&y,&z);
    z=sum(x , &y, &z);
    printf("%d",z);
    return 0;
}
int sum(int p,int *q, int r){
    p= 3;
    *q= 2;
    r= 5;
    return p +(*q)+ r;
}
