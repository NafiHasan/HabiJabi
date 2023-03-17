#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		long long a, b;
		cin >> a >> b;
		if (a % 3 != 0)a += (3LL - (a % 3LL));
		if (b % 3 != 0)b += (3LL - (b % 3LL));
		a *= b;
		long long ans = a / 9;
		cout << ans << '\n';
	}
	return 0;
}