#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

//Don't forget to clear the global variables

vector<long long>b(200005, 0), tree(200005 * 3, 0);

void init (int node , int lo, int hi) {
	if (lo == hi) {
		tree[node] = b[lo];
		return;
	}
	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2 ;

	init (left, lo, mid);
	init (right, mid + 1, hi);
	tree[node] = __gcd(tree[left] , tree[right]);
}

long long query(int node, int lo, int hi, int i, int j) {
	if (i > hi || j < lo) return 0;
	if (lo >= i && hi <= j) return tree[node];

	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2;
	long long ans1 = query (left, lo, mid, i, j);
	long long ans2 = query (right, mid + 1, hi, i, j);
	return __gcd(ans1, ans2);
}

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		b.clear(), tree.clear();
		int n;
		cin >> n;
		if (n == 1) {
			long long x;
			cin >> x;
			cout << "1\n";
			continue;
		}
		vector<long long>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i)b[i - 1] = abs(a[i] - a[i - 1]);
		}
		init(1, 0, n - 2);
		int ans = 1, l = 0, r = 0;
		while (r < n - 1) {
			long long temp = query(1, 0, n - 2, l, r);
			while (l < r && temp == 1) {
				l++;
				temp = query(1, 0, n - 2, l, r);
			}
			if (temp > 1) ans = max(ans, r - l + 2);
			r++;
		}
		cout << ans << "\n";
	}
	return 0;
}