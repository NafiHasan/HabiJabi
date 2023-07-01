#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		cout << "Division ";
		int n;
		cin >> n;
		if (n >= 1900)cout << 1 << "\n";
		else if (n >= 1600)cout << 2 << "\n";
		else if (n >= 1400)cout << 3 << "\n";
		else cout << "4\n";
	}
	return 0;
}