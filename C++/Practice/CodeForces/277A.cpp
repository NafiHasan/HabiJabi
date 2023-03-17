#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

void bfs(int source, vector<int>edges[], int* vis){
    queue<int>q;
    q.push(source);
    while(q.size()){
        int u=q.front(); q.pop();
        vis[u]=1;
        for (int i=0; i<edges[u].size(); i++){
            int v=edges[u][i];
            if (vis[v]==0){
                vis[v]=1;
                q.push(v);
            }
        }
    }
}

int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n,m, cnt=0, ans=0;
    cin >> n >> m;
    vector<int>edges[m];
    int vis[m];
    memset(vis,0,sizeof(vis));
    map<int,int> ex;
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        if (x==0)ans++;
        else {
            int a[x];
            for (int j = 0; j < x; j++){
                cin >> a[j];
                a[j]--;
                ex[a[j]]++;
            }
            for (int j = 0; j < x-1 ; j++)
            {
                for (int k = j+1 ; k < x; k++)
                {
                    edges[a[j]].push_back(a[k]);
                    edges[a[k]].push_back(a[j]);
                }
            }
        }
    }
    for (int i=0; i<m; i++){
        if (vis[i]==0 && ex[i]>0){
            // if (ex[i]==1) 
            cnt++;
            //cout << i << " ";
            bfs(i,edges,vis);
        }
    }
    if (cnt)cnt--;
    cout << ans+cnt << en;
    return 0;
}