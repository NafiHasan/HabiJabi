#include<stdio.h>
int main (){
    int n;
    scanf("%d",&n);
    long long int a[n],cnt=0,pos=0;
    for (int i=0; i<n; i++){
        scanf("%lld", &a[i]);
        if (a[i]<0)cnt++;
        if (a[i])pos++;
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n-1; j++){
            if (a[j]>a[j+1]){
                long long tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }
    long long ans=1;
    for (int i=0; i<n; i++){
        if (cnt%2 && i+1==cnt)continue;
        if (pos && a[i]==0)continue;
        if (i)printf(" ");
        printf("%lld",a[i]);
    }
    printf("\n");
    return 0;
}