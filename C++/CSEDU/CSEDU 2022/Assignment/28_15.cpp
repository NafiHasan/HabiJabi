#include<stdio.h>
#include<math.h>

double fact (double a){
    double mul=1;
    for (double i=2; i<=a; i++)mul*=i;
    return mul;
}

int main(){
    int x;
    scanf("%d", &x);
    double ans=(double)x;
    int j=1;
    for(double i= 3; i<=15; i+=2,j++){
        if (j%2==1)ans-=(pow((double)x,i)/fact(i));
        else
            ans += (pow((double)x, i) / fact(i));
    }
    printf("%lf\n",ans);
    return 0;
}