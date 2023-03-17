#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		double n;
		cin >> n;
		cout << fixed << setprecision(6) << sqrt(n) << '\n';
	}
	return 0;
}