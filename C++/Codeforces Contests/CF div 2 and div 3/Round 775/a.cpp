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
		vector<int> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		int pre = 0, last  = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0)break;
			pre = i;
		}
		for (int i =  n - 1; i > 0; i--) {
			if (a[i] == 0)break;
			last = i;
		}
		cnt = last - pre;
		if (cnt <= 1)cnt = 0;
		cout << cnt << '\n';
	}
	return 0;
}