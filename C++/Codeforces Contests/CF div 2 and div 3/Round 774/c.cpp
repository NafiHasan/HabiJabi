#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long n;
		cin >> n;
		vector<long long> fac(20);
		fac[0] = 1;
		for (long long i = 1; i < 17; i++) fac[i] = fac[i - 1] * i;
		long long ans = n;
		long long bas = log2(n);
		if (pow(2, bas) == n) {
			cout << "1\n";
			continue;
		}
		for (int i = 0; i < pow(2 , 16); i++) {
			long long sum = 0, cnt = 0;
			for (long long j = 0; j < 16; j++) {
				if (((1LL << j) & i) != 0) {
					sum += fac[j];
					cnt++;
				}
			}
			if (sum > n)continue;
			if (sum == n) {
				ans = min(ans, cnt);
				continue;
			}
			long long rem = n - sum;
			cnt += __builtin_popcountll(rem);
			ans = min(ans, cnt);
		}
		cout << ans << '\n';
	}
	return 0;
}