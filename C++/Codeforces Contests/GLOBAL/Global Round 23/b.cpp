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
		deque<int> d;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			d.push_back(x);
		}
		int ans = 0;
		while (!d.empty()) {
			while (!d.empty() && d.front() == 0)d.pop_front();
			while (!d.empty() && d.back() == 1)d.pop_back();
			if (!d.empty() && d.front() == 1 && d.back() == 0) {
				ans++;
				d.pop_front();
				d.pop_back();
			}
		}
		cout << ans << '\n';
	}
	return 0;
}