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
		vector<long long> a(n), b(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++)cin >> b[i];
		long long ans = 0;
		for (int i = 1; i < n; i++) {
			// ans++;
			ans = max(ans + 1, a[i] + 1);
		}
		for (int i = n - 1; i >= 0; i--) {
			// ans++;
			// if (i == n - 1)ans = max(ans, max(a[n - 1] + 2, b[i] + 1));
			// else ans = max(ans, max(b[i + 1] + 2, b[i] + 1));
			// ans++;
			ans = max(ans + 1, b[i] + 1);
		}
		long long ans2 = 0;
		for (int i = 0; i < n; i++) {
			// ans2++;
			// if (i == 0)ans2 = max(ans2, b[i] + 1);
			// else ans2 = max(ans2, max(b[i - 1] + 2, b[i] + 1));
			ans2 = max(ans2 + 1, b[i] + 1);
			// ans2++;
		}
		for (int i = n - 1; i > 0; i--) {
			// if (i == n - 1)ans2 = max(ans2, max(b[n - 1] + 2, a[i] + 1));
			// else ans2 = max(ans2 , max(a[i + 1] + 2, a[i] + 1));
			ans2 = max(ans2 + 1, a[i] + 1);
			// ans2++;
		}
		ans = min(ans, ans2);
		cout << ans << '\n';
	}
	return 0;
}