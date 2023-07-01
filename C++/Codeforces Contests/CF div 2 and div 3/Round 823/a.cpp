#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, c;
		cin >> n >> c;
		vector<int> cnt(105, 0), a(n);
		for (int i = 0; i < n ; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		int ans = 0;
		for (int i = 0; i < 105; i++) {
			ans += min(cnt[i] , c);
		}
		cout << ans << '\n';
	}
	return 0;
}