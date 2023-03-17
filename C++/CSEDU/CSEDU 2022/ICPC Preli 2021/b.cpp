#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	int cs = 0;
	while (tc--) {
		cs++;
		cout << "Case " << cs << ": ";
		int a, b, c, k;
		cin >> a >> b >> c >> k;
		int avg = (a + b + c) / 3;
		if ((a + b + c) % 3 != 0) {
			cout << "Fight\n";
			continue;
		}
		bool ans = 1;
		if ((int)abs(avg - a) % k != 0)ans = 0;
		if ((int)abs(avg - b) % k != 0)ans = 0;
		if ((int)abs(avg - c) % k != 0)ans = 0;
		if (ans)cout << "Peaceful\n";
		else cout << "Fight\n";
	}
	return 0;
}