#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 1; i < n; i += 2) {
		ans += a[i] - a[i - 1];
	}
	cout << ans << '\n';
	return 0;
}