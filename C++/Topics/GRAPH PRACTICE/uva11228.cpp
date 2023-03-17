#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//Don't forget to clear the global variables
// make sure to set the maximum size according to the problem

const int N = 3e4 + 10;

vector<pair<int, int>> nodes(N);
vector<int> par(N), rnk(N, 0), siz(N, 1);

void makeset() {
	for (int i = 1; i < N; i++)par[i] = i;
}

int get(int a) {
	// path compressed, change if needed
	return (par[a] == a ? a : (par[a] = get(par[a])));
}

void union_set(int a, int b) {
	a = get(a);  // find the topmost parent
	b = get(b);

	if (a == b)return; // are in same set

	if (rnk[a] == rnk[b])rnk[a]++;

	if (rnk[a] > rnk[b])par[b] = a;
	else par[a] = b;
}

void clr() {
	makeset();
	par.clear();
	rnk.clear();
	siz.clear();
}

bool isSameSet(int a, int b) {
	return (get(a) == get(b));
}

int main() {
	FastIO;
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		int n, r ;
		cin >> n >> r;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			nodes[i] = {x, y};
		}
		vector<pair<double, pair<int, int>>> EdgeList;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				double x1 = nodes[i].first - nodes[j].first;
				double y1 = nodes[i].second - nodes[j].second;
				double dist = sqrt(abs(x1 * x1 + y1 * y1));
				EdgeList.push_back({dist, {i, j}});
			}
		}
		sort(EdgeList.begin(), EdgeList.end());
		for (int i = 0; i < n; i++) {
			vector <
		}
	}
	return 0;
}