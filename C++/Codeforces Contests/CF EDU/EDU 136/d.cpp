#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


const int N = 200005;
vector<int> edge[N], h(N, -1), mx(N, 0), vec;
vector<bool> vis(N, 0);
map<pair<int,int> ,int> mp;

int cur = 0, cnt = 0,cm = 0;

void dfs2(int u){
	// vis[u] = 1;

	mx[u] = max(mx[u], h[u]);
	for (int i: edge[u]){
		if(mp[{u, i}] == 0){
			h[i] = h[u] + 1;
			dfs2(i);
			mx[u] = max(mx[i], mx[u]);
		}
	}
}
void dfs(int u, int par){
	if(cur == 2)cout <<u << '\n';
	// vis[u] = 1;
	// mx[u] = max(mx[u], h[u]);


	if(mx[u] > cur && mx[u] - cur < h[u] || (h[u] > cur)){
		cout << u << ' ' << mx[u] << ' ' << cur << 'f' << '\n' ;
		cnt++;
		mp[{par, u}]++;
		vec.push_back(u);
		// edge[1].push_back(u);
		// h[u] = 1;
		// mx[u] = 1;
		// for (int i : edge[u]){
		// 	h[i] = h[u] + 1;
		// 	mx[i] = h[i];
		// 	dfs(i, u);
		// 	mx[u] = max(mx[u], mx[i]);
		// }
	}
	else {
		for (int i : edge[u]){
		// if(mp[{u, i}] == 0){
			// h[i] = h[u] + 1;
			dfs(i, u);
			// if(mp[{u, i}] != 0){
			// 	mx[u] = h[u];
			// }
			// else mx[u] = mx[i];
		// }
	}
	}
	
}



int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, k;
 		cin >> n>> k;
 		for (int i=0; i<=n; i++){
 			edge[i].clear();
 			h[i] = 0; mx[i] = 0;
 		}
 		cur = 0, cnt = 0;
 		for (int i=1; i<n; i++){
 			int x;
 			cin >> x;
 			edge[x].push_back(i + 1);
 		}
 		int ans = n, lo = 1, hi = n, mid;
 		while(lo <= hi){
 			mid = (lo + hi)/2;
 			fill(vis.begin(), vis.begin() + n + 5, 0);
 			fill(mx.begin(), mx.begin() + n + 2, 0);
 			fill(h.begin(), h.begin() + n + 2, 0);
 			vec.clear();
 			cnt = 0; cur = mid; cm = 0;
 			mp.clear();
 			dfs2(1);
 			dfs(1, -1);
 			for (int i=0; i<vec.size(); i++)edge[1].push_back(vec[i]);

 			fill(h.begin(), h.begin() + n + 2, 0);
 			dfs2(1);
 			for (int i=vec.size() - 1; i>=0; i--)edge[1].pop_back();
 			cm = 0;
 			for (int i=1; i<=n; i++)cm = max(cm, h[i]);
 				// cout << cur << ' ' << cnt << ' '<< cm << '\n';
 			cout << cur << ' ' << cnt << ' '<< cm << '\n';
 			if(cnt > k || cm > cur){
 				lo = mid + 1;
 			}
 			else {
 				ans = min(ans, mid);
 				hi = mid - 1;
 			}
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}