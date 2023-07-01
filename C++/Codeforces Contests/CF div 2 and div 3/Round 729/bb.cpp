#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long n, a , b;
		cin >> n >> a  >> b;
		long long right  = n % b;
		long long left = 1;
		bool found = 0;
		if (a % b == 1) {
			if ((n - 1) % b == 0)found = 1;
		} else if (a % b == 0) {
			if (right == 0 && n >= a)found = 1;
			else if ((n - 1) % b == 0)found = 1;
		} else {
			while (left <= n) {
				if ((left % b) == right) {
					found = 1;
					break;
				}
				left *= a;
			}
		}
		if (found == 1)cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}