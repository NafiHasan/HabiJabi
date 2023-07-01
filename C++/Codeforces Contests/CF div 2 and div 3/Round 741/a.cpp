#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b ;
		int mid = b / 2 + 1;
		cout << min (b - a, b - mid) << '\n';
	}
	return 0;
}