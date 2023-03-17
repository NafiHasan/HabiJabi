#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n;
	cin >> n;
	deque<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	vector<int> ans;
	string res = "";
	int all = 0;
	if (a.front() > a.back()) {
		ans.push_back(a.back());
		all++;
		res += "R";
		a.pop_back();
	} else if (a.front() < a.back()) {
		ans.push_back(a.front());
		all++;
		res += "L";
		a.pop_front();
	} else {
		int cnt = 1, best = 0;
		for (int i = 1; i < a.size(); i++) {
			if (a[i] > a[i - 1])cnt++;
			else break;
		}
		best = max(best, cnt);
		cnt = 1;
		for (int i = a.size() - 1; i > 0; i--) {
			if (a[i] < a[i - 1])cnt++;
			else break;
		}
		if (best > cnt) {
			if (ans.empty()) {
				int tmp = a.front();
				a.pop_front();
				ans.push_back(tmp);
				all++;
				res += "L";
			}
		} else {
			if (ans.empty()) {
				int tmp = a.back();
				a.pop_back();
				ans.push_back(tmp);
				all++;
				res += "R";
			}
		}
	}
	while (!a.empty()) {
		if (a.size() == 1) {
			if (a[0] > ans.size()) {
				all++;
				res += "L";
			}
			break;
		}
		int f = a.front(), l = a.back();
		// cout << f << ' ' << l << '\n';
		if (ans.back() < l && l < f) {
			ans.push_back(l);
			res += "R";
			all++;
			a.pop_back();
		} else if (ans.back() < f && f < l) {
			ans.push_back(f);
			res += "L";
			all++;
			a.pop_front();
		} else if (ans.back() < l && l > f) {
			ans.push_back(l);
			res += "R";
			all++;
			a.pop_back();
		} else if (ans.back() < f && f > l) {
			ans.push_back(f);
			res += "L";
			all++;
			a.pop_front();
		} else {
			int cnt = 1, best = 0;
			for (int i = 1; i < a.size(); i++) {
				if (a[i] > a[i - 1])cnt++;
				else break;
			}
			best = max(best, cnt);
			cnt = 1;
			for (int i = a.size() - 1; i > 0; i--) {
				if (a[i] < a[i - 1])cnt++;
				else break;
			}
			if (best > cnt) {
				if (ans.empty()) {
					int tmp = a.front();
					a.pop_front();
					ans.push_back(tmp);
					all++;
					res += "L";
				}
				while (ans.back() < a.front()) {
					int tmp = a.front();
					a.pop_front();
					ans.push_back(tmp);
					all++;
					res += "L";
				}
			} else {
				if (ans.empty()) {
					int tmp = a.back();
					a.pop_back();
					ans.push_back(tmp);
					all++;
					res += "R";
				}
				while (ans.back() < a.back()) {
					int tmp = a.back();
					a.pop_back();
					ans.push_back(tmp);
					all++;
					res += "R";
				}
			}
			break;
		}
	}
	cout << all << "\n";
	cout << res << "\n";
	return 0;
}