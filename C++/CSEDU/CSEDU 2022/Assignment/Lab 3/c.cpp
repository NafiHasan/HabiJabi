#include<stdio.h>

void rec(char c[], int si, int n){
    if (n==0){
        for (int i=0; i<si; i++)printf("%c",c[i]);
        return ;
    }
    for (int i=0; i<si; i++){
        if (n%2){
            if (c[i]=='0')printf("0");
            else rec(c,si,n-1);
        }
        else {
            if (c[i] == '1')
                printf("1");
            else
                rec(c, si, n - 1);
        }
    }
}


int main(){
    char a[1000];
    char fin[4];
    scanf("%s",a);
    int ara[4];
    for (int i=0; i<4 ;i++)ara[i]=-1;
    int num=0;
    int found=-1, cnt=0;
    for (int i=0,j=0; a[i]!='\0'; i++){
        printf("%c ",a[i]);
        if (a[i]==' ') found =1;
        else if (found == 1 && a[i]!=' ') {
            ara[j++] = a[i] - '0';
            printf("%c ",a[i]);
        }
        else if (found==-1) fin[i]=a[i];
        cnt=j;
    }
    for(int i=cnt,j=0; i>=0; i--){
        if (ara[i]!=-1){
            if (j) num+= (j*10)* ara[i];
            j++;
            printf("%d ",ara[i]);
        }
    }
    printf("%d",num);
    // si=2;
    // int x;
    //scanf("%d",&x);
    //rec(a,si,0);
    printf("\n");
    return 0;
}