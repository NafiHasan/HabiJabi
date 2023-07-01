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
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++)cin >> b[i];
		int cnt1 = 0, cnt2 = 0, dif = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1)cnt1++;
			if (b[i] == 1)cnt2++;
			if (a[i] != b[i])dif++;
		}
		int ans = min(abs(cnt1 - cnt2) + 1, dif);
		cout << ans << '\n';
	}
	return 0;
}