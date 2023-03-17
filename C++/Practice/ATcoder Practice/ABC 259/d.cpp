#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long 

const int N = 3005;
vector<int> edge[N];
vector<bool> vis(N, 0);

void dfs(int u){
	vis[u] = 1;

	for (int i : edge[u]){
		if(!vis[i]){
			dfs(i);
		}
	}
}



bool chk(ll x1, ll y1, ll r1, ll x2, ll y2, ll r2){
	ll dia = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	if(dia < (r1 - r2) * (r1 - r2)) return 0;
	if(dia <= (r1 + r2) * (r1 + r2))return 1;
	if(dia == (r1 - r2) * (r1 - r2))return 1;
	return 0;
}


int main() {
	FastIO;
 	ll n, sx, sy, tx, ty;
 	cin >> n >> sx >> sy >> tx >> ty;
 	vector<pair<pair<ll,ll>, ll>> vp(n);
 	for (int i=0; i<n; i++)cin >> vp[i].first.first >> vp[i].first.second >> vp[i].second;
 	int source, dest;
 	for (int i=0; i<n ;i++){
 		ll x = vp[i].first.first, y = vp[i].first.second, r = vp[i].second;
 		if((x - sx) * (x - sx) + (y - sy) * (y - sy) == r * r)source = i;
 		if((x - tx) * (x - tx) + (y - ty) * (y - ty) == r * r)dest = i;
 		for(int j=i + 1; j<n; j++){
 			if(chk(vp[i].first.first, vp[i].first.second, vp[i].second, vp[j].first.first , vp[j].first.second , vp[j].second)){
 				edge[i].push_back(j);
 				edge[j].push_back(i);
 			}
 		}
 	}
 	dfs(source);
 	if(vis[dest])cout << "Yes\n";
 	else cout << "No\n";
    return 0;
}