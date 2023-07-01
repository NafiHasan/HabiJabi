#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, mn, mx;
		cin >> n >> mn >> mx;
		string s;
		cin >> s;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1')cnt1++;
			else if (s[i] == '2')cnt2++;
			else cnt3++;
		}
		int box = n / mx;
		if (n % mx != 0)box++;
		box = max(box, cnt1);
		if ((box * mn) > n || box > (cnt1 + cnt3)) {
			cout << "NO\n";
			continue;
		} else cout << "YES\n";
	}
	return 0;
}