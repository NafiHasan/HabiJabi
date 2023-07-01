#include <stdio.h>

void reverse_array(int *a, int n){
    if (n<=)return;
    int tmp=a;
    a=a[n-1];
    a[n-1]=tmp;
    reverse_array(a,start+1,n-1);
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    reverse_array(a,0,n);
    for (int i=0; i<n; i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}