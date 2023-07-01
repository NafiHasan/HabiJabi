#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n;
	cin >> n;
	vector<long long>a(n), ne;
	for (int i = 0; i < n; i++) cin >> a[i];
	long long ans = 0, prev = 0, now = 0, com = -1, cum = 0;
	while (1) {
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				now += a[i];
				// if (i < n - 1 && a[i] < a[i + 1])prev = 0;
				continue;
			}
			prev = min(now, a[i]);
			if (abs(a[i - 1] - a[i]) > 0)ne.push_back(abs(a[i - 1] - a[i]));
			// ans += com ;
			ans += prev;
			com++;
			ans += com;
			// cum+=com;
			now -= a[i];
			cout << now << ' ' << prev << '\n';
			if (now < 0) {
				com = -1;
				now = 0;
			}
			// cout << now << ' ' << prev <<  '\n';
		}
		if (ne.size() <= 1)break;
	}
	// cout << com << '\n';
	cout << ans << '\n';
	return 0;
}