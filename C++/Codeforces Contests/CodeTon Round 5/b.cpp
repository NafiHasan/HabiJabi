#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, x;
		cin >> n >> x;
		vector<int> a, b, c;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			a.push_back(x);
		}
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			b.push_back(x);
		}
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			c.push_back(x);
		}
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		reverse(c.begin(), c.end());
		int cur = 0;
		while (x != cur) {
			if (a.size() > 0 && (((a.back() | cur) | x) == x)) {
				cur |= a.back();
				a.pop_back();
			} else if (b.size() > 0 && (((b.back() | cur) | x) == x)) {
				cur |= b.back();
				b.pop_back();
			} else if (c.size() > 0 && (((c.back() | cur) | x) == x)) {
				cur |= c.back();
				c.pop_back();
			} else {
				break;
			}
		}
		if (x == cur) {
			cout << "Yes\n";
		} else cout << "No\n";
	}
	return 0;
}