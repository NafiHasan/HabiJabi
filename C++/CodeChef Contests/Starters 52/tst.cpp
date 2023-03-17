#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, x;
		cin >> n >> x;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (((i ^ n ) & x) == 0) {
				cnt++;
				cout << i << ' ';
			}
		}

		cout << '\n' << cnt << '\n';
	}
	return 0;
}