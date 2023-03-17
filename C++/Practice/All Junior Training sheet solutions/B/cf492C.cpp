#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	long long n, r, avg;
	cin >> n >> r >> avg;
	long long need = avg * n;
	long long got = 0;
	vector<pair<long long, long long>> vp(n);
	for (int i = 0; i < n; i++)	{
		cin >> vp[i].second >> vp[i].first;
		got += vp[i].second;
	}
	long long ans = 0;
	sort(vp.begin(), vp.end());
	for (int i = 0; i < n && got < need; i++) {
		long long gr = min(r - vp[i].second, need - got);
		got += gr;
		ans += gr * vp[i].first;
	}
	cout << ans << '\n';
	return 0;
}