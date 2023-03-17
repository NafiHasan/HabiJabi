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
    
    int n,k;
    cin >>n>>k;
    int ara[n];
    for (int i=0; i<n; i++)cin>> ara[i];
    int dp[n];
    for(int i=0; i<n; i++)dp[i]=INT_MAX;
    dp[0]=0;
    dp[1]=abs(ara[0]-ara[1]);
    for (int i=2; i<n; i++){
        for (int j=1; j<=k ; j++){
            dp[i] =min(dp[i], dp[i-j]+abs(ara[i]-ara[i-j]));
        }
    }   
    cout<< dp[n-1]<<en;
    return 0;
}