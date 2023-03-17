#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

//Don't forget to clear the global variables or just init

// long long a[270000];

int tree[270000];

vector<int >ind;

void init(int node, int lo, int hi) {
	if (lo == hi) {
		if (tree[node] == -1)tree[node] = 2;
		return;
	}
	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	init(left, lo, mid);
	init(right, mid + 1, hi);
	if (tree[node] == -1)tree[node] = tree[left] + tree[right];
}

// long long query(int node, int lo, int hi, int i, int j, long long carry = 0LL) {
// 	if (i > hi || j < lo) return 0;
// 	if (i <= lo && j >= hi)return tree[node].sum + carry * (hi - lo + 1) * 1LL;

// 	int left = 2 * node, right = left + 1;
// 	int mid = (lo + hi) / 2;
// 	long long ans1 = query(left, lo, mid, i , j , carry + tree[node].prop);
// 	long long ans2 = query(right, mid + 1, hi, i , j , carry + tree[node].prop);

// 	return ans1 + ans2 ;
// }

void update(int tar, int node, long long val) {
	// if (i > hi || j < lo) return;
	if (node > tar) return ;
	if (node == tar) {
		if (val == 2)tree[node] = tree[node].sum;
		else if (val == 1)tree[node] = tree[2 * node + 1];
		else tree[node] = tree[2 * node];
		return ;
	}

	int left = 2 * node, right = left + 1;
	update(tar, left, val);
	update(tar, right, val);
	tree[node] = tree[left] + tree[right];
}




int main() {
	fast_io();
	int n;
	cin >> n;
	n = (1 << n) ;
	string s;
	cin >> s;
	for (int i = 0, j = n - 2; i < n - 1, j >= 0; j--, i++) {
		if (s[j] == '1')tree[i + 1] = 1;
		else if (s[j] == '0') tree[i + 1] = 0;
		else tree[i + 1] = -1;
	}
	init(1, 0, n - 1);
	int q;
	cin >> q;
	while (q--) {
		int pos;
		char c ;
		cin >> pos >> c ;
		// pos++;
		// pos = n - pos;
		// cout << pos << en << en;
		if (c == '?')update(pos, 1, 2);
		else {
			if (c == '0')update(pos, 1 , 0);
			else update(pos, 1, 1);
		}
		cout << tree[1]  << en;
	}
	return 0;
}


//Don't forget to clear the global variables or just init

long long a[100005];

struct info {
	long long prop, sum;
} tree[100005 * 3];

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
	long long ans1 = query(left, lo, mid, i , j , carry + tree[node].prop);
	long long ans2 = query(right, mid + 1, hi, i , j , carry + tree[node].prop);

	return ans1 + ans2 ;
}

void update(int node, int lo, int hi, int i, int j, long long val) {
	if (i > hi || j < lo) return;
	if (i <= lo && j >= hi) {
		tree[node].sum += 1LL * (hi - lo + 1) * val;
		tree[node].prop += val;
		return ;
	}

	int left = 2 * node, right = left + 1;
	int mid = (lo + hi) / 2;
	update(left, lo, mid, i, j, val);
	update(right, mid + 1, hi, i, j, val);
	tree[node].sum = tree[left].sum + tree[right].sum + (hi - lo + 1) * tree[node].prop * 1LL;
}