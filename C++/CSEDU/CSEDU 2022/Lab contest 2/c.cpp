#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	// fast_io();
	int tc;
	cin >> tc;
	getchar();
	for (int cs = 1; cs <= tc; cs++) {
		char ch;
		string line, tmp;
		deque<pair<string, int>> d;
		int ind = 0;
		while (1) {
			getline(cin, line);
			// cout << line << "\n";
			if (line == "END")break;
			for (int i = 0; i < line.size(); i++) {
				if (line[i] >= 'a' && line[i] <= 'z') {
					tmp += line[i];
				} else {
					if (tmp != "") {
						d.push_back({tmp, ind++});
						tmp = "";
					}
				}
			}
			if (tmp != "") {
				d.push_back({tmp, ind++});
				tmp = "";
			}
		}
		map<string , int> mp;
		int sz = 0;
		for (int i = 0; i < d.size(); i++) {
			mp[d[i].first]++;
			// cout << d[i].first << ' ' << d[i].second + 1 << " " << mp[d[i].first] << '\n';
			if (mp[d[i].first] == 1) {
				sz++;
			}
		}
		mp.clear();
		int got = 0;
		int lo = 1, hi = d.size();
		deque<pair<string, int>> ans;
		for (int i = d.size() - 1; i >= 0; i--) {
			ans.push_back(d[i]);
			mp[d[i].first]++;
			if (got < sz && mp[d[i].first] == 1)got++;
			if (got == sz && ans.size() > 1 && ans.back().first == ans.front().first) {
				mp[ans.front().first]--;
				ans.pop_front();
			}
			while (got == sz && ans.size() > 1) {
				if (ans[0].first == ans[1].first) {
					mp[ans.front().first]--;
					ans.pop_front();
				} else break;
			}
			while (got == sz && !ans.empty() && mp[ans.front().first] > 1) {
				mp[ans.front().first]--;
				ans.pop_front();
			}
			if (got == sz && ans.size() >= 1 && ans.size() <= (hi - lo + 1)) {
				lo = ans.back().second + 1;
				hi = ans.front().second + 1;
				// cout << lo << ' ' << hi << '\n';
			}
			// for (int j = 0; j < ans.size(); j++)cout << ans[j].first << ' ';
			// cout << "\n";
		}
		while (got == sz && mp[ans.back().first] > 1) {
			ans.pop_back();
			mp[ans.back().first]--;
		}
		while (got == sz && ans.size() > 1) {
			if (ans.front().first == ans.back().first) {
				ans.pop_back();
			} else break;
		}
		if (got == sz && ans.size() >= 1 && ans.size() <= (hi - lo + 1)) {
			lo = ans.back().second + 1;
			hi = ans.front().second + 1;
			// cout << lo << ' ' << hi << '\n';
		}
		cout << "Document " << cs << ": " << lo << ' ' << hi << "\n";
	}
	return 0;
}