#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        int n;
        string s;
        cin >>n>>s;
        int mat[10]={6,2,5,5,4,5,6,3,7,6};
        int sum=0;
        for (int i=0; i<n; i++){
            int x=s[i]-'0';
            sum+=mat[x];
        }
        int av[]={2,3,4,5,6,7};
        int dp[n+1][6];
        dp[0][0]=0;
        memset(dp,0,sizeof(dp));
        for(int i=2, k=0; i<=n; i++){
            for (int j=0; j<6; j++){
                if (i>=av[j] && dp[i-av[j]]+dp[i]){
                    dp[][]
                }
            }
        }
    }   
    return 0;
}