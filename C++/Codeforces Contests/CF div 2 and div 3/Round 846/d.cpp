#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	// FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int ans = 0;
		while (n > 0) {
			int num = 0;
			for (int i = 0; i < n; i++)num |= (1LL << i);
			cout << "- " << num << endl;
			ans += num;
			cin >> n;
		}
		if (n == -1)return 0;
		cout << "! " << ans << endl;
	}
	return 0;
}