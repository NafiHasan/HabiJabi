#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; 
    cin >> n;
    int a[n];
    vector<pair<string,int>>vp(n);
    for(int i=0; i<n; i++)cin >>a[i];
    for(int i=0; i<n; i++){
        string s;
        cin >>s;
        vp[i]={s,a[i]};
    }   
    int dp[n][2];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<n; i++){
        if(vp[i].first < vp[i-1].first){

        }
    }
    return 0;
}