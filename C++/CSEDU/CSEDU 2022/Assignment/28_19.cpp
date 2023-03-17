#include<stdio.h>

int gcd(int x, int y){
    if (y==0)return x;
    else return gcd(y, x%y);
}
int main (){
    int x,y;
    scanf("%d %d", &x,&y);
    int g=gcd(x,y);
    int lcm=(x*y)/g;
    printf("GCD: %d\nLCM: %d\n",g,lcm);
    return 0;
}