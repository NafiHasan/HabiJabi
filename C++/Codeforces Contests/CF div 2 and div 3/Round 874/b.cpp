#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i].first;
			b[i].second = i;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		// for (int i = 0; i < n; i++)cout << a[i].first << ' ' << a[i].second << '\n';
		// for (int i = 0; i < n; i++)cout << b[i].first << ' ' << b[i].second << '\n';
		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			ans[a[i].second] = b[i].first ;
		}
		for (int i = 0; i < n; i++)cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}