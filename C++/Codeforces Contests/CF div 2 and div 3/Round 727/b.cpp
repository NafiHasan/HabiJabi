#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	int a[n];
	for (int i = 0; i < n; i++) {
		a[i] = s[i] - 96;
	}
	vector<int>pre(n + 1, 0);
	pre[0] = a[0];
	for (int i = 1; i <= n; i++)pre[i] = pre[i - 1] + a[i - 1];
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << pre[r] - pre[l - 1] << en;
	}
	return 0;
}