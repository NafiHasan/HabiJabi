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
		vector<int> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		bool ans = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] - a[i - 1] == 1)cnt1++;
			else if (a[i] - a[i - 1] == 2)cnt2++;
			else if (a[i] - a[i - 1] == 3)cnt3++;
			else ans = 0;
		}
		if (ans && cnt3 == 1 && cnt2 == 0) {
			cout << "yes\n";
		} else if (ans && cnt3 == 0 && cnt2 <= 2)cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}