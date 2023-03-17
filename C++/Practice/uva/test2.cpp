#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a.begin(), a.end());
	vector<long long > dp(n, 0);
	for (int i = 0; i < n; i++) {
		if (i && a[i] == a[i - 1]) {
			dp[i] = dp[i - 1] - a[i];
			continue;
		}
		long long now = 0;
		for (int j = 1; j * a[i] <= a[n - 1]; j++) {
			long long  lo = i, hi = n - 1, mid, need = a[i] * j, lp = -1, rp = -1, need2 = a[i] * (j + 1) - 1;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (a[mid] > need2)hi = mid - 1;
				else if (a[mid] >= need) {
					lp = mid;
					hi = mid - 1;
				} else lo = mid + 1;
			}
			lo = i, hi = n - 1;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (a[mid] > need2)hi = mid - 1;
				else if (a[mid] <= need2) {
					rp = mid;
					lo = mid + 1;
				} else lo = mid + 1;
			}
			if (lp != -1 && rp != -1)now += (rp - lp + 1) * a[i] * j;
			// cout << a[i] << ' ' << j  << ' ' << lp << ' ' << rp << ' ' << now  << '\n';
		}
		dp[i] = now;
	}
	cout << *max_element(dp.begin(), dp.end()) << '\n';
	return 0;
}