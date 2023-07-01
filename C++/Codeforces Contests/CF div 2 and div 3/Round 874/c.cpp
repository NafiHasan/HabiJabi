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
		vector<int>a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		sort(a.begin(), a.end());
		bool odd = 0, even = 0, ans = 1;
		if (a[0] % 2 == 0)even = 1;
		else {
			cout << "YES\n";
			continue;
		}
		for (int i = 1; i < n; i++) {
			if (a[i] % 2 == 1)ans = 0;
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}