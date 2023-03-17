#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int N = 1000005;

long long a[N], tree[N * 4];

void clear(int n) {
	for (int i = 0; i <= n; i++) a[i] = 0;
	for (int i = 0; i <= 4 * n; i++) tree[i] = 0;
}

void init (int node , int lo, int hi) {
	if (lo == hi) {
		tree[node] = a[lo];
		return;
	}
	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2 ;
	init (left, lo, mid);
	init (right, mid + 1, hi);
	tree[node] = tree[left] + tree[right];
}

long long query(int node, int lo, int hi, int i, int j) {
	if (i > hi || j < lo) return 0;
	if (lo >= i && hi <= j) return tree[node];

	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2;
	return query (left, lo, mid, i, j) + query (right, mid + 1, hi, i, j);
}

void update(int node, int lo, int hi, int i, long long new_value) {
	if (i < lo || i > hi) return;
	if (lo == hi) {
		tree[node] = new_value;
		return;
	}
	int left = node * 2, right = left + 1;
	int mid = (lo + hi) / 2;
	update(left, lo, mid, i, new_value);
	update(right, mid + 1, hi, i, new_value);
	tree[node] = tree[left] + tree[right];
}




int main() {
	FastIO;
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case #" << cs << ": ";
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		init(1, 0, n - 1);
		int q, ans = 0;
		cin >> q;
		while (q--) {
			int t, l, r;
			cin >> t >> l >> r;
			if ((r - l) % 2 == 1)continue;
			if (r == l) {
				ans++;
				continue;
			}
			bool ok = 1;

			if (ok) {
				ans++;
				// cout << l << ' ' << r << '\n';
			}
		}
		cout << ans << '\n';
	}
	return 0;
}