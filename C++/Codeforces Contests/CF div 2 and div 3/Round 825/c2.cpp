#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


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
	tree[node] = min(tree[left] , tree[right]);
}

long long query(int node, int lo, int hi, int i, int j) {
	if (i > hi || j < lo) return 1e8;
	if (lo >= i && hi <= j) return tree[node];

	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2;
	return min(query (left, lo, mid, i, j) , query (right, mid + 1, hi, i, j));
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
	tree[node] = min(tree[left] , tree[right]);
}



int main() {
	FastIO;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] -= (i + 1);
	}
	init(1, 0, n - 1);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int ald = 1 - (i + 1);
		int lo = i, hi = n - 1, mid, f = i;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (query(1, 0, n - 1, i, mid) >= ald) {
				f = max(f, mid);
				lo = mid + 1;
			} else hi = mid - 1;
		}
		ans += (long long)(f - i + 1);
	}

	int q;
	cin >> q;
	while (q--) {
		int ind, val;
		cin >> ind >> val;
		ind--;
		int tmp = a[ind];
		// a[ind] = val - (ind + 1);
		update(1, 0, n - 1, ind, val - (ind + 1));
		int left = ind;
		int lo = 0, hi = ind, mid, f = ind;
		int ald = 1 - (ind + 1);
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			ald = 1 - (mid + 1);
			if (query(1, 0, n - 1, mid, ind) >= ald) {
				f = min(f, mid);
				hi = mid - 1;
			} else lo = mid + 1;
		}
		left = f;
		int right = ind;
		ald = 1 - (left + 1);
		lo = f, hi = n - 1;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (query(1, 0, n - 1, left, mid) >= ald) {
				right = max(right, mid);
				lo = mid + 1;
			} else hi = mid - 1;
		}
		long long cnt1 = (ind - left) * (right - ind + 1);

		// second


		// a[ind] = tmp;
		f = ind;
		update(1, 0, n - 1, ind, tmp);
		// cout << tmp << '\n';
		lo = 0, hi = ind;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			ald = 1 - (mid + 1);
			if (query(1, 0, n - 1, mid, ind) >= ald) {
				f = min(f, mid);
				hi = mid - 1;
			} else lo = mid + 1;
		}
		left = f;
		right = ind;
		lo = f, hi = n - 1;
		ald = 1 - (left + 1);
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (query(1, 0, n - 1, left, mid) >= ald) {
				right = max(right, mid);
				lo = mid + 1;
			} else hi = mid - 1;
		}
		// cout << left << ' '  << right << '\n';
		int add = 0;
		if (left == ind)add++;
		if (right == ind)add--;
		long long cnt2 = (long long)(ind - left) * (long long)(right - ind + 1);
		// cout << cnt1 << ' ' << cnt2 << '\n';
		cout << ans - cnt2 + cnt1 + add << '\n';
	}
	return 0;
}