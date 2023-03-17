#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool comp (pair<pair<int, int>, int>a, pair<pair<int, int>, int>b) {
	if (a.first.first == b.first.first)return a.first.second > b.first.second;
	return a.first.first < b.first.first;
}


int main() {
	fast_io();
	int n;
	cin >> n;
	vector<pair<pair<int, int>, int>> vp(n);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		vp[i] = {{v, i}, u};
	}
	sort(vp.begin(), vp.end(), comp);
	for (int i = n - 1; i >= 0; i--) {
		cout << vp[i].second << ' ' << vp[i].first.first << '\n';
	}
	return 0;
}