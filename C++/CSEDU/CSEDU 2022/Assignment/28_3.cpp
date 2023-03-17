#include<stdio.h>
#include<math.h>

int main (){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    if (b*b-4*a*c<0)printf("Imaginary\n");
    else {
        double x1=(-b+ sqrt(b*b-4*a*c))/(2*a);
        double x2=(-b- sqrt(b*b-4*a*c))/(2*a);
        printf("%.4lf %.4lf\n",x1,x2);
    }
    return 0;
}