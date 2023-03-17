#include<stdio.h>
int strlen(char a[])
{
    int len = 0;
    for (int i = 0; a[i] != '\0'; i++)
        len = i;
    return len+1;
}
// minimum of 2 integers
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
//string comparison
int strcomp(char a[], char b[])
{
    int mn = min(strlen(a), strlen(b));
    for (int i = 0; i < mn; i++)
    {
        if (b[i] > a[i])
            return -1;
        else if (b[i] < a[i])return 1;
    }
    if (mn == strlen(a) && mn == strlen(b))
        return 0;
    return 1;
}
int main(){
    char a[30], b[30];
    scanf("%s %s",a,b);
    int x=strcomp(a,b);
    if (x==-1){
        printf("%d",x);
    }
    else if (x==1)printf("%d is smaller",x);
    else printf("equal");
}