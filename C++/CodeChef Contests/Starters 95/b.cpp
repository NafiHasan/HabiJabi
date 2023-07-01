#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		long long mx = 0;
		int last = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mx = max(mx, a[i]);
			last = max(last, 64 - (__builtin_clzll(a[i])));
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if ((a[i] & (1LL << (last - 1))) != 0)cnt++;
		}
		cout << (cnt + 1) / 2 << '\n';
	}
	return 0;
}