#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<ll> a(n), b(n + 1, 0), ans(n + 2, 0), pre(n + 2 , 0), add(n + 2, 0);
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++)cin >> b[i];
		for (int i = 1; i <= n; i++)
			pre[i] = pre[i - 1] + b[i - 1];
		for (int i = 0; i < n; i++) {
			int lo = i, hi = n, mid, ind = n + 1;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (a[i] <= (pre[mid] - pre[i])) {
					ind = mid;
					hi = mid - 1;
				} else lo = mid + 1;
			}
			ans[i + 1] += 1;
			ans[ind] -= 1;
			ll inc = 0;
			if (ind >= i) {
				inc = a[i] - (pre[ind - 1] - pre[i]);
				if (inc > 0)
					add[ind] += inc;
			}
		}
		vector<ll> res(n + 2, 0);
		for (int i = 1; i <= n; i++) {
			ans[i] += ans[i - 1];
			res[i] = ans[i] * b[i - 1];
			res[i] += add[i];
		}
		for (int i = 1; i <= n; i++)cout << res[i] << ' ';
		cout << "\n";
	}
	return 0;
}