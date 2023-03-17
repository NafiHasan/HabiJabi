#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    while(1){
        int n,l;
        cin >>n;
        if(n==0)return 0;
        cin >>l;
        int source;
        vector<int> ed[n+1];
        vector<pair<int, int>>vp;
        for(int i=0; i<l; i++){
            int u,v; 
            cin >> u>> v;
            vp.push_back(make_pair(u,v));
            if (i == 0)
                source = u;
            ed[u].push_back(v);
            ed[v].push_back(u);
        }
        int clr[n+1];
        memset(clr, 0, sizeof(clr));
        queue <int>q;
        q.push(source);
        clr[source]=1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=0; i<ed[u].size(); i++){
                int v = ed[u][i];
                if (clr[v]==0){
                    q.push(v);
                    if (clr[u] == 1)
                        clr[v] = 2;
                    else if (clr[u] == 2)
                        clr[v] = 1;
                }
            }
        }
        bool ans=true;
        for(int i=0; i<vp.size(); i++){
            if(clr[vp[i].first]==clr[vp[i].second]){
                ans=false;
                break;
            }
        }
        (ans ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n");
    }   
    return 0;
}