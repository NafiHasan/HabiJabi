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
		long long a, b;
		cin >> a >> b;
		if (a == b) {
			cout << "0 0\n";
			continue;
		}
		long long ex = abs(a - b);
		long long div1 = min(a, b) / ex;
		long long div2 =  min(a, b) / ex;
		if (min(a, b) % ex != 0)div2++;
		long long step = min(abs(ex * div1 - min(a, b)), abs(ex * div2 - min(a, b)));
		cout << ex << " " << step << "\n";
	}
	return 0;
}