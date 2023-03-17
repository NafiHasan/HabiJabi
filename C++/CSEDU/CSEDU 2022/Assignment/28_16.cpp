#include<stdio.h>
#include<math.h>

int main (){
    int x,m;
    scanf("%d %d", &x,&m);
    long long ans=0;
    for(int i=0; i<=m; i++){
        ans+=(long long)pow(x,i);
    }
    printf("%lld\n",ans);
}