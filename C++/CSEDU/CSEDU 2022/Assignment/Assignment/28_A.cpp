#include <stdio.h>
#include <math.h>

const double pi = 3.14159265358979323846;

int main(){
    int h, A ,B;
    scanf("%d %d %d", &h, &A, &B);
    double a,b,left_base,right_base , base, ans;
    a=A*pi/180.0;      //converting into radian
    b=B*pi/180.0;      //converting into radian
    left_base=tan(a)*(double)h;
    right_base=tan(b)*(double)h;
    
    base= (double) (left_base + right_base);
    ans=(double)(.5*base*(double)h);
    printf("%.6lf\n",ans);
    return 0;
}