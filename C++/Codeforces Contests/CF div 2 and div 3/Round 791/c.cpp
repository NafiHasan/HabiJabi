#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

//Don't forget to clear the global variables

int tree[100005 * 3], tree2[100005 * 3];

int query(int node, int lo, int hi, int i, int j) {
	if (i > hi || j < lo) return 0;
	if (lo >= i && hi <= j) return tree[node];

	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2;
	return query (left, lo, mid, i, j) + query (right, mid + 1, hi, i, j);
}

int query2(int node, int lo, int hi, int i, int j) {
	if (i > hi || j < lo) return 0;
	if (lo >= i && hi <= j) return tree2[node];

	int left = node * 2 , right = left + 1;
	int mid = (lo + hi) / 2;
	int ans1 = query2 (left, lo, mid, i, j);
	int ans2 = query2 (right, mid + 1, hi, i, j);
	return ans1 + ans2;
}

void update(int node, int lo, int hi, int i, int new_value) {
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

void update2(int node, int lo, int hi, int i, int new_value) {
	if (i < lo || i > hi) return;
	if (lo == hi) {
		tree2[node] = new_value;
		return;
	}
	int left = node * 2, right = left + 1;
	int mid = (lo + hi) / 2;
	update2(left, lo, mid, i, new_value);
	update2(right, mid + 1, hi, i, new_value);
	tree2[node] = tree2[left] + tree2[right];
}

int main() {
	fast_io();
	int n, q;
	cin >> n >> q;
	vector<int> row(n, 0), col(n, 0);
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int r, c;
			cin >> r >> c;
			r--, c--;
			row[r]++;
			col[c]++;
			update(1, 0, n - 1, r, 1);
			update2(1, 0, n - 1, c, 1);
		} else if (t == 2) {
			int r, c;
			cin >> r >> c;
			r--, c--;
			row[r]--;
			col[c]--;
			if (row[r] == 0)update(1, 0, n - 1, r, 0);
			if (col[c] == 0)update2(1, 0, n - 1, c, 0);
		} else {
			int r1, c1, r2, c2;
			cin >> r1 >> c1 >> r2 >> c2;
			r1--, r2--, c1--, c2--;

			int sum1 = query(1, 0, n - 1, r1, r2);
			int sum2 = query2(1, 0, n - 1, c1, c2);
			if (sum1 == (r2 - r1 + 1) || sum2 == (c2 - c1 + 1))cout << "Yes\n";
			else cout << "No\n";
		}
	}
	return 0;
}