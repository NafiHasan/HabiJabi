#include<stdio.h>

int main (){
    int n;
    scanf("%d",&n);
    int ara[n];
    for (int i=0; i<n; i++)scanf("%d",&ara[i]);
    int x; scanf("%d", &x);
    int found[n], cnt=0;
    for (int i=0,j=0; i<n; i++){
        if (ara[i]==x){
            cnt++;
            found[j++]=i;
        }
    }
    if (cnt==0)printf("NOT FOUND\n");
    else {
        printf("FOUND at index position: ");
        for (int i=0; i<cnt ; i++){
            if (i==cnt-1)printf("%d\n",found[i]);
            else printf("%d, ",found[i]);
        }
    }
    return 0;
}