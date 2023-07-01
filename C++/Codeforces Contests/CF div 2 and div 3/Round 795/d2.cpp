#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


//Don't forget to clear the global variables
//lo -- hi = range of the index (0 based indexing/ lo = 0, hi = n-1)
// i -- j = range of query

const int N = 200005;

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
	tree[node] = max(tree[left] , tree[right]);
}

long long query(int node, int lo, int hi, int i, int j) {
	if (i > hi || j < lo) return 0;
	if (lo >= i && hi <= j) return tree[node];

	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2;
	return max(query (left, lo, mid, i, j) , query (right, mid + 1, hi, i, j));
}

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		clear(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		init(1, 0, n - 1);
		bool ans = 1;
		long long curmax = 0, l = 0, cursum = 0;
		for (int i = 0; i < n; i++) {
			cursum += a[i];
			if (cursum <= 0 ) {
				cursum = 0;
				curmax = 0;
				l = i + 1;
			}
			if (cursum > curmax) {
				curmax = cursum;
				long long mx = query(1, 0, n - 1, l, i);
				if (mx < curmax) {
					ans = 0;
					break;
				}
			}
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}