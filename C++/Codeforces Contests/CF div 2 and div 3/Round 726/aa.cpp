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
		int n, odd = 0, even = 0;
		cin >> n;
		for (int i = 0; i < 2 * n; i++) {
			int x;
			cin >> x;
			if (x % 2 == 0)even++;
			else odd++;

		}
		if (even == odd)cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}