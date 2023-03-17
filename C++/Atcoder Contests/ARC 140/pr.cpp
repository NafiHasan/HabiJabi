#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();

	int a, b, n;
	cin >> n >> a >> b;
	if (a + b <= n)cout << "Yes\n";
	else cout << "No\n";
	// cout << a - b << '\n';
	// }
	return 0;
}