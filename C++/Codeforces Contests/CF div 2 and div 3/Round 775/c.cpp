#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

long long distsum(vector<long long> a) {
	sort(a.begin(), a.end());
	int n = a.size();
	long long res = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		res += (a[i] * i - sum);
		sum += a[i];
	}
	return res;
}

long long totaldis(vector<long long> x, vector<long long> y) {
	return distsum(x) + distsum(y);
}


int main() {
	fast_io();
	int n, m;
	cin >> n >> m;
	int sz = 100005;
	map<long long, long long> c;
	vector<long long> a[sz], b[sz];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			c[x]++;
			a[x].push_back(i + 1);
			b[x].push_back(j + 1);
		}
	}
	vector<long long> x, y;
	vector<long long> pass;
	for (int i = 1; i <= 100005; i++) {
		if (c[i] > 0)pass.push_back(i);
	}
	long long ans = 0;
	for (int i = 0; i < pass.size(); i++) {
		x = a[pass[i]];
		y = b[pass[i]];
		// int sz = x.size();
		ans += totaldis(x, y);
	}
	cout << ans << '\n';
	return 0;
}