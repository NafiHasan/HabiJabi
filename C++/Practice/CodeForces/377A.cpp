#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

int n,m;
char ara[505][505];

int area(char ara[][505] , int i, int j){
    int cnt=0;
    if(ara[i][j-1]=='.')cnt++;
    if(ara[i][j+1]=='.')cnt++;
    if(ara[i+1][j]=='.')cnt++;
    if(ara[i-1][j]=='.')cnt++;
    return cnt;
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int k;
    cin >>n >>m >>k;
    n++,m++;
    memset(ara,-1, sizeof(ara));
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            cin >> ara[i][j];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (k == 0)
            {
                i = n;
                break;
            }
            else if (area(ara, i, j) <= 1 && ara[i][j] == '.' && k > 0)
            {
                ara[i][j] = 'X';
                k--;
            }
        }
    }
    int cnt=0;
    for( int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if (area(ara,i,j)<=1)cnt++;
        }
    }
    //cout <<cnt<<en;
    if(cnt>k && k>0) {
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (ara[i][j] == '.' && area(ara, i, j) <= 1)
                {
                    ara[i][j] = 'X';
                    //cout <<ara[i][j]<<en;
                    k--;
                }
                if (k == 0)
                {
                    i = n;
                    break;
                }
            }
        }
    }
    else if (cnt == 0 && k > 0)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (ara[i][j] == '.')
                {
                    ara[i][j] = 'X';
                    //cout <<ara[i][j]<<en;
                    k--;
                }
                if (k == 0)
                {
                    i = n;
                    break;
                }
            }
        }
    }
    //while(k>0){
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                if (k == 0){
                    i = n;
                    break;
                }
                else if (area(ara, i, j) <= 1 && ara[i][j]=='.' &&k>0){
                    ara[i][j] = 'X';
                    k--;
                }
            }
        }
    //}
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++)cout<<ara[i][j];
        cout <<en;
    }
    return 0;
}