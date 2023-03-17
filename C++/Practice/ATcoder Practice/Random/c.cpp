#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;
    cin >>n;
    int ara[n][3];
    int dp[n][3];
    memset ( dp, 0, sizeof(dp));
    for (int i=0; i<n; i++)cin >> ara[i][0]>>  ara[i][1] >> ara[i][2];
    dp[0][0]=ara[0][0];
    dp[0][1]=ara[0][1];
    dp[0][2]=ara[0][2];
    for (int i=1; i<n; i++){
        dp[i][0]=ara[i][0]+ max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=ara[i][1] + max ( dp[i-1][0] , dp[i-1][2] );
        dp[i][2]=ara[i][2] + max (dp [i-1][0], dp[i-1][1]);
    }
    cout <<max({dp[n-1][0],  dp[n-1][1],  dp[n-1][2]})<<en;    
    return 0;
}