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
		vector<int> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		string s;
		cin >> s;
		int ans = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0')ans = min(ans, a[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}