#include <stdio.h>

int chk (char pos, char name[], int points[]){
    int ans=0;
    for (int i=0; i<7; i++){
        if (pos==name[i])ans=points[i];
    }
    return ans;
}

int max(int a, int b){
    if (a<b)return b;
    else return a;
}
int main()
{
    char c[20][20];
    for (int i=0; i<20; i++)for (int j=0; j<20; j++)c[i][j]='.';
    int mx=0, my=0;
    for (int i=3; i<11; i++){
        char tmp[9];
        scanf("%s",tmp);
        for (int j=3,k=0; k<8,j<11; k++,j++)c[i][j]=tmp[k];
    }
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (c[i][j]=='2' || c[i][j]=='0')mx=i,my=j;
        }
    }
    // for (int i=0; i<20; i++){
    //     for (int j=0; j<20; j++)printf("%c",c[i][j]);
    //     printf("\n");
    // }
    // printf("%d %d\n",mx,my);
    char name[]={'.','P','B', 'K', 'R', 'Q', 'A'};
    int points[]={0,1,3, 5, 3, 8, 10};
    int cnt=0;
    cnt =max(cnt,chk(c[mx-2][my+1],name, points));
    cnt =max(cnt,chk(c[mx-2][my-1],name, points));
    cnt =max(cnt,chk(c[mx-1][my+2],name, points));
    cnt =max(cnt,chk(c[mx+1][my+2],name, points));
    cnt =max(cnt,chk(c[mx+1][my-2],name, points));
    cnt =max(cnt,chk(c[mx-1][my-2],name, points));
    cnt =max(cnt,chk(c[mx+2][my-1],name, points));
    cnt =max(cnt,chk(c[mx+2][my+1],name, points));
    printf("%d\n",cnt);
    return 0;
}