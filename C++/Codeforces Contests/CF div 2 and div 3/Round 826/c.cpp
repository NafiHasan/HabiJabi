#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc; cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int ans = n;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			long long tmp = 0;
			bool pos = 1, came = 0;
			int last = i, len = 0;
			for (int j = i + 1; j < n; j++) {
				tmp += a[j];
				if (tmp == sum) {
					tmp = 0;
					len = max(len, j - last);
					last = j;
					came = 1;
				} else if (tmp > sum) {
					pos = 0;
					break;
				}
			}
			if (pos && came && tmp == 0) {
				ans = min(ans, max(len, i + 1));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}