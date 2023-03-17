#include<stdio.h>

int main (){
    int n;
    scanf("%d", &n);
    int ara[n];
    int found;
    for (int i=0; i<n; i++) scanf("%d", &ara[i]);
    for (int i=0; i<n; i++){
        found =0;
        for (int j=0; j<i; j++){
            if (ara[i]==ara[j]){
                found=1;
                break;
            }
        }
        if (!found)printf("%d ",ara[i]);
    }
    printf("\n");
    return 0;

}