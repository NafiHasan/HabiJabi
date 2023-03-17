#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"
int n,s;
const int MAXS = 1000;
int v[MAXS];
int dp[MAXS];

int rec(int state){
    //base cases
    for (int i=0; i<n; i++){
        if (v[i]==state)return 1;
    }

    //check if dp is computed before
    if (dp[state]!=-1)return dp[state];
    dp[state]=100000;

    for (int i=0; i<n; i++){
        if (v[i]<=state){
            cout <<"before "<< v[i] << " " << dp[state] << endl;
            dp[state] = min(dp[state], 1 + rec(state - v[i]));
            cout << v[i] << " " << dp[state] << endl;
        }
    }
    return dp[state];
}
int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    cin >>n>>s;
    for (int i=0; i<n; i++)cin >>v[i];
    for (int i=0; i<=s; i++)dp[i]=-1;
    cout <<rec(s)<<endl;
    return 0;
}