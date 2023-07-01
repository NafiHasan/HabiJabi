#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 0; i < n; i++)cin >> a[i];
		if (count(a.begin(), a.end(), 1) != 1) {
			cout << "no\n";
			continue;
		}
		a[n] = a[0];
		bool ans = 1;
		for (int i = 1; i < a.size(); i++) {
			if (a[i] - a[i - 1] > 1)ans = 0;
		}
		if (ans)cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}