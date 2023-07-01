#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		long long n;
		cin >> n;
		string ans = "";
		while (n > 1LL) {
			n /= 2LL;
			if (n % 2LL == 0) {
				n++;
				ans += "1";
			} else {
				ans += "2";
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
	return 0;
}