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
	while (tc--) {
		// cout << (1 << 30) << en;
		int n;
		cin >> n;
		if ((n & (n - 1)) == 0 && n != 1)cout << "YES\n";
		else if (n % 2 == 0) {
			int tmp = n / 2;
			int p = sqrt(tmp);
			if (p * p == tmp)cout << "YES\n";
			else if (n % 4 == 0) {
				int tmp = n / 4;
				int p = sqrt(tmp);
				// cout << p << en;
				if (p * p == tmp)cout << "YES\n";
				else cout << "NO\n";
			} else cout << "NO\n";
		} else cout << "NO\n";
	}
	return 0;
}