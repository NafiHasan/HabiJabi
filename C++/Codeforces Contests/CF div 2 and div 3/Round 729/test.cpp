#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	long long l = 1;
	for (long long i = 2; i < 1000000; i++) {
		l = l * i / __gcd(l, i);
		if (l > (long long)1e17) {
			cout << i << "\n";
			break;
		}
	}
	return 0;
}