#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n ; i++)cin >> a[i];
		sort(a.begin(), a.end());
		long long ans = 0;

		for (int i = 1; i < n - 1; i++) {
			ans = max(ans, )
		}
		cout << ans << '\n';
	}
	return 0;
}