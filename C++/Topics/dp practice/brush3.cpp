#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

int unit[1000][2];
int dp[1000];
bool used[1000];
int n,w,k;

int fnc(int x){
    if (x==k+1) return 0;
    if (dp[x] !=-1)return dp[x];

    for (int i=0; i<n; i++){
        int cnt = 0;
        for (int j=0; j<n; j++){
            if (used[i] == 0 && (ll)abs((ll)unit[i][1] - (ll)w))
            {
                used[i]=1;
                cnt++;
            }
        }
        dp[i]=max(cnt,fnc(i+1));
    }
    return dp[x];
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int c;
    w(t){
        cin>> n>>w>>k;
        memset(dp,-1,sizeof dp);
        for (int i=0; i<n; i++){
            cin >>unit[i][0]>>unit[i][1];
        }
        int ans=fnc(1);
        int best=*max_element(dp,dp+k);
        cout <<best<<en;
    }   
    return 0;
}