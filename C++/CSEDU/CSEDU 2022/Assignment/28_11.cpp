#include<stdio.h>

int main (){
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        double a, as, ct, m, f;
        scanf("%lf %lf %lf %lf %lf", &a, &as, &ct, &m, &f);
        m = m * 30.0 / 50.0, f = f * 40.0 / 100.0;
        double sum = a + as + ct + m + f;
        int total = (int)sum;
        if (total >= 0 && total < 55)
            printf("F\n");
        else if (total >= 55 && total < 57)
            printf("D\n");
        else if (total >= 57 && total < 61)
            printf("D+\n");
        else if (total >= 61 && total < 65)
            printf("C-\n");
        else if (total >= 65 && total < 69)
            printf("C\n");
        else if (total >= 69 && total < 73)
            printf("C+\n");
        else if (total >= 73 && total < 77)
            printf("B-\n");
        else if (total >= 77 && total < 81)
            printf("B\n");
        else if (total >= 81 && total < 85)
            printf("B+\n");
        else if (total >= 85 && total < 90)
            printf("A-\n");
        else if (total >= 90 && total <= 100)
            printf("A\n");
    }
    return 0;
}