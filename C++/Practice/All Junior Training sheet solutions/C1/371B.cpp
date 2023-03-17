#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int a , b ;
	cin >> a >> b;
	vector<int> cnt1(3, 0), cnt2(3, 0);
	while (a % 2 == 0) {
		a /= 2;
		cnt1[0]++;
	}
	while (a % 3 == 0) {
		a /= 3;
		cnt1[1]++;
	}
	while (a % 5 == 0) {
		a /= 5;
		cnt1[2]++;
	}
	while (b % 2 == 0) {
		b /= 2;
		cnt2[0]++;
	}
	while (b % 3 == 0) {
		b /= 3;
		cnt2[1]++;
	}
	while (b % 5 == 0) {
		b /= 5;
		cnt2[2]++;
	}
	int ans = 0;
	int need2 = min(cnt1[0], cnt2[0]);
	ans += cnt1[0] - need2 + cnt2[0] - need2;
	need2 = min(cnt1[1], cnt2[1]);
	ans += cnt1[1] - need2 + cnt2[1] - need2;
	need2 = min(cnt1[2], cnt2[2]);
	ans += cnt1[2] - need2 + cnt2[2] - need2;
	if (a != b) {
		cout << "-1\n";
	} else {
		cout << ans << '\n';
	}
	return 0;
}