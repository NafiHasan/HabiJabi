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
    
    int n,x;
    cin >> n>> x;
    int coins[n];
    int dp[x+1];
    dp[0]=0;
    for (int i=0; i<n; i++){
        cin>> coins[i];
    } 
    int values[10000];  
    for (int i=1; i<=x; i++){
        dp[i]=1e9;
        for (int j=0; j<n; j++){
            if (coins[j]<=i){
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    cout <<dp[x]<<en;
    return 0;
}