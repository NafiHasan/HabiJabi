#include <stdio.h>
int main()
{
    char a[1000010];
    scanf("%s",a);
    int cnt=1;
    printf("%c",a[0]);
    for(int i=1, j=1; a[i] != '\0'; i++){
        if(a[i] == a[i-1])cnt++;
        else {
            printf("%d",cnt);
            printf("%c",a[i]);
            cnt=1;
        }
    } 
    printf("%d\n",cnt);
    return 0;
}