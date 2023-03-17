#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

int main() {
	FastIO;
	ll n, ans;
	cin >> n >> ans;
	vector<pair<int, int>> vp(n);
	for (int i = 0; i < n; i++)cin >> vp[i].first >> vp[i].second;
	vector<int> res(n, 0);


	for (int i = 0; i < 30; i++) {
		int curbit = (((1 << i) & ans) != 0);
		int after[n + 1][2];

		memset(after, 0, sizeof(after));
		after[0][1] = 1;
		for (int j = 0; j < n; j++) {
			int opbit = (((1 << i) & vp[j].second) != 0);
			if (vp[j].first == 1) {
				//and
				after[j + 1][0] = after[j][0] & opbit;
				after[j + 1][1] = after[j][1] & opbit;
			} else if (vp[j].first == 2) {
				//or
				after[j + 1][0] = after[j][0] | opbit;
				after[j + 1][1] = after[j][1] | opbit;
			} else {
				//xor
				after[j + 1][0] = after[j][0] ^ opbit;
				after[j + 1][1] = after[j][1] ^ opbit;
			}
		}
		for (int j = 0; j < n; j++) {
			curbit = after[j + 1][curbit];
			if (curbit == 1)res[j] |= (1 << i);
			else res[j] &= ~(1 << i);
			// res[j]
			// cout << ans << '\n';
		}
	}
	for (int i = 0; i < n; i++)cout << res[i] << '\n';
	return 0;
}