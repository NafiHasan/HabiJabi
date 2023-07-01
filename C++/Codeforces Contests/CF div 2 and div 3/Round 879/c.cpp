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
		string a, b;
		cin >> a >> b;
		int rev = 0, cnt = 0, best = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i])cnt++;
		}
		best = cnt;
		cnt = 0;
		reverse(b.begin(), b.end());
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i])cnt++;
		}
		if (best > cnt) {
			rev = 1;
			best = cnt;
		} else if (best == cnt && best % 2 == 0 && best > 0) {
			rev = 1;
			best = cnt;
		}
		if (best == 0) {
			if (rev == 1)cout << "2\n";
			else cout << "0\n";
		} else if (best % 2 == 0) {
			if (rev == 0)cout << best * 2 << '\n';
			else cout << best * 2 - 1 << '\n';
		} else {
			if (rev) cout << best * 2 << '\n';
			else cout << best * 2 - 1 << '\n';
		}
	}
	return 0;
}