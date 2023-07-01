#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define MAX 10000003

// const ll mod=1e9+7;
const ll mod = 998244353;

map<pair<int, int> , pair<int, int>> mp;
const int N = 200005;
vector<int> edge[N];
vector<bool> vis(N, 0);

int prime[MAX];
// unordered_map<int,int> max_map;

int bigmod(int a, int n) {
	a %= mod;
	int ans = 1;
	while (n) {
		if (n & 1) ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans % mod;
}



// ll lcm(ll a, ll b) {
// 	return a * b / (__gcd(a, b));
// }



void dfs(int u, pair<int, int> now) {
	vis[u] = 1;

	for (int i : edge[u]) {
		if (!vis[i]) {
			int f = now.first * mp[ {u, i}].first;
			int s = now.second * mp[ {u, i}].second;
			dfs(i, {f, s});
			if (f == 0 || s == 0) {
				cout << "z";
				break;
			}
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




// Function to find the smallest prime factors
// of numbers upto MAX
void sieve() {
	prime[0] = prime[1] = 1LL;
	for (ll i = 2; i < MAX; i++) {
		if (prime[i] == 0) {
			for (ll j = i * 2LL; j < MAX; j += i) {
				if (prime[j] == 0) {
					prime[j] = i;
				}
			}
			prime[i] = i;
		}
	}
}

// Function to return the LCM modulo M
// ll lcmModuloM(vector<ll> ar) {

// 	for (int i = 0; i < ar.size(); i++) {
// 		ll num = ar[i];
// 		unordered_map<ll, ll> temp;

// 		// Temp stores mapping of prime factor to
// 		// its power for the current element
// 		while (num > 1) {

// 			// Factor is the smallest prime factor of num
// 			ll factor = prime[num];

// 			// Increase count of factor in temp
// 			temp[factor]++;
// 			if (factor == 0) {
// 				cout << "nafi";
// 				break;
// 			}
// 			// Reduce num by its prime factor
// 			num /= factor;
// 		}

// 		for (auto it : temp) {

// 			// Store the highest power of every prime
// 			// found till now in a new map max_map
// 			max_map[it.first] = max(max_map[it.first], it.second);
// 		}
// 	}

// 	ll ans = 1;

// 	for (auto it : max_map) {

// 		// LCM is product of primes to their highest powers modulo M
// 		ans = (ans * bigmod(it.first, it.second)) % mod;
// 	}

// 	return ans;
// }


int main() {
	fast_io();
	// sieve();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 0; i <= n ; i++) {
			edge[i].clear();
			vis[i] = 0;
		}
		// lc.clear();
		// max_map.clear();
		mp.clear();
		for (int i = 0; i < n - 1; i++) {
			int u, v , x, y;
			cin >> u >> v >> x >> y;
			mp[ {u, v}] = {x, y};
			mp[ {v, u}] = {y, x};
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		// dfs(1, {1, 1});
		ll lc = 1;
		// vector<ll> lv;
		// for (ll i = 2; i <= n; i++) {
		// 	if (mp[ {1, i}].first == 0) {
		// 		// cout << "nafi1 " << 1 << ' ' << i << '\n';;
		// 		break;
		// 	}
		// 	lv.push_back(mp[ {1, i}].first);
		// 	// lc = lcm(lc, mp[ {1, i}].first);
		// 	// lc = lcm(lc, mp[ {1, i}].first);
		// 	// if(lc < 0)cout << "nafi";
		// 	// lc %= mod;
		// }
		// lc = lcmModuloM(lv);
		vector<ll> ans(n + 5, 0);
		ans[1] = lc;
		for (int i = 2; i <= n; i++) {
			if (mp[ {1, i}].first == 0) {
				cout << "nafi2 ";
				break;
			}
			// ans[i] = (lc % mod) * (mp[ {1, i}].second % mod) * invfact[mp[ {1, i}].first];
			if (mp[ {1, i}].first == 0) {
				cout << "nafi2";
				break;
			}
			// ans[i] = lc * mp[ {1, i}].second  / mp[ {1, i}].first;
			ans[i] %= mod;
		}
		ll cnt = 0;
		for (int i = 1; i <= n; i++) {
			// cnt += ans[i];
			// cout << ans[i] << '\n';
			cnt %= mod;
		}
		cout << cnt << '\n';
	}
	return 0;
}