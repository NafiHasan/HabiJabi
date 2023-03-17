#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

//Don't forget to clear the global variables
//lo -- hi = range of the index
// i -- j = range of query
#define ll long long

const int N = 200005;

long long a[N];
struct info {
	long long prop, sum;
} tree[N * 4];

void clear(int n) {
	for (int i = 0; i <= n; i++)a[i] = 0;
	for (int i = 0; i <= 4 * n; i++) {
		tree[i].sum = 0;
		tree[i].prop = 0;
	}
}

void init(int node, int lo, int hi) {
	if (lo == hi) {
		tree[node].sum = a[lo];
		return;
	}
	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	init(left, lo, mid);
	init(right, mid + 1, hi);
	tree[node].sum = tree[left].sum + tree[right].sum;
}

long long query(int node, int lo, int hi, int i, int j, long long carry = 0LL) {
	if (i > hi || j < lo) return 0;
	if (i <= lo && j >= hi)return tree[node].sum + carry * (hi - lo + 1) * 1LL;

	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;

	return query(left, lo, mid, i , j , carry + tree[node].prop) + query(right, mid + 1, hi, i , j , carry + tree[node].prop);
}

void update(int node, int lo, int hi, int i, int j, long long val) {
	if (i > hi || j < lo) return;
	if (i <= lo && j >= hi) {
		tree[node].sum += 1LL * (hi - lo + 1) * val;
		tree[node].prop += val;
		return;
	}

	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	update(left, lo, mid, i, j, val);
	update(right, mid + 1, hi, i, j, val);
	tree[node].sum = tree[left].sum + tree[right].sum + (hi - lo + 1) * tree[node].prop * 1LL;
}


int main() {
	FastIO;
	ll n, k;
	cin >> n >> k;
	for (int i = k; i <= n; i += k) {
		a[i - 1]++;
	}
	init(1, 0, n - 1);
	ll now = k;
	for (int i = k + 1; i <= n; i++) {
		now += i;
		update(1, 0, n - 1, now - 1, now - 1, 1);
		update(1, 0, n - 1, now + k - 1, n - 1, 1);
		cout << now << ' ' << now + k  - 1 << ' ' << n << '\n';
	}
	for (int i = 0; i < n; i++) {
		ll ans = query(1, 0, n - 1, i, i, 0);
		cout << ans << ' ' ;
	}
	cout << '\n';
	return 0;
}