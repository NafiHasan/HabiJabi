#include<stdio.h>

int main (){
    int n,m;
    scanf("%d", &n);
    int ara[n];
    for(int i=0; i<n; i++)scanf("%d",& ara[i]);
    scanf("%d", &m);
    int ara2[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &ara2[i]);
    int I[n+m], U[n+m], D[n+m];
    int cnt=0;
    for(int i=0,k=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (ara[i]==ara2[j]){
                I[k++] = ara[i];
                cnt++;
            }
        }
    }
    if (cnt==0)printf("Empty set");
    else {
        printf("I: ");
        for (int i = 0; i < cnt; i++)
            printf("%d ", I[i]);
    }
    printf("\n");
    for (int i = 0, k = 0; i < n; i++)
    {
        U[i]=ara[i];
    }
    for (int i=0, k=n; i<m; i++){
        U[k++]=ara2[i];
    }
    int finu[n+m];
    cnt=0;
    for (int i = 0,k=0; i < n+m; i++)
    {
        int found = 0;
        for (int j = 0; j < i; j++)
        {
            if (U[i] == U[j])
            {
                found = 1;
                break;
            }
        }
        if (!found){
            cnt++;
            finu[k++]=U[i];
        }
    }
    printf("U: ");
    for (int i=0; i<cnt; i++)printf("%d ",finu[i]);
    printf("\n");
    cnt=0;
    for (int i = 0, k=0; i < n; i++)
    {
        int found = 0, num;
        for (int j = 0; j < m; j++)
        {
            if (ara[i] == ara2[j])
            {
                found = 1;
                break;
            }
        }
        if (!found){
            D[k++] = ara[i];
            cnt++;
        }
            
    }
    if (cnt==0)printf("Empty set\n");
    else {
        printf("D: ");
        for (int i = 0; i < cnt; i++)
            printf("%d ", D[i]);
    }
    printf("\n");
    return 0;
}