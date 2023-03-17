#include<stdio.h>
int main (){
    int n;
    scanf("%d",&n);
    char a[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (j==n/2 || i==n/2)a[i][j]='$';
            else a[i][j] = '_';
        }
    }
    for (int i=0,j=n-1; i<n/2,j>n/2; j--,i++){
        a[i][n/2-i]='$';
        a[i][n/2+i]='$';
        a[j][n/2-i]='$';
        a[j][n/2+i]='$';
    }
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++)printf("%c",a[i][j]);
        puts("");
    }
    return 0;
}