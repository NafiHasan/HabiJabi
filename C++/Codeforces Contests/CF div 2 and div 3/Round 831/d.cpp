#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(k);
		for (int i = 0; i < k; i++)cin >> a[i];
		map<int, int> appeared;
		int onBoard = 0, cur = k, maxCap = n * m - 4;
		bool ok = 1;
		for (int i = 0; i < k; i++) {
			if (a[i] == cur) {
				appeared[cur] = 1;
				cur--;
				while (appeared[cur] != 0) {
					cur--;
					onBoard--;
				}
			} else {
				onBoard++;
				appeared[a[i]] = 1;
			}
			if (onBoard > maxCap) {
				ok = 0;
				break;
			}
		}
		if (ok)cout << "YA\n";
		else cout << "TIDAK\n";
	}
	return 0;
}