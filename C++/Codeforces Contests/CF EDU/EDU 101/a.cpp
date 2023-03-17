#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"
int dp[105][105];
int n;
string s;
int canComplete(int i, int leftCount){
    if (leftCount<0)
        return 0;
    
    if(i==n){
        if (leftCount==0)
            return dp[i][leftCount]=1;
        else
            return dp[i][leftCount] = 0;
    }
    if (dp[i][leftCount] != -1)
        return dp[i][leftCount];
    if(s[i]=='(')
        dp[i][leftCount] = canComplete(i + 1, leftCount+1);
    else if (s[i] == ')')
        dp[i][leftCount] = canComplete(i + 1, leftCount - 1);
    else if(s[i]=='?'){
        int res1 = canComplete(i + 1, leftCount - 1);
        int res2 = canComplete(i + 1, leftCount + 1);
        int res=0;
        if(res1==1 || res2==1)
            res=1;
        dp[i][leftCount] = res;
    }
    return dp[i][leftCount];
}
    int main()
    {
        // ios::sync_with_stdio(false);
        // cin.tie(NULL);
        w(t){
        cin >>s;
        n= s.size();
        for(int i=0;i<105;i++)
            for(int j=0;j<105;j++)
                dp[i][j]=-1;
        int ans = canComplete(0,0);
        if(ans==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}