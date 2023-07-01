#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b, c;
		cin >> a >> b >> c;
		if ((a + b + c) % 3 != 0) {
			cout << "-1\n";
			continue;
		}
		int sum = a + b + c;
		int avg = sum / 3;
		int cnt = 0;
		cnt += abs(a - avg) + abs(b - avg) + abs(c - avg);
		cnt /= 2;
		cout << cnt << '\n';
	}
	return 0;
}
