#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

const ll mx=1e4;
const ll inf=1e18;

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int tc=1;
    while(1){
        int n;
        cin >>n;
        if(n==0)return 0;
        vector<ll>ed[mx];
        vector <ll> nodes;
        map<ll,ll>cnod,no;
        for(ll i=0,j=1; i<n; i++){
            ll u,v;
            cin >>u >>v;
            if(no[u]==0) no[u]=j++;
            if (no[v]==0) no[v]=j++;
            if(cnod[no[u]]==0){
                nodes.push_back(no[u]);
                cnod[no[u]]++;
            }
            if (cnod[no[v]] == 0){
                nodes.push_back(no[v]);
                cnod[no[v]]++;
            }
            ed[no[u]].push_back(no[v]);
            ed[no[v]].push_back(no[u]);
        }
        while(1){
            ll source, ttl;
            cin >> source>> ttl;
            if (source==0 && ttl ==0)break;
            ll dist[mx];
            for (int i = 0; i < mx; i++) dist[i] = inf;
            queue<ll>q;
            q.push(no[source]);
            dist[no[source]]=0;
            while(q.size()){
                ll u=q.front(); q.pop();
                for(int i=0; i<ed[u].size(); i++){
                    ll v=ed[u][i];
                    if(dist[v]==inf){
                        dist[v]=dist[u]+1;
                        q.push(v);
                    }
                }
            }
            ll cnt=0;
            for(int i=0 ; i<nodes.size(); i++){
                if (nodes[i] != no[source] && dist[nodes[i]] > ttl) cnt++;
            }
            cout << "Case "<<tc++<<": "<< cnt<< " nodes not reachable from node "<<source<<" with TTL = "<<ttl<<"."<<en;
        }
    }       
    return 0;
}