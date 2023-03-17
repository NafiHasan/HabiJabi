#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		int n;
		cin >> n;
		deque<int> a;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			a.push_back(x);
		}
		int last = 0, cnt = 0;
		while (1) {
			// for (int i = 0; i < a.size(); i++)cout << a[i] << ' ';
			// cout << "\n";
			if (a.empty())break;
			if (a.back() >= a.front()) {
				if (last > a.front() && last > a.back()) {
					break;
				} else if (last > a.front() && last <= a.back()) {
					last = max(last, a.back());
					a.pop_back();
					cnt++;
				} else {
					last = max(last, a.front());
					a.pop_front();
					cnt++;
				}
			} else {
				if (last > a.back() && last > a.front()) {
					break;
				} else if (last > a.back() && last <= a.front()) {
					last = max(last, a.front());
					a.pop_front();
					cnt++;
				} else {
					last = max(last, a.back());
					a.pop_back();
					cnt++;
				}
			}
		}
		cout << "Case #" << cs << ": " << cnt << "\n";
	}
	return 0;
}