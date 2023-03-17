#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		long long n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		long long cnt1 = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1')cnt1++;
		}
		long long need = cnt1 * m;
		if (need % 2LL == 1) {
			cout << "0\n";
			continue;
		}
		if (cnt1 == 0) {
			cout << n * m << '\n';
			continue;
		}
		need /= 2LL;
		long long ind = need % cnt1;
		if (ind == 0)ind = cnt1;
		long long now = 0;
		long long ans = 0;
		for (int i = 0; ; i++) {
			if (i == n)i %= n;
			if (s[i] == '1')now++;
			if (now > ind)break;
			if (now == ind) {
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}