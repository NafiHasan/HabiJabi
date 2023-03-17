#include <bits/stdc++.h>
using namespace std;

#define FastIO                       \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
#define ll long long
#define M 200005


ll t[4 * M], lazy[4 * M];

void clear(int n) {
	for (int i = 0; i <= 4 * n; i++) {
		t[i] = 0;
		lazy[i] = 0;
	}
}

void build(ll a[], int v, int tl, int tr) {
	// lazy[v] = -1; //for assignment
	if (tl == tr) {
		t[v] = a[tl];
		return;
	}
	int tm = (tl + tr) / 2;
	build(a, v * 2, tl, tm);
	build(a, v * 2 + 1, tm + 1, tr);
	t[v] = t[v * 2] + t[v * 2 + 1];
}

void push(int v, int tl, int tr) {
	// if(lazy[v] == -1) return; //for assignment
	t[v] += lazy[v];
	if (tl != tr) {
		lazy[v * 2] = lazy[v];
		lazy[v * 2 + 1] = lazy[v];
	}
	lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, ll addend) {
	push(v, tl, tr);
	if (l > tr or r < tl)
		return;
	if (l <= tl and tr <= r) {
		lazy[v] += addend;
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) / 2;
	update(v * 2, tl, tm, l, r, addend);
	update(v * 2 + 1, tm + 1, tr, l, r, addend);
	t[v] = t[v * 2] + t[v * 2 + 1];
}
ll query(int v, int tl, int tr, int l, int r) {
	push(v, tl, tr);
	if (l > tr or r < tl)
		return 0;
	if (l <= tl and tr <= r)
		return t[v];
	int tm = (tl + tr) / 2;
	ll Lchild = query(v * 2, tl, tm, l, r);
	ll Rchild = query(v * 2 + 1, tm + 1, tr, l, r);
	return Lchild + Rchild;
}

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, q;
		cin >> n >> q;
		clear(n);
		update(1, 0, n - 1, 0, n - 1, 1);
		// cout << query(1, 0, n- 1, 0, n -1, 0) << '\n';
		vector<pair<ll, pair<ll, ll>>> vp(q);
		for (int i = 0; i < q; i++) {
			cin >> vp[i].second.first >> vp[i].second.second >> vp[i].first;
		}
		sort(vp.begin(), vp.end());
		for (int i = 0; i < q; i++) {
			ll x = vp[i].second.first;
			ll y = vp[i].second.second;
			ll now = query(1, 0, n - 1, x - 1, y - 1);
			if (now < 1 || x == y || x == y - 1)continue;
			// cout << i << ' ' << now << '\n';
			update(1, 0, n - 1, x - 1, y - 1, 0);
			// cout << query(1, 0 , n- 1, x- 1, y - 1, 0) << '\n';
			update(1, 0, n - 1, x - 1, x - 1, 1);
			update(1, 0, n - 1, y - 1, y - 1, 1);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (query(1, 0, n - 1, i, i) == 0)
				continue;
			else
				ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}