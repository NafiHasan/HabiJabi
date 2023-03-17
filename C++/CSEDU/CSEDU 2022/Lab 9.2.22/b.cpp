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
		long long rt = 0;
		for (long long i = 1; i <= 100000; i++) {
			if (i * i <= n)rt = i;
			else break;
		}
		string ans = "";
		long long rem = n - (rt * rt);
		long long div = 0;
		while (ans.size() < 7) {
			long long gun;
			string tmp = to_string(rt) + ans;
			gun = stoll(tmp);
			div = 2 * gun;
			rem *= 100;
			for (long long i = 9; i >= 0; i--) {
				long long num = div * 10 + i;
				if (num * i <= rem) {
					ans += to_string(i);
					rem -= (num * i);
					break;
				}
			}
		}
		if (ans[6] >= '5') {
			if (ans[5] < '9')ans[5]++;
			else {
				ans[5] = '0';
				if (ans[4] < '9')ans[4]++;
				else {
					ans[4] = '0';
					ans[3]++;
				}
			}
		}
		ans.pop_back();
		cout << rt << "." << ans << '\n';
	}
	return 0;
}