#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int n;
	cin >> n;
	long long ans = 0;
	bool eq = 1;
	long long mn = INT_MAX, num = -1;
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		if (a != b)eq = 0;
		ans += a;
		if (b < a)mn = min(mn, b);
	}
	ans -= mn;
	if (eq)ans = 0;
	cout << ans << '\n';
	return 0;
}