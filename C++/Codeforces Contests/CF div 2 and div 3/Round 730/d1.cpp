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
		int n, k, r;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			if (i > 0)cout << (i ^ (i - 1)) << endl;
			else cout << 0 << endl;

			cin >> r;
			if (r == -1)return 0;
			else if (r == 1)break;
		}
	}
	return 0;
}