#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int m=n, cnt=0, a[12];
    while (m>0){
        a[cnt++]=m%10;
        m/=10;
    }
    if (n==0){
        cnt=1;
        a[0]=0;
    }
    for (int line=1; line<=5; line++){
        for (int num=cnt-1 ; num>=0; num--){
            if (a[num] == 0){
                if (line == 1 || line==5) printf("*****");
                if (line>1 && line<5)printf("*   *");
            }
            else if (a[num] == 1) printf("    *");
            else if (a[num] == 2){
                if (line % 2 == 1) printf("*****");
                else if (line == 2) printf("    *");
                else if (line == 4) printf("*    ");
            }
            else if (a[num] == 3){
                if (line % 2 == 1) printf("*****");
                else printf("    *");
            }
            else if (a[num] == 4)
            {
                if (line<=2) printf("*   *");
                else if (line==3) printf("*****");
                else printf("    *");
            }
            else if (a[num] == 5){
                if (line % 2 == 1) printf("*****");
                else if (line == 4) printf("    *");
                else printf("*    ");
            }
            else if (a[num] == 6){
                    if (line % 2 == 1)
                        printf("*****");
                    else if (line == 4)
                        printf("*   *");
                    else if (line == 2)
                        printf("*    ");
            }
            else if (a[num] == 7){
                if (line==1)printf("*****");
                else printf("    *");
            }
            else if (a[num] == 8){
                    if (line % 2 == 1)
                        printf("*****");
                    else
                        printf("*   *");
            }
            else{
                    if (line % 2 == 1)
                        printf("*****");
                    else if (line == 4)
                        printf("    *");
                    else if (line == 2)
                        printf("*   *");
            }
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}