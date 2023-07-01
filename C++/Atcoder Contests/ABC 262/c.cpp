#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	FastIO;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	int cnt = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == i + 1)cnt++;
		else if (a[i] > i + 1 && a[a[i] - 1] == i + 1)ans++;
	}
	cnt *= cnt - 1;
	cnt /= 2;
	ans += cnt;
	cout << ans << '\n';
	return 0;
}