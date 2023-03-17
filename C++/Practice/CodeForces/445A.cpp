#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

char a[105][105];
int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++)cin >> a[i][j];
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (a[i][j]=='.'){
                if ((i+j)%2==0)
                    a[i][j] = 'B';
                else  a[i][j]='W';
            }
        }
    }
    for (int i=1; i<=n; i++){
        for (int j = 1; j <= m; j++)
            cout << a[i][j];
        cout << en;
    }
    return 0;
}