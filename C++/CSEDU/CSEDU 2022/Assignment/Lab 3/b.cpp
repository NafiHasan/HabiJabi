#include <stdio.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n][m];
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            scanf("%d",&a[i][j]);
        }
    }
    int cnt[100010];
    for (int i=0; i<100010; i++)cnt[i]=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (j)printf(" ");
            if (cnt[a[i][j]] ==0){
                printf("%d",a[i][j]);
            }
            else printf("-1");
            cnt[a[i][j]]++;
        }
        printf("\n");
    }
    return 0;
}