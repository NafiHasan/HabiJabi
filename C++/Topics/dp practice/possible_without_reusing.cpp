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
    
    int coins[]={2,3,5,10};
    int x;
    cin >>x;
    bool dp[x+1];
    bool used[4];
    memset(used,0,sizeof used);
    memset(dp,0,sizeof dp);
    dp[0]=1;
    for (int i=1; i<=x; i++){
        memset(used, 0, sizeof used);
        for (int j=0; j<4; j++){
            if (i>=coins[j] && used[j]==0){
                dp[i] |= dp[i-coins[j]];
                used[j]=1;
            }
        }
    }
    cout <<dp[x]<<en;
    return 0;
}