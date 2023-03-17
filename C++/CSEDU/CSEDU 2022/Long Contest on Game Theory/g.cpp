#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

long long grundy(long long n) {
	if (n % 2 == 0)return n / 2;
	else return grundy(n / 2);
}

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";
		int n;
		cin >> n;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			long long x;
			cin >> x;
			x = grundy(x);
			ans ^= x;
		}
		if (ans != 0)cout << "Alice\n";
		else cout << "Bob\n";
	}
	return 0;
}


// 1 - 0
// 2 - 1
// 3 - 0
// 4 - 2
// 5 - 1
// 6 - 3
// 7 - 0
// 8 - 4
// 9 - 2
// 10 - 5
// 11 - 1
// 12 - 6
// 13 - 3
// 14 - 7
// 15 - 0
