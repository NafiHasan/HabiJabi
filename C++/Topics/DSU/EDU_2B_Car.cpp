#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


struct DSU {
	vector<int> par;
	DSU(int n) : par(n) {
		iota(par.begin(), par.end(), 0);
	}
};

const int N = 3e5 + 10;

vector<int> par(N);

void makeset() {
	for (int i = 0; i < N; i++)par[i] = i;
}

int get(int a) {
	// path compressed, change if needed
	return (par[a] == a ? a : (par[a] = get(par[a])));
}

void union_set(int a, int b) {
	a = get(a);  // find the topmost parent
	b = get(b);

	if (a == b)return; // are in same set
	par[a] = b;
}

int main() {
	FastIO;
	int n; cin >> n;

	vector<int> a(n), ans(n, -1);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	makeset();
	for (int i = 0; i < n; i++) {
		ans[i] = get(a[i]);
		if (ans[i] < n)union_set(ans[i], ans[i] + 1);
		else union_set(ans[i], 1);
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << "\n";
	return 0;
}