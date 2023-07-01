#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n + 1);
		map<int, int> mx, last, cnt;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (last[a[i]] == 0) {
				cnt[a[i]]++;
				mx[a[i]] = max(mx[a[i]], cnt[a[i]]);
				last[a[i]] = i;
			} else {
				cnt[a[i]] -= i - last[a[i]] - 1;
				cnt[a[i]] = max(0, cnt[a[i]]);
				cnt[a[i]]++;
				last[a[i]] = i;
				mx[a[i]] = max(mx[a[i]], cnt[a[i]]);
			}
		}
		int ans = 0, ind = 0;
		for (int i = 1; i <= n; i++) {
			if (mx[a[i]] > ans) {
				ans = mx[a[i]];
				ind = a[i];
			}
		}
		int fi = -1, la = -1;
		mx.clear(), cnt.clear(), last.clear();
		for (int i = 1; i <= n; i++) {
			if (a[i] != ind)continue;
			if (last[ind] == 0) {
				cnt[ind]++;
				mx[ind] = max(mx[ind], cnt[ind]);
				last[ind] = i;
			} else {
				cnt[ind] -= i - last[ind] - 1;
				cnt[ind] = max(0, cnt[ind]);
				cnt[ind]++;
				last[ind] = i;
				mx[ind] = max(mx[ind], cnt[ind]);
			}
			if (mx[ind] == ans) {
				la = i;
				int cn = 0;
				for (int j = la; j >= 1; j--) {
					if (a[j] == ind)cn++;
					else cn--;
					if (cn == ans) {
						fi = j;
						break;
					}
				}
				break;
			}
		}
		cout << ind << ' ' << fi << ' ' << la << '\n';
	}
	return 0;
}