#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		int one = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x == 1)one  = 1;
		}
		if (one == 0)cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}