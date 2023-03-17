#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";
		long long n;
		cin >> n;
		long long ans = 0, cnt1 = 0;
		for (int i = 0; i < n; i++) {
			long long x;
			cin >> x;
			if (x == 1)cnt1++;
			ans ^= x;
		}
		if (cnt1 == n && cnt1 % 2 == 1)cout << "Bob\n";
		// if (ans == 0 || (cnt1 == n && cnt1 % 2 == 1))cout << "Bob\n";
		else if (cnt1 == n && cnt1 % 2 == 0)cout << "Alice\n";
		else if (ans == 0) cout << "Bob\n";
		else cout << "Alice\n";
	}
	return 0;
}