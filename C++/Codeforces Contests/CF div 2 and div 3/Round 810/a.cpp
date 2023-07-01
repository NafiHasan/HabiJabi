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
		cout << n << ' ';
		for (int i = 1; i < n; i++)cout << i << ' ';
		cout << '\n';
	}
	return 0;
}