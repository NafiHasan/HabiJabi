#include<bits/stdc++.h>
using namespace std;

// #define int long long

int cnt;
vector<vector<int>>g(1e6+1);
int vis[1000001],mod=1e9+7,pw[1000001];
string s;
void precalculation()
{
    int i;
    pw[0]=1;
    for(i=1;i<=1000000;i++)
    {
        pw[i]=(pw[i-1]*31)%mod;
    }
}
void fun(int u,int t1,int t2,int l)
{
    t1=(s[u-1]-'A'+1+(t1*31))%mod;
    t2=(((s[u-1]-'A'+1)*pw[l])%mod+t2)%mod;
    vis[u]=1;
    if(t1==t2) cnt++;
    for(auto v:g[u])
    {
        if(!vis[v]) fun(v,t1,t2,l+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,i,j,u,v,n,tc=1;
    precalculation();
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        cnt=0;
        for(i=1;i<=n;i++)
            g[i].clear();
        for(i=1;i<n;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        memset(vis,0,sizeof(vis));
        fun(1,0,0,0);
        cout<<"Case "<<tc++<<": "<<cnt/__gcd(cnt,n)<<"/"<<n/__gcd(n,cnt)<<"\n";
    }
    return 0;
}

