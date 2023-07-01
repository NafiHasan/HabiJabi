#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			sum1 += x;
		}
		for (int i = 0; i < m ; i++) {
			int x;
			cin >> x;
			sum2 += x;
		}
		if (sum1 == sum2) {
			cout << "Draw\n";
		} else if (sum1 > sum2) {
			cout << "Tsondu\n";
		} else cout << "Tenzing\n";
	}
	return 0;
}