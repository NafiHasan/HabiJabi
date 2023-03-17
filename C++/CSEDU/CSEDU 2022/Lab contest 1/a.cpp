#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	// fast_io();
	while (1) {
		vector<string> v;
		string ans = "";
		map<char, int> m;
		string s;
		while (1) {
			cin >> s;
			if (s == "#")break;
			if (feof(stdin))return 0;
			v.push_back(s);
		}
		// vector<vector<string>> vp;
		// for (int i = 0; i < v.size(); i++) {
		// 	if (m[v[i][0]] == 0) {
		// 		m[v[i][0]]++;
		// 		ans += v[i][0];
		// 	}
		// }
		for (int i = 1; i < v.size(); i++) {
			string t1, t2;
			t1 = v[i - 1], t2 = v[i];
			// if (t1[0] != t2[0])continue;
			for (int j = 0; j < min(t1.size(), t2.size()); j++) {
				if (t1[j] == t2[j]) {
					if (m[t1[j]] > 0)continue;
					else {
						m[t1[j]]++;
						ans += t1[j];
					}
				} else {
					if (m[t1[j]] == 0) {
						m[t1[j]]++;
						ans += t1[j];
					} else if (m[t2[j]] == 0 ) {
						m[t2[j]]++;
						ans += t2[j];
					}
					break;
				}
			}
			// while (!t1.empty() && !t2.empty()) {
			// 	if (t1[0] == t2[0]) {
			// 		t1.pop_back();
			// 		t2.pop_back();
			// 	} else {
			// 		if (m[t1[0]] == 0) {
			// 			m[t1[0]]++;
			// 			ans += t1[0];
			// 		} else if (m[t2[0]] == 0 ) {
			// 			m[t2[0]]++;
			// 			ans += t2[0];
			// 		}
			// 		break;
			// 	}
			// }
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].size(); j++) {
				if (m[v[i][j]] == 0) {
					ans += v[i][j];
					m[v[i][j]]++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}