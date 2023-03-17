#include <stdio.h>


int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)scanf("%d", &a[i]);
    int m;
    scanf("%d",&m);
    int cnt=0;
    for(int i=0; i<m; i++){
        char c;
        int j;
        getchar();
        scanf("%c",&c);
        if(c=='I'){
            scanf("%d",&j);
            cnt+=j;
        }
        else if (c=='D'){
            scanf ("%d", &j);
            cnt-=j;
        }
        else if(c=='P'){
            for(int k=0; k<n; k++){
                if(k) printf(" ");
                printf("%d",a[k]+cnt);
            }
            printf("\n");
        }
    }
    return 0;
}