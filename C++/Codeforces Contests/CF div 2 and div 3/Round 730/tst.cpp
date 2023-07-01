#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int sum = 0;
	for (long long i = 1, j = 58; i < 29; i++, j--) {
		sum += i * j;
		cout << i << " " << j << en;
	}
	cout << 2 * sum << en;
	return 0;
}