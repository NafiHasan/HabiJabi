#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s; cin >> s;
		vector<long long> cnt(26, 0), fact(16, 1);
		for (long long i = 2; i < 16; i++)fact[i] = fact[i - 1] * i;
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
		}
		int odd = 0;
		long long ans = 0;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] % 2)odd++;
			ans += cnt[i] / 2;
		}
		if (odd > 1) {
			cout << "0\n";
			continue;
		}
		ans = fact[ans];
		for (int i = 0; i < 26; i++) {
			ans = ans / (fact[cnt[i] / 2]);
		}
		cout << ans << '\n';
	}
	return 0;
}