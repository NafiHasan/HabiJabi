#include<stdio.h>

int main (){
    int n;
    scanf("%d", &n);
    double ans=0;
    for (int i=1; i<=n; i++){
        if (i%2==0)ans-=1.0/(double)i;
        else
            ans += 1.0 / (double)i;
    }
    printf("%.2lf\n",ans);
}