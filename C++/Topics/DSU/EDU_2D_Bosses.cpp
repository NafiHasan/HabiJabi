#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

//DSU to calculate depth of a node

const int N = 3e5 + 10;
vector<int> par(N), siz(N, 0);

void makeset(int n) {
	for (int i = 1; i <= n; i++)par[i] = i;
}

int get(int a) {
	if (par[a] == a) return a;
	else {
		int root = get(par[a]);
		siz[a] += siz[par[a]];
		return par[a] = root;
	}
}

void union_set (int a , int b) {
	par[a] = b;
	siz[a]++;
}

int main() {
	FastIO;
	int n, q;
	cin >> n >> q;
	makeset(n);
	while (q--) {
		int t, a, b;
		cin >> t;
		if (t == 1) {
			cin >> a >> b;
			union_set(a, b);
		} else {
			cin >> a;
			get(a);
			cout << siz[a] << '\n';
		}
	}
	return 0;
}