#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

int cost[19][19];
int dp[19][(1<<19)];
int n;

int solve(int x, int mask){
    if (x==n) return 0;
    if (dp[x][mask] !=-1) return dp[x][mask];

    int ans=0;
    //if (n==1) return cost[0][0];
    for (int i=0; i<n; i++){
        if (((1<<i) & mask) ==0){
            ans=max(ans,(cost[x][i]+solve(x+1, (mask| ((1<<i))))));
        }
    }
    dp[x][mask] = ans;
    return ans;
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int c=1;
    w(t){
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> cost[i][j];
        }
        memset(dp, -1, sizeof (dp));
        int ans = solve(0, 0);
        cout <<"Case "<<c++<<": "<< ans << en;
    }
    return 0;
}