#include<stdio.h>
#include<math.h>

int main (){
    int n;
    scanf("%d",&n);
    bool prime=true;
    int limit=sqrt(n)+1;
    if (n%2==0 && n>2)prime=false;
    for (int i=3; i<=limit; i+=2){
        if (n%i==0){
            prime=false;
            break;
        }
    }
    if (prime) printf("Prime\n");
    else printf("Composite\n");
    return 0;
}