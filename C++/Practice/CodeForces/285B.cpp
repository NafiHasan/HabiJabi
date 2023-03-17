#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

int bfs(int source, int dest, int ed[], int n){
    queue<int>q;
    q.push(source);
    int vis[n];
    memset(vis,0,sizeof(vis));
    int cnt=0;
    while(q.size()){
        int u=q.front(); q.pop();
        int v=ed[u];
        cnt++;
        if (v==dest) return cnt;
        if (vis[v]==0){
            vis[v]=1;
            q.push(v);
        }
    }
    if (vis[dest]==0) return -1;
    return cnt;
}

int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n, s, t;
    cin >> n >> s >> t;
    s--, t--;
    int ed[n];
    for (int i=0; i<n ; i++){
        cin >> ed[i];
        ed[i]--;
    }
    if (s!=t  && ed[s] == s){
        cout << "-1\n";
        return 0;
    }
    if (s==t){
        cout << "0\n";
        return 0;
    }
    int ans= bfs(s,t,ed,n);
    cout << ans << en;
    return 0;
}