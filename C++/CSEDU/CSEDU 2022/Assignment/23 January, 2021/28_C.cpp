#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n==0){
        printf(" *****\n");
        for (int i=1; i<=3; i++)printf(" *   *\n");
        printf(" *****\n");
    }
    else if (n==1) for (int i=0; i<5; i++) printf("     *\n");
    else if (n==2){
        for (int i=1; i<=5; i++){
            if (i%2==1) printf(" *****\n");
            else if (i==2)printf("     *\n");
            else if (i==4)printf(" *    \n");
        }
    }
    else if (n==3){
        for (int i = 1; i <= 5; i++){
            if (i % 2 == 1)printf(" *****\n");
            else printf("     *\n");
        }
    }
    else if (n==4){
        printf(" *   *\n");
        printf(" *   *\n");
        printf(" *****\n");
        printf("     *\n");
        printf("     *\n");
    }
    else if (n==5){
        for (int i = 1; i <= 5; i++){
            if (i % 2 == 1) printf(" *****\n");
            else if (i == 4) printf("     *\n");
            else if (i == 2) printf(" *    \n");
        }
    }
    else if (n==6){
        for (int i = 1; i <= 5; i++){
            if (i % 2 == 1) printf(" *****\n");
            else if (i == 4) printf(" *   *\n");
            else if (i == 2) printf(" *    \n");
        }
    }
    else if (n==7){
        printf(" *****\n");
        for (int i=0; i<4; i++) printf("     *\n");
    }
    else if (n==8){
        for (int i = 1; i <= 5; i++){
            if (i % 2 == 1) printf(" *****\n");
            else printf(" *   *\n");
        }
    }
    else {
        for (int i = 1; i <= 5; i++){
            if (i % 2 == 1) printf(" *****\n");
            else if (i == 4) printf("     *\n");
            else if (i == 2) printf(" *   *\n");
        }
    }
    return 0;
}