#include <stdio.h>
int main(){
    long long n;
    scanf("%lld",&n);
    int a[20];
    bool neg=false;
    if(n<0){
        neg = true;
        n*=-1;
    }
    int cnt=0;
    if (n==0){
        a[0] = 0;
        cnt=1;
    }
    while(n!=0){
        a[cnt++]=n%10;
        n/=10;
    }
    for(int i=0; i<cnt-1 ; i++){
        for(int j=i+1; j<cnt; j++){
            if (a[i]>a[j]){
                int tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
    if (cnt==1 && !neg){
        printf("Maximum = %d\n",a[0]);
        printf("Minimum = %d\n",a[0]);
    }
    else if (cnt == 1 && neg)
    {
        printf("Maximum = -%d\n", a[0]);
        printf("Minimum = -%d\n", a[0]);
    }
    else if (neg){
        int ind = 0, i = 0,tmp;
        bool swapped=false;
        while (a[i] == 0)
            ind = ++i;
        if (a[0] == 0)
        {
            tmp = a[0];
            a[0] = a[ind];
            a[ind] = tmp;
            swapped=true;
        }
        printf("Maximum = -");
        for (int j = 0; j < cnt; j++)
            printf("%d", a[j]);
        puts("");
        if (swapped){
            tmp = a[0];
            a[0] = a[ind];
            a[ind] = tmp;
        }
        printf("Minimum = -");
        for (int j=cnt-1; j>=0; j--)printf("%d",a[j]);
        puts("");
    }
    else {
        printf("Maximum = ");
        for (int j=cnt-1; j>=0; j--)printf("%d",a[j]);
        puts("");
        int ind=0, i=0;
        while (a[i]==0)ind=++i;
        if (a[0]==0){
            int tmp = a[0];
            a[0]=a[ind];
            a[ind]=tmp;
        }
        printf("Minimum = ");
        for (int j=0; j<cnt; j++)printf("%d",a[j]);
        puts("");
    }
    return 0;
}