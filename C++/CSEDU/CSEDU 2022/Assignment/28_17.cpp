#include<stdio.h>
#include<math.h>

double fact(double x){
    double ans=1;
    for (double i=1; i<=x; i++)ans*=i;
    return ans;
} 

int main (){
    int n,x;
    scanf("%d %d", &x, &n);
    double ans=1.0;
    for (double i=1; i<=n; i++){
        double term=(double)((double)pow((double)x,i)/fact(i));
        ans+=term;
    }
    printf("%.2lf\n",ans);
    return 0;
}