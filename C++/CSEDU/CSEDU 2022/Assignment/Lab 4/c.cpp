#include<stdio.h>
#include<string.h>
int main (){
    int n;
    scanf("%d",&n);
    int a[100010];
    int cur=n;
    memset(a,0,sizeof(a));
    for (int i=0; i<n; i++){
        while(1){
            int x;
            scanf("%d",&x);
            if (x==0)break;
            a[x]=i+1;
        }
    }
    int c;
    scanf("%d",&c);
    while(c--){
        int p;
        scanf("%d",&p);
        if (p==1){
            int k;
            scanf("%d",&k);
            int found=-1;
            if (a[k]) found=a[k];
            if (found){
                int first=0;
                for (int i=0; i<100005; i++){
                    if (a[i]==found){
                        if (!first) printf("{");
                        else printf(", ");
                        printf("%d", i);
                        first++;
                    }
                }
                if (first) printf("}\n");
            }
        }
        else if (p==2){
            int k1,k2;
            scanf("%d %d",&k1,&k2);
            int fk1=-1,fk2=-1;
            if (a[k1])fk1=a[k1];
            if (a[k2])fk2=a[k2];
            if (fk1==-1 || fk2==-1)continue;
            if (fk1 && fk2 && fk1!=fk2){
                int first=0;
                for (int i=0; i<100005; i++){
                    if (a[i]==fk1 || a[i]==fk2){
                        a[i]=fk1;
                        if (!first) printf("{");
                        else printf(", ");
                        printf("%d",i);
                        first++;
                    }
                }
                if (first) printf("}\n");
            }
        }
        else {
            int k1, k2;
            scanf("%d %d", &k1, &k2);
            int fk1 = -1, fk2 = -1;
            if (a[k1]) fk1 = a[k1];
            if (a[k2]) fk2 = a[k2];
            if (fk1==-1)continue;
            if (fk1>0 && fk1!=fk2){
                if (fk2<=0){
                    a[k1]=++cur;
                    printf("{%d}\n",k1);
                }
                else {
                    int first=0;
                    a[k1]=fk2;
                    for (int i=0; i<100005; i++){
                        if (a[i]==fk2){
                            if (first==0)printf("{");
                            else printf(", ");
                            printf("%d", i);
                            first++;
                        }
                    }
                    if (first) printf("}\n");
                }
                int first=0;
                printf("{");
                for (int i=0; i<100005; i++){
                    if (a[i]==fk1){
                        if (first)printf(", ");
                        printf("%d", i);
                        first++;
                    }
                }
                printf("}\n");
            }
        }
    }
    return 0;
}