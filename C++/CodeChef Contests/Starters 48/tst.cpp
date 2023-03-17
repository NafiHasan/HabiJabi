#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		int n = s.size();
		s[0] = '(', s[n - 1] = ')';
		int cnt0 = 0, cnt1  = 0;
		vector<int> pos;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(')cnt0++;
			else if (s[i] == ')')cnt1++;
			else pos.push_back(i);
		}
		for (int i = 0; i < pos.size(); i++) {
			if (cnt0 < n / 2) {
				s[pos[i]] = '(';
				cnt0++;
			} else s[pos[i]] = ')';
		}
		bool ans = 1;
		int ind1 = -1, ind2 = -1;
		for (int i = 0, j = pos.size()  - 1; i < pos.size(); i++, j--) {
			if (s[pos[i]] == ')' && ind1 == -1)ind1 = pos[i];
			if (s[pos[j]] == '(' && ind2 == -1)ind2 = pos[j];
		}
		if (ind1 != -1 && ind2 != -1) {
			// cout << ind1  << ' ' << ind2  << '\n';;
			// cout << s << '\n';
			swap(s[ind1], s[ind2]);
			// cout << s << '\n';
			int cnt = 0;
			bool ex = 1;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '(')cnt++;
				else cnt--;
				if (cnt < 0) {
					ex = 0;
					break;
				}
			}
			if (ex)ans = 0;
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

// (()?()?)