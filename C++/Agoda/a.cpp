#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


const int N = 3e5 + 5;
pair<int, int> tree[N * 4];

void init(int node, int lo, int hi) {
	if (lo == hi) {
		tree[node].first = 0;
		tree[node].second = 0;
		return;
	}
	int left = node * 2, right = left + 1;
	int mid = (lo + hi) / 2;
	init(left, lo , mid);
	init(right, mid + 1, hi);
}

int query(int node, int lo, int hi, int i, int j) {
	if (i > hi || j < lo)return 0;
	if (lo <= i && hi >= j)return tree[node].first;

	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	return query(left, lo, mid, i, j) + query(right, mid + 1, hi, i , j);
}

int query2(int node, int lo, int hi, int i, int j) {
	if (i > hi || j < lo)return 0;
	if (lo <= i && hi >= j)return tree[node].second;

	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;

	return query2(left, lo, mid, i, j) + query2(right, mid + 1, hi, i , j);
}
void update(int node, int lo , int hi, int i, int val) {
	if (i < lo || i > hi)return ;
	if (lo == hi) {
		tree[node].first = val;
		if (val == 0)tree[node].second = 0;
		else tree[node].second = 1;
		return ;
	}
	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	update(left, lo, mid, i, val);
	update(right, mid + 1, hi, i, val);
	tree[node].first = tree[left].first + tree[right].first;
	tree[node].second = tree[left].second + tree[right].second;
}

int main() {
	int n;
	int mx = 3e5 + 4;
	cin >> n;
	init(1, 0, mx);
	vector<int> freq(1e7 + 5, 0);
	while (n--) {
		string s;
		int val;
		cin >> s >> val;
		if (s == "B") {
			freq[val]++;
			int cnt = 0;
			if (freq[val] > 1)cnt = query(1, 0, mx, freq[val] - 1, freq[val] - 1);
			if (cnt > 0)update(1, 0, mx, freq[val] - 1, cnt - 1);
			cnt = query(1, 0, mx, freq[val], freq[val]);
			cout << freq[val] << 'f' << cnt << '\n';
			update(1, 0, mx, freq[val], cnt + 1);
		} else if (s == "C") {
			if (freq[val] == 0)continue;
			freq[val]--;
			int cnt = query(1, 0, mx, freq[val] + 1, freq[val] + 1);
			if (cnt > 0)update(1, 0, mx, freq[val] + 1, cnt - 1);
			cnt = query(1, 0, mx, freq[val], freq[val]);
			update(1, 0, mx, freq[val], cnt + 1);
		} else {
			int cnt = query(1, 0, mx, val, mx);
			int cnt2 = query2(1, 0, mx, val, mx);
			cout << cnt << ' ' << cnt2 << '\n';
		}
	}
	cout << "F";
	return 0;
}