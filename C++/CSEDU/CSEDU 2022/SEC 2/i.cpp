#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n;
	cin >> n;
	double ans = 0;
	for (int i = 1; i <= 40 ; i++) {
		double ad = i / pow(n, i);
		ans += ad;
	}
	cout << fixed << setprecision(10) << ans << '\n';
	return 0;
}
