#include<stdio.h>
#include<math.h>

int main (){
    int x,y,k;
    scanf("%d %d %d",&x,&y,&k);
    if (abs(x-y)%k!=0){
        printf("ERROR\n");
        return 0;
    }
    while(1){
        if (x==y){
            printf("Reached!\n");
            return 0;
        }
        else if (x<y){
            printf("%d, ",x*x);
            x+=k;
        }
        else {
            printf("%d, ",x*x);
            x-=k;
        }
    }
    return 0;
}