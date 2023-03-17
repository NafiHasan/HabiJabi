#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long n;
		cin >> n;
		long long mx = (n - 1) * 3LL;
		long long mn = (n - 2) / 2LL;
		if (n % 2LL)mn++;
		cout << mx - (mn * 3LL) << "\n";
	}
	return 0;
}