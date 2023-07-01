#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
//Don't forget to clear the global variables
// make sure to set the maximum size according to the problem

const int N = 1e5 + 10;

vector<int> par(N), len(N, 0), rnk(N, 0), blk(N, 0) ;

void makeset() {
	for (int i = 1; i < N; i++)par[i] = i;
}

pair<int, int> get(int a) {
	// path compressed, change if needed
	if (par[a] == a) {
		return {a, 0};
	} else {
		pair<int, int> x = get(par[a]);
		par[a] = x.first;
		len[a] = (len[a] + x.second) % 2;
		return {par[a], len[a]};
	}
}

void union_set(int a, int b) {
	pair<int, int> pa = get(a); // find the topmost parent
	pair<int, int> pb = get(b);

	if (pa == pb && len[a] == len[b]) {
		blk[pa.first] = 1;
		blk[pb.first] = 1;
		return;
	} // are in same set

	if (rnk[pa.first] == rnk[pb.first])rnk[pa.first]++;

	if (rnk[pa.first] > rnk[pb.first]) {
		par[pb.first] = pa.first;
		len[pb.first] = (1 + pa.second + pb.second) % 2;
		rnk[pa.first]++;
	} else {
		par[pa.first] = pb.first;
		len[pa.first] = (1 + pa.second + pb.second) % 2;
		rnk[pb.first]++;
	}

}

int32_t main() {
	FastIO;
	int n, m;
	cin >> n >> m ;
	vector<int> a(n + 1);
	makeset();
	for (int i = 1; i <= n; i++)cin >> a[i];
	while (m--) {
		int typ;
		cin >> typ;
		if (typ == 1) {
			int x, v;
			cin >> x >> v;
			a[x] = v;
		} else if (typ == 2) {
			int x, y;
			cin >> x >> y;

			union_set(x, y);

		} else {
			int x, y, v;
			cin >> x >> y >> v;
			pair<int, int> px = get(x);
			pair<int, int> py = get(y);
			if (px.first != py.first || blk[px.first] == 1 || blk[py.first] == 1) {
				cout << "0\n";
			}  else {
				if (px.second != py.second)cout << "-";
				int g = __gcd(a[x] * v, a[y]);
				cout << a[x] * v / g << "/" << a[y] / g << '\n';
			}
		}
	}
	return 0;
}