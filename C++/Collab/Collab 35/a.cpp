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
		int xo = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			xo ^= x;
		}
		if (n % 2 == 0 || xo == 0)cout << "First\n";
		else cout << "Second\n";
	}
	return 0;
}