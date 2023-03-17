#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int ara[n];
    for ( int i=0; i<n; i++)cin >>ara[i];
    ll dp[n];
    dp[0]=0;
    dp[1]=abs(ara[1]-ara[0]);
    for (int i=2; i<n; i++)
        dp[i] =(ll) min(dp[i-1]+abs(ara[i]-ara[i - 1]),dp[i-2]+abs(ara[i]-ara[i - 2]));
    cout <<dp[n-1]<<en;
    return 0;
}