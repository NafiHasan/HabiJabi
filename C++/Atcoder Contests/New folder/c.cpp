#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

int dp[10][(1<<10)];
int cnt=0;
int cost[10][10];
int fnc (int x, int mask, int& k, int& n){
    int total=0;
    if (x==n)return 0;
    if (dp[x][mask]!=-1)return dp[x][mask];
    else {
        for (int i=1; i<n; i++){
            for (int j=1; j<n; j++){
                if (((1<<j) & mask)==0){
                    total=cost[i][j]+fnc(j+1, ((~(1<<j))&mask), k, n);
                }
            }
        }
    }
}
int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n,k;
    cin >>n>>k;
    memset(dp,-1,sizeof (dp)); 
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)cin >>cost[i][j];
    }  
    int ans=fnc()
    return 0;
}