#include <stdio.h>

char c[20][20];
int max(int a, int b){
    if (a<b)return b;
    else return a;
}

int chk (int move,char name[], int points[], int x, int y){
    char pos=c[x][y];
    if (move==1){
        int cnt=0;
        for (int i=0; i<7; i++){
            if (pos==name[i]){
                 //printf("%d\n",points[i]);
                 return points[i];

            }
        }
    }
    int ans=0;
    int cnt=0;
    for (int i=0; i<7; i++){
        if (pos==name[i]){
            ans=points[i];
            //printf("%d \n\n",ans);
            cnt =max(cnt,chk(1,name, points, x-2,y+1));
            cnt =max(cnt,chk(1,name, points, x-2,y-1));
            cnt =max(cnt,chk(1,name, points, x-1,y+2));
            cnt =max(cnt,chk(1,name, points, x+1,y+2));
            cnt =max(cnt,chk(1,name, points, x+1,y-2));
            cnt =max(cnt,chk(1,name, points, x-1,y-2));
            cnt =max(cnt,chk(1,name, points, x+2,y-1));
            cnt =max(cnt,chk(1,name, points, x+2,y+1));
            return ans+cnt;
        }
    }
    return ans+cnt;
}
int main()
{
    for (int i=0; i<20; i++)for (int j=0; j<20; j++)c[i][j]='.';
    int mx=0, my=0;
    for (int i=6; i<14; i++){
        char tmp[9];
        scanf("%s",tmp);
        for (int j=6,k=0; k<8,j<14; k++,j++)c[i][j]=tmp[k];
    }
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (c[i][j]=='0')mx=i,my=j;
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
    cnt =max(cnt,chk(0, name, points, mx-2, my+1));
    cnt =max(cnt,chk(0, name, points, mx-2, my-1));
    cnt =max(cnt,chk(0, name, points, mx-1, my+2));
    cnt =max(cnt,chk(0, name, points, mx+1, my+2));
    cnt =max(cnt,chk(0, name, points, mx+1, my-2));
    cnt =max(cnt,chk(0, name, points, mx-1, my-2));
    cnt =max(cnt,chk(0, name, points, mx+2, my-1));
    cnt =max(cnt,chk(0, name, points, mx+2, my+1));
    printf("%d\n",cnt);
    return 0;
}