#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
long long mod = 998244353;
// for (a^n) % p
long long bigmod (long long a, long long n) {
	a %= mod;
	long long ans = 1;
	while (n) {
		if (n & 1) ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}

// //Don't forget to clear the global variables or just init

// long long a[100005];

// struct info {
// 	long long prop, sum;
// } tree[100005 * 3];

// void init(int node, int lo, int hi){
// 	if(lo == hi) {
// 		tree[node].sum = a[lo];
// 		return;
// 	}
// 	int left = 2 * node, right = left + 1;
// 	int mid = (lo + hi) / 2;
// 	init(left, lo, mid);
// 	init(right, mid + 1, hi);
// 	tree[node].sum = tree[left].sum + tree[right].sum;
// }

// long long query(int node, int lo, int hi, int i, int j, long long carry = 0LL){
// 	if(i > hi || j < lo) return 0;
// 	if(i <= lo && j >= hi)return tree[node].sum + carry * (hi - lo + 1) * 1LL;

// 	int left = 2 * node, right = left + 1;
// 	int mid = (lo + hi) / 2;
// 	long long ans1 = query(left, lo, mid, i , j , carry + tree[node].prop);
// 	long long ans2 = query(right, mid + 1, hi, i , j , carry + tree[node].prop);

// 	return ans1 + ans2 ;
// }

// void update(int node, int lo, int hi, int i, int j, long long val){
// 	if(i > hi || j < lo) return;
// 	if(i <= lo && j >= hi) {
// 		tree[node].sum += 1LL * (hi - lo + 1) * val;
// 		tree[node].prop += val;
// 		return ;
// 	}

// 	int left = 2 * node, right = left + 1;
// 	int mid = (lo + hi) / 2;
// 	update(left, lo, mid, i, j, val);
// 	update(right, mid + 1, hi, i, j, val);
// 	tree[node].sum = tree[left].sum + tree[right].sum + (hi - lo + 1) * tree[node].prop * 1LL;
// }


int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, m, k, q;
		cin >> n >> m >> k >> q;
		set<ll> ro, col;
		ll cnt = 0;
		vector<pair<ll, ll>> vp;
		map<pair<ll, ll>, ll>mp;
		for (ll i = 1; i <= n; i++)ro.insert(i);
		for (ll i = 1; i <= m; i++)col.insert(i);
		vector<ll> cntr(n + 1, 0), cntl(n + 1, 0);
		for (int i = 0; i < q; i++) {
			ll x, y;
			cin >> x >> y;
			// cin >> vp[i].first >> vp[i].second;

			mp[ {x, y}]++;
			if (mp[ {x, y}] == 1) {
				// mp[ {vp[i].first, vp[i].second}] = LLONG_MIN;
				vp.push_back({x, y});
			}
			// else {
			// 	cntr[vp[i].first]++;
			// 	cntl[vp[i].second]++;
			// }
			// ro.insert(vp[i].first);
			// col.insert(vp[i].second);
		}
		for (int i = vp.size() - 1, j = 1; i >= 0; j++, i--) {
			cntr[vp[i].first]++;
			cntl[vp[i].second]++;
			if (ro.find(vp[i].first) != ro.end() || col.find(vp[i].second) != col.end()) {
				if (cntr[vp[i].first] <= m && cntl[vp[i].second] <= n) {
					ro.erase(vp[i].first);
					col.erase(vp[i].second);
					cnt = j;
				}
			}
			// else if (col.find(vp[i].second) != col.end()) {
			// 	ro.erase(vp[i].first);
			// 	col.erase(vp[i].second);
			// 	cnt = j;
			// }
			// col.erase(vp[i].second);
			// if (ro.empty() && col.empty())break;`
		}
		cout << bigmod(k, cnt) << '\n';
	}
	return 0;
}