#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

//Don't forget to clear the global variables
//lo -- hi = range of the index
// i -- j = range of query

const int N = 100005;

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
	tree[node] = __gcd(tree[left], tree[right]);
}

long long query(int node, int lo, int hi, int i, int j) {
	if (i > hi || j < lo) return 0;
	if (lo >= i && hi <= j) return tree[node];

	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2;
	return __gcd(query (left, lo, mid, i, j) , query (right, mid + 1, hi, i, j));
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
	tree[node] = __gcd(tree[left] , tree[right]);
}



int main() {
	fast_io();
	int n;
	cin >> n;
	vector<long long> b(n);
	long long mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
		mx = max(mx, a[i]);
	}
	sort(b.begin(), b.end());
	init(1, 0 , n - 1);
	long long ans = query(1, 0, n - 1, 0, n - 1);
	// cout << ans << '\n';
	for (int i = 0; i < n; i++) {
		int pre = a[i];
		if (i == 0)update(1, 0, n - 1, i, a[1]);
		else update(1, 0, n - 1, i , a[0]);
		ans = max(ans, query(1, 0 , n  - 1, 0 , n - 1));
		update(1, 0, n - 1, i, pre);
	}
	cout << ans << '\n';
	return 0;
}