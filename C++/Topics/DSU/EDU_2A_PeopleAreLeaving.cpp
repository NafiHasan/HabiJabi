#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

//Don't forget to clear the global variables
// make sure to set the maximum size according to the problem

const int N = 1e6 + 10;

vector<int> par(N);

void makeset(int n) {
	for (int i = 0; i <= n; i++)par[i] = i;
}

int get(int a) {
	// path compressed, change if needed
	return (par[a] == a ? a : (par[a] = get(par[a])));
}

void union_set(int a, int b) {
	a = get(a);  // find the topmost parent
	b = get(b);

	par[a] = b;
}

int main() {
	FastIO;
	int n, m;
	cin >> n >> m;
	makeset(n + 5);
	while (m--) {
		char c;
		int pos;
		cin >> c >> pos;
		if (c == '?') {
			int ans = get(pos);
			if (ans > n)ans = -1;
			cout << ans << '\n';
		} else {
			union_set(pos, pos + 1);
		}
	}
	return 0;
}