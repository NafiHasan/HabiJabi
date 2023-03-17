#include <stdio.h>

typedef struct {
    int id;
    char name[30];
    int sub[5];
    int total;
}student;

int main (){
    int n;
    scanf("%d",&n);
    student a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i].id);
        scanf(" %[^\n]", a[i].name);
        int marks=0;
        for(int j=0; j<5; j++){
            scanf("%d",&a[i].sub[j]);
            marks+=a[i].sub[j];
        }
        a[i].total=marks;
    }
    // sorting
    for(int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if(a[j].total > a[i].total){
                student tmp=a[j];
                a[j]=a[i];
                a[i]=tmp;
            }
            else if (a[j].total== a[i].total && a[j].id < a[i].id){
                student tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%5d%5d %-20s%5d", i + 1, a[i].id, a[i].name, a[i].total);
        for (int j=0; j<5; j++)printf("%5d",a[i].sub[j]);
        printf("\n");
    }
    return 0;
}