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
		int ans = 0, sum = 0;
		int i = 1;
		while (1) {
			if (sum >= n)break;
			sum += i;
			i += 2;
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}