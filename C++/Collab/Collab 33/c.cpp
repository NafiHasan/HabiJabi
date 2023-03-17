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
		int mx = 0, mxcnt = 0;
		map<int, int>mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
			if (mp[a[i]] > mxcnt) {
				mxcnt = mp[a[i]];
				mx = a[i];
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == mx) {
				cnt = mxcnt;
				break;
			}
		}
		if (mxcnt <= (n / 2)) {
			cout << (n + 1) / 2 << '\n';
		} else {
			int ans = (n - mxcnt + 1) / 2;
			mxcnt -= ans;
			ans += (mxcnt);
			cout << ans << '\n';
		}
	}
	return 0;
}