#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	vector<int>xo(300005, 0);
	for (int i = 1; i < 300005; i++)xo[i] = (i ^ xo[i - 1]);
	while (tc--) {
		int a, b;
		cin >> a >> b;
		int x = xo[a - 1];
		if (x == b)cout << a << '\n';
		else if ((x ^ b) == a)cout << a + 2 << '\n';
		else cout << a + 1 << '\n';
	}
	return 0;
}