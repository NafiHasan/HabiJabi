#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int ind = -1;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x > 1 && ind == -1) {
				ind = i;
			}
		}
		if (ind == -1) {
			(n % 2 == 0 ? cout << "Second\n" : cout << "First\n");
		} else {
			(ind % 2 == 0 ? cout << "First\n" : cout << "Second\n");
		}
	}
	return 0;
}