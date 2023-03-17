#include<stdio.h>
int main()
{
    char a[1000];
    scanf("%[^\n]",a);
    int num=0;
    for (int i=0; a[i]!=' '; i++){
        num+=a[i]-'0';
        if (i==0)num*=10;
        //printf("%d\n",num);
    }
    if (num==21)printf("International Mother Language Day!\n");
    else printf("I don't care!\n");
    return 0;
}