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
		vector<int> a(n), cnt(1000, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		bool ans = 1;
		int last = cnt[0];
		for (int i = 1; i < 100; i++) {
			if (cnt[i] > last) {
				ans = 0;
				break;
			} else last = min(last, cnt[i]);
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}