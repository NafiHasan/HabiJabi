#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)



int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		string a, b;
		cin >> a >> b;
		int ans = 0;
		if (a.size() < b.size()) {
			ans = ((int)b.size() - 1) * 9 + (int)(b[0] - '0');
		} else if (a.size() == b.size()) {
			while (a.size() > 0 && a[0] == b[0]) {
				reverse(a.begin(), a.end());
				reverse(b.begin(), b.end());
				a.pop_back();
				b.pop_back();
				reverse(a.begin(), a.end());
				reverse(b.begin(), b.end());
			}
			ans = ((int)b.size() - 1) * 9 + ((int)(b[0] - '0') - (int)(a[0] - '0'));

		}
		ans = max(ans, 0);
		cout << ans << '\n';
	}
	return 0;
}