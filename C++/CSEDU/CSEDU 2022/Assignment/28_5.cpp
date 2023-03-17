#include<stdio.h>
int main (){
    int x,y;
    scanf("%d %d", &x, &y);
    if (x>0 && y>0)printf("1\n");
    else if (x==0 && y==0)printf("Origin\n");
    else if (x==0)printf("Y axis\n");
    else if (y==0) printf("X axis\n");
    else if (x>0 && y<0) printf("4\n");
    else if(x<0 && y>0) printf("2\n");
    else printf("3\n");
    return 0;
}