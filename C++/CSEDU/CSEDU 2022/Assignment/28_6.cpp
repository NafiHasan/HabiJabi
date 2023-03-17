#include<stdio.h>

int main(){
    int x;
    scanf("%d", &x);
    int a2=x%100;
    if (x/100==1)printf("One ");
    else if (x/100==2)printf("Two ");
    else if (x/100==3)printf("Three ");
    else if (x/100==4)printf("Four ");
    else if (x/100==5)printf("Five ");
    else if (x/100==6)printf("Six ");
    else if (x/100==7)printf("Seven ");
    else if (x/100==8)printf("Eight ");
    else if (x/100==9)printf("Nine ");
    if (x/100>0)printf("hundred ");
    if (a2/10==2)printf("twenty ");
    else if (a2/10==3)printf("thirty ");
    else if (a2/10==4)printf("forty ");
    else if (a2/10==5)printf("fifty ");
    else if (a2/10==6)printf("sixty ");
    else if (a2/10==7)printf("seventy ");
    else if (a2/10==8)printf("eighty ");
    else if (a2/10==9)printf("ninety ");
    if (a2/10 ==1 && a2 %10==1)printf("eleven\n");
    else if (a2/10==1 && a2%10==2)printf("twelve\n");
    else if (a2/10==1 && a2%10==3)printf("thirteen\n");
    else if (a2/10==1 && a2%10==4)printf("fourteen\n");
    else if (a2/10==1 && a2%10==5)printf("fifteen\n");
    else if (a2/10==1 && a2%10==6)printf("sixteen\n");
    else if (a2/10==1 && a2%10==7)printf("seventeen\n");
    else if (a2/10==1 && a2%10==8)printf("eighteen\n");
    else if (a2/10==1 && a2%10==9)printf("nineteen\n");
    else if (a2/10==1 && a2%10==0)printf("ten\n");
    else if (a2%10==1)printf("one\n");
    else if (a2%10==2)printf("two\n");
    else if (a2%10==3)printf("three\n");
    else if (a2%10==4)printf("four\n");
    else if (a2%10==5)printf("five\n");
    else if (a2%10==6)printf("six\n");
    else if (a2%10==7)printf("seven\n");
    else if (a2%10==8)printf("eight\n");
    else if (a2%10==9)printf("nine\n");
    return 0;
}