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
			d.push_back(i + 1);
		}
		vector<int> ans(n);
		int l = 1;
		for (int i = 0; i < n; i++) {
			if (l == 1) {
				ans[i] = d.back();
				d.pop_back();
				l = 0;
			} else {
				l = 1;
				ans[i] = d.front();
				d.pop_front();
			}
		}
		for (int i = 0; i < n; i++)cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}