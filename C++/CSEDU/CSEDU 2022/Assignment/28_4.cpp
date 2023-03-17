#include<stdio.h>
#include<stdlib.h>

int main (){
    int x,y,z;
    scanf("%d %d %d", &x, &y, &z);
    int sum=x+y+z;
    int minn,maxx;
    if (x<=y && x<=z)minn=x;
    else if (y<=x && y<=z)minn=y;
    else minn=z;
    if (x>=y && x>=z)maxx=x;
    else if (y>=z && y>=x)maxx=y;
    else maxx=z;
    printf("minimum = %d\nmaximum = %d\nmedian = %d\n",minn,maxx,sum-(minn+maxx));
    return 0;
}