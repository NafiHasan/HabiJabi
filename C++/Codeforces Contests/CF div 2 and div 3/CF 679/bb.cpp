#include <bits/stdc++.h>
using namespace std;

#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    w(t)
    {
        int r, c;
        cin >> r >> c;
        int row[r][c];
        int col[c][r];
        map<int,int>m;
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                cin >>row[i][j];
                int x=row[i][j];
                m[x]=j;
            }
        }
        int ara[r][c];
        for (int i=0; i<c; i++){
            for (int j=0; j<r; j++){
                cin >>col[i][j];
                int cc=m[col[i][j]];
                //cout <<"de "<<col[i][j]<<" col= "<<m[col[i][j]]<<"row="<<i<<en;
                ara[j][cc]=col[i][j];
            }
        }
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++)cout <<ara[i][j]<<" ";
            cout <<en;
        }
    }
    return 0;
}