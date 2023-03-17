#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	vector<double> pre(1000005, 0.0);
	for (int i = 1; i < 1000005; i++) {
		pre[i] += pre[i - 1] + log((double)i);
	}
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";
		int n, b;
		cin >> n >> b;
		double ans = pre[n] / log((double)b);
		ans += 1.0;
		int res = ans;
		cout << res << '\n';
	}
	return 0;
}