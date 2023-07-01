#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long


// const ll mod=1e9+7;
const ll mod = 998244353;
map<pair<ll, ll> , pair<ll, ll>> mp;
const int N = 200005;
vector<int> edge[N];
vector<bool> vis(N, 0);

vector<ll>fact(N), invfact(N);

ll bigmod(ll a, ll n) {
	a %= mod;
	ll ans = 1;
	while (n) {
		if (n & 1) ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans % mod;
}
void factmodp() {
	fact[0] = 1LL;
	for (ll i = 1; i < N; i++)fact[i] = (fact[i - 1] * i) % mod;
}

void invfactmodp() {
	invfact[0] = 1LL;
	for (ll i = 1; i < N; i++)invfact[i] = bigmod(fact[i], mod - 2);
}



ll lcm(ll a, ll b) {
	return a * b / (__gcd(a, b));
}



void dfs(int u, pair<ll, ll> now) {
	vis[u] = 1;

	for (int i : edge[u]) {
		if (!vis[i]) {
			ll f = now.first * mp[ {u, i}].first;
			ll s = now.second * mp[ {u, i}].second;
			dfs(i, {f, s});
			// if (i == 1) cout << "f " << f << ' ' << s << '\n';
			mp[ {1, i}] = {f / __gcd(f, s), s / __gcd(f, s)};
		}
		// if (i == 4 )cout << u << '\n';
		if (i != 1 && mp[ {1, i}].first == 0) {
			// mp[ {1, i}].first = mp[ {1, u}].first * mp[ {u, i}].first;
			// mp[ {1, i}].second = mp[ {1, u}].second * mp[ {u, i}].second;
			mp[ {1, i}] = now;
			// cout << 1 << ' ' << i << ' ' << now.first << ' ' << now.second << '\n';
		}
	}
}



int main() {
	fast_io();
	// factmodp();
	// invfactmodp();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n;
		cin >> n;
		for (int i = 0; i <= n ; i++) {
			edge[i].clear();
			vis[i] = 0;
		}
		// lc.clear();
		mp.clear();
		for (int i = 0; i < n - 1; i++) {
			ll u, v , x, y;
			cin >> u >> v >> x >> y;
			mp[ {u, v}] = {x, y};
			mp[ {v, u}] = {y, x};
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		dfs(1, {1, 1});
		ll lc = 1LL;
		for (int i = 2; i <= n; i++) {
			// if (mp[ {1, i}].first == 0) {
			// 	// cout << "nafi1 " << 1 << ' ' << i << '\n';;
			// 	break;
			// }
			lc = lcm(lc, mp[ {1, i}].first);
			// lc %= mod;
		}
		vector<ll> ans(n + 5, 0);
		ans[1] = lc;
		for (int i = 2; i <= n; i++) {
			// if (mp[ {1, i}].first == 0) {
			// 	// cout << "nafi2 ";
			// 	break;
			// }
			// ans[i] = (lc % mod) * (mp[ {1, i}].second % mod) * invfact[mp[ {1, i}].first];
			ans[i] = lc * mp[ {1, i}].second  / mp[ {1, i}].first;
			ans[i] %= mod;
		}
		ll cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += ans[i];
			// cout << ans[i] << '\n';
			cnt %= mod;
		}
		cout << cnt << '\n';
	}
	return 0;
}