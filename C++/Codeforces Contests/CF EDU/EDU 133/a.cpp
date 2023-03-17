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
		int ans = n / 3;
		if (n % 3 != 0)ans++;
		if (n == 1)ans = 2;
		cout << ans << '\n';
	}
	return 0;
}