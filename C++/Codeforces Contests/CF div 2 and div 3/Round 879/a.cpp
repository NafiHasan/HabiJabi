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
		int cnt = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] < 0)cnt++;
			sum += a[i];
		}
		int ans = 0;
		while (sum < 0 || (cnt % 2 == 1)) {
			if (cnt == 0)break;
			for (int i = 0; i < n; i++) {
				if (a[i] < 0) {
					a[i] = 1;
					cnt--;
					sum += 2;
					ans++;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}