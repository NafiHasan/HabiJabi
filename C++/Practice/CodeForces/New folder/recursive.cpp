#include <stdio.h>

int dec_to_binary(int *a, int i, int n){
    if (n == 0) {
        printf("last %d\n",i);
        return (i - 1);
    }
    else {
        if (n % 2 == 0)
            a[i] = 0;
        else
            a[i] = 1;
        i++;
        printf("%d %d\n", n,i);
        dec_to_binary(a, i, n / 2);
    }
    return i-1;
}
int main ()
{
    int a[10000];
    int n;
    scanf("%d", &n);
    int end;
    end= dec_to_binary(a,0,n);
    printf("%d\n",end);
    for (int i=end; i>=0; i--) printf("%d",a[i]);
    printf("\n");
    return 0;
}