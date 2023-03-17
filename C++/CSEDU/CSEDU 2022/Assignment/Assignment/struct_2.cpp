#include <stdio.h>

int gcd(int a, int b){
    if(b==0)return a;
    else return gcd(b, a%b);
}

int lcm(int a, int b){
    int x=gcd(a,b);
    return a*b/x;
}

typedef struct{
    int p;
    int q;
}rational;

void add (int p1, int q1, int p2, int q2){
    int x=lcm(q1,q2)/q1*p1;
    int y=lcm(q1,q2)/q2*p2;
    int g = gcd(x + y, lcm(q1, q2));
    printf("%d/%d\n", (x + y) / g, lcm(q1, q2) /g);
}

int main (){
    rational a[2];
    for(int i=0; i<2; i++)
        scanf("%d %d",&a[i].p, &a[i].q);
    add (a[0].p,a[0].q,a[1].p,a[1].q);
    return 0;
}