#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

int dp1[1005][1005], dp2[1005][1005], dp3[1005][1005], dp4[1005][1005], mat[1005][1005];

int main ()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> mat[i][j];
    
    for(int i=1; i<=n ; i++)
        for (int j = 1; j <= m; j++)
            dp1[i][j] = mat[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
    
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= m; j++)
            dp2[i][j] = mat[i][j] + max(dp2[i + 1][j], dp2[i][j - 1]);
    
    for(int i=1; i<=n; i++) 
        for(int j=m; j>=1; j--) 
            dp3[i][j] = mat[i][j] + max(dp3[i-1][j] , dp3[i][j+1]);

    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
            dp4[i][j] = mat[i][j] + max(dp4[i + 1][j], dp4[i][j + 1]);
    
    int ans=0;
    for(int i=2; i<n; i++){
        for(int j=2; j<m; j++){
            ans = max(ans, dp1[i-1][j] + dp4[i+1][j] + dp2[i][j-1] + dp3[i][j+1]);
            ans = max(ans, dp1[i][j-1] + dp4[i][j+1] + dp2[i+1][j] + dp3[i-1][j]);
        }
    }
    cout << ans <<"\n";
    return 0;
}