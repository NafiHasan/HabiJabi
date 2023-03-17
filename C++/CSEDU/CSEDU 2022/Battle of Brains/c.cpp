#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin>>t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

int dp[10000][10001];

int fn (string s){
    string choto = s;
    reverse(s.begin(), s.end());
    string boro = s;
    int b = stoi(boro), c = stoi(choto);
    return b-c;
}
int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    
    memset(dp,-1,sizeof(dp));
    for (int i=0; i<=10000; i++){
        string s = to_string(i);
        while (s.size() < 4)
            s += '0';
        sort(s.begin(), s.end());
        int cap=stoi(s);
        if (dp[cap][1]==-1){
            for (int j = 0; j <= 10000; j++)
            {
                if (dp[cap][j] == -1 && j > 0)
                {
                    dp[cap][j] = fn(to_string(dp[cap][j - 1]));
                }
                else if (j == 0)
                    dp[cap][j] = fn(s);
            }
        }
    }
    w(t){
        int n,k,ans;
        cin>>n>>k;
        string s=to_string(n);
        while(s.size()<4)s+='0';
        sort (s.begin(),s.end());
        ans=stoi(s);
        if (k>0)cout <<dp[ans][k-1]<<en;
        else cout <<n<<en;
    }   
    return 0;
}