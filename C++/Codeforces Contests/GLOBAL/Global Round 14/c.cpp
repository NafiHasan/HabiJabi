#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, x;
		cin >> n >> m >> x;
		vector<pair<int, int>>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a.begin(), a.end());
		// for (int i = 0; i < n; i++)cout << a[i].first << " " <<  a[i].second << "\n";
		// cout << en;
		vector<int>ans(n);
		for (int i = 0; i < n; i++) {
			ans[a[i].second] = (i + 1) % m;
			if ((i + 1) % m == 0)ans[a[i].second] = m;
		}
		cout << "YES\n";
		for (int i = 0; i < n; i++)cout << ans[i] << " ";
		cout << en;
	}
	return 0;
}