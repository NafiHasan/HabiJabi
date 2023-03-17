#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool only(string s) {
	for (int i = 1; i < s.size(); i++)if (s[i] != s[i - 1])return 0;
	return 1;
}


int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		int n; cin >> n;
		vector<string> v(n);
		for (int i = 0; i < n; i++)cin >> v[i];
		sort(v.begin(), v.end());
		deque<deque<string>> dd;
		bool brk = 1;
		deque<string> d;
		while (brk) {
			brk = 0;
			if (!d.empty()) {
				char fi = d.front().front();
				bool f = 0;
				for (int i = 0; i < n; i++) {
					if (v[i] == "")continue;
					if (v[i].back() == fi && only(v[i])) {
						d.push_front(v[i]);
						v[i] = "";
						f = 1;
						brk = 1;
						break;
					}
				}
				if (f == 0) {
					for (int i = 0; i < n; i++) {
						if (v[i] == "")continue;
						if (v[i].back() == fi) {
							d.push_front(v[i]);
							v[i] = "";
							brk = 1;
							break;
						}
					}
				}
				f = 0;
				char la = d.back().back();
				for (int i = 0; i < n; i++) {
					if (v[i] == "")continue;
					if (v[i].front() == la && only(v[i])) {
						d.push_back(v[i]);
						v[i] = "";
						brk = 1;
						f = 1;
						break;
					}
				}
				if (f == 0) {
					for (int i = 0; i < n; i++) {
						if (v[i] == "")continue;
						if (v[i].front() == la) {
							d.push_back(v[i]);
							v[i] = "";
							brk = 1;
							break;
						}
					}
				}
			}
			if (brk == 0) {
				if (!d.empty())dd.push_back(d);
				d.clear();
				for (int i = 0; i < n; i++) {
					if (v[i] == "")continue;
					d.push_back(v[i]);
					v[i] = "";
					brk = 1;
					break;
				}
			}
		}
		string ans = "";
		for (int j = 0; j < dd.size(); j++) {
			deque<string> tmp = dd[j];
			for (int i = 0; i < tmp.size(); i++)ans += tmp[i];
		}
		map<char, int>m;
		bool ok = 1;
		for (int i = 0; i < ans.size(); i++) {
			m[ans[i]]++;
			if (i && m[ans[i]] > 1 && ans[i] != ans[i - 1]) {
				ok = 0;
				break;
			}
		}
		cout << "Case #" << cs << ": ";
		if (ok)cout << ans << "\n";
		else cout << "IMPOSSIBLE\n";
	}
	return 0;
}