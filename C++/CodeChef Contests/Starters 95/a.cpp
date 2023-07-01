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

		vector<int> a(4, 0); // a, b, ab, o
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			if (s == "A") {
				a[0]++;
			} else if (s == "B") {
				a[1]++;
			} else if (s == "AB") {
				a[2]++;
			} else {
				a[3]++;
			}
		}
		int ans = 0;
		ans = max(a[0] + a[2] + a[3] , a[1] + a[2] + a[3]);
		cout << ans << '\n';
	}
	return 0;
}