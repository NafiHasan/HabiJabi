#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

const ll mod=1e9+7;

ll binpow(ll a, ll n){
	a %= mod;
	ll ans=1;
	while(n){
		if(n&1) ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans%mod;
}

const int N = 500005;
vector<int> edge[N];
vector<bool> vis(N, 0);
vector<ll> a(N);

ll ans = 0;

void dfs(int u, ll cur, vector<int> path){
	vis[u] = 1;
	path.push_back(u);
	bool has = 0;
	ll sz = edge[u].size();
	if(u != 1)sz--;
	for (int i : edge[u]){
		if(!vis[i]){
			has = 1;
			dfs(i, cur * sz, path);
		}
	}
	if(!has){
		ll x = 0;
		for (int i=0; i<path.size(); i++){
			x ^= a[path[i] - 1];
		}
		ll mx = 0;
		for (int i=0; i<path.size(); i++){
			mx = max(mx, x ^ a[path[i] - 1]);
		}
		// cout << mx << ' ' << cur << "c ";
		ans = (ans + mx * binpow(cur, mod - 2) % mod) % mod;
	}
}

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		for (int i=0; i<=n; i++){
			vis[i] = 0;
			edge[i].clear();
		}
		for (int i=0; i<n; i++)cin >> a[i];
		for (int i=0; i<n-1; i++){
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		vector<int> path;
		ans = 0;
		dfs(1, 1LL, path);
		cout << ans << '\n';
	} 		
    return 0;
}