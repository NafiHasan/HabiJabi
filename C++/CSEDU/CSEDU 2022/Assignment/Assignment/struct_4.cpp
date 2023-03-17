#include <stdio.h>

bool cmp(char a[], char b[]){
    int sa,sb;
    for(int i=0; a[i]!='\0'; i++)sa=i;
    for(int i=0; b[i]!='\0'; i++)sb=i;
    if(sa!=sb)return false;
    for(int i=0; i<sa; i++)if (a[i]!=b[i])return false;
    return true;
}

typedef struct {
    int id,year;
    char title[30], genre[30], author[30];
}books;

int main (){
    int n;
    scanf("%d", &n);
    books a[n];
    for(int i=0; i<n; i++) scanf("%d %s %s %s %d",&a[i].id, a[i].title, a[i].genre, a[i].author,&a[i].year);
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i].id> a[j].id){
                books tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int q;
        scanf("%d",&q);
        if(q==1){
            char g[30];
            scanf("%s",g);
            for(int i=0; i<n; i++){
                if(cmp(g,a[i].genre))printf("%d %s %s %s %d\n",a[i].id, a[i].title, a[i].genre, a[i].author,a[i].year);
            }
        }
        else {
            int z;
            scanf("%d",&z);
            for (int i = 0; i < n; i++){
                if (z==a[i].year)
                    printf("%d %s %s %s %d\n", a[i].id, a[i].title, a[i].genre, a[i].author, a[i].year);
            }
        }
    }
    return 0;
    if(q==1){
            char g[30];
            scanf("%s",g);
            for(int i=0; i<n; i++){
                if(cmp(g,a[i].genre))printf("%d %s %s %s %d\n",a[i].id, a[i].title, a[i].genre, a[i].author,a[i].year);
            }
        }
}


if (i){
    int i = 0;
    int a = 0;
    cout << a & b << en;
    
}
if (i==0){
    int i = 0;
    for (int i = 0; i < n; i++){
        if(a==b && b==c){
            c = b;
        }
    }
}


if(q==1){
            char g[30];
            scanf("%s",g);
            for(int i=0; i<n; i++){
                if(cmp(g,a[i].genre))printf("%d %s %s %s %d\n",a[i].id, a[i].title, a[i].genre, a[i].author,a[i].year);
            }
        }