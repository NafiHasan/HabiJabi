#include <stdio.h>
int main()
{
    char c[20][20];
    for (int i=0; i<20; i++)for (int j=0; j<20; j++)c[i][j]='.';
    int mx=0, my=0;
    for (int i=3; i<11; i++){
        scanf("%s", c[i]);
    }
    for (int i = 2; i < 11; i++)
    {
        for (int j = 2; j < 11; j++)
        {
            if (c[i][j]=='2')mx=i,my=j;
        }
    }
    char name[]={'.','P','B', 'K', 'R', 'Q', 'A'};
    int points[]={0,1,3, 5, 3, 8, 10};
    char pos[20][20][20];
    for (int i=0; i<20; i++){
        for (int j=0; j<20; j++){
            for(int k=0; k<20; k++)pos[i][j][k]='.';
        }
    }
    //printf("%d %d\n",mx,my);
    int i=0, cnt=0;
    if (mx>=2){
        if (my<7) pos[i++][mx - 2][my + 1] = c[mx - 2][my + 1];
        if (my>0) pos[i++][mx - 2][my - 1] = c[mx - 2][my - 1];
    }
    if (mx<6){
        pos[i++][mx + 2][my - 1] = c[mx + 2][my - 1];
        pos[i++][mx + 2][my + 1] = c[mx + 2][my + 1];
    }
    if (my>1){
        if (mx<7)pos[i++][mx + 1][my - 2] = c[mx + 1][my - 2];
        if (mx>0)pos[i++][mx - 1][my - 2] = c[mx - 1][my - 2];
    }
    if (my<5){
        if (mx<7)pos[i++][mx + 1][my + 2] = c[mx + 1][my + 2];
        if (mx>0)pos[i++][mx - 1][my + 2] = c[mx - 1][my + 2];
    }
    for (int j=0; j<8; j++){
        for (int k=0; k<8; k++){
            for (int l=0; l<8; l++){
                for (int m=0; m<7; m++){
                    if (pos[j][k][l]==name[m] && points[m]>cnt)cnt=points[m];
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}