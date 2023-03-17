#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    char a[n+2][m+2];
    memset(a,0,sizeof(a));
    for (int i=1; i<=n; i++)for (int j=1; j<=m; j++)cin >> a[i][j];
    int cnt=0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (a[i][j] == 'P'){
                if (a[i-1][j] == 'W'){
                    cnt++;
                    a[i-1][j] = '.';
                }else if (a[i+1][j] == 'W'){
                    cnt++;
                    a[i+1][j] = '.';
                }else if (a[i][j-1] == 'W'){
                    cnt++;
                    a[i][j-1] = '.';
                }else if (a[i][j+1] == 'W'){
                    cnt++;
                    a[i][j+1] = '.';
                }
            }
        }
    }
    cout  << cnt << en;
    return 0;
}