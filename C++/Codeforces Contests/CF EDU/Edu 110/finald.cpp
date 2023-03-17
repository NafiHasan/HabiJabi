#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

struct info {
	int sum;
	char prop;
} tree[270000 * 2];

void init(int tar, int node) {
	if (node > tar)return;
	if (tar == node) {
		if (tree[node].sum == -1) tree[node].sum = 2;
		return;
	}
	int left = 2 * node, right = left + 1;
	init(tar , left);
	init(tar, right);
	if (tree[left].sum == 0)tree[left].sum = 1;
	if (tree[right].sum == 0) tree[right].sum = 1;

	if (tree[node].prop == '?')tree[node].sum = tree[left].sum + tree[right].sum ;
	else if (tree[node].prop == '0')tree[node].sum = tree[left].sum;
	else tree[node].sum = tree[right].sum;
}


void update(int tar, int node, long long val) {
	if (node < 1) return;
	if (node == tar) {
		if (tree[node * 2].sum == 0)tree[node * 2].sum = 1;
		if (tree[node * 2 + 1].sum == 0) tree[node * 2 + 1].sum = 1;

		if (val == 2) {
			tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
			tree[node].prop = '?';
		} else if (val == 1) {
			tree[node].sum = tree[2 * node + 1].sum;
			tree[node].prop = '1';
		} else {
			tree[node].sum = tree[2 * node].sum;
			tree[node].prop = '0';
		}
	}

	int up = node / 2, left , right;
	if (node % 2) {
		left = node - 1;
		right = node;
	} else {
		right = node + 1;
		left = node;
	}
	if (tree[up].prop == '?')tree[up].sum = tree[left].sum + tree[right].sum ;
	else if (tree[up].prop == '0')tree[up].sum = tree[left].sum;
	else tree[up].sum = tree[right].sum;
	update(tar, up, val);
}



int main() {
	fast_io();
	int n;
	cin >> n;
	int level = n;
	vector<int>ind((1 << n));
	int st = 1;
	while (level) {
		for (int i = (1 << (level - 1)); i < (1 << level); i++) {
			ind[st++] = i;
		}
		level--;
	}
	n = (1 << n) ;
	string s;
	cin >> s;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == '1' || s[i] == '0')tree[ind[i + 1]].sum = 1;
		else tree[ind[i + 1]].sum = -1;
		tree[ind[i + 1]].prop = s[i];
	}
	init(n - 1, 1);
	int q;
	cin >> q;
	while (q--) {
		int pos;
		char c ;
		cin >> pos >> c ;
		if (c == '?')update(ind[pos], ind[pos], 2);
		else {
			if (c == '0')update(ind[pos], ind[pos], 0);
			else update(ind[pos], ind[pos], 1);
		}
		cout << tree[1].sum  << en;
	}
	return 0;
}
