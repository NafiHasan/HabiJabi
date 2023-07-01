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
		int ans = 0, curPig = 0, now = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x == 1) {
				curPig++;
				now++;
				ans = max(ans, now);
			} else {
				int cnt = (curPig + 2) / 2;
				if (curPig == 0)cnt = 0;
				now = cnt;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
