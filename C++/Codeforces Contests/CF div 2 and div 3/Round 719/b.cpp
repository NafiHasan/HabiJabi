#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	int a[10] = {0, 9, 18, 27, 36, 45, 54, 63, 72, 81};
	while (tc--) {
		int n;
		cin >> n;
		string s = to_string(n);
		int ss = (int)s.size();
		int ans = a[ss - 1];
		ans += s[0] - '0';
		for (int i = 1; i < ss; i++) {
			if (s[i] > s[i - 1])break;
			else if (s[i] < s[i - 1]) {
				ans--;
				break;
			}
		}
		cout << ans << en;
	}
	return 0;
}