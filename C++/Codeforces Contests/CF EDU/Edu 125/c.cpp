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
		string s;
		cin >> s;
		stack<char> st;
		for (int i = n - 1; i >= 0; i--) {
			st.push(s[i]);
		}
		int ans = 0;
		int length = -1;
		bool ok = 1;
		while (st.size() > 1 && ok) {
			ans++;
			char t1 = st.top();
			st.pop();
			char t2 = st.top();
			st.pop();
			if (t1 == t2)continue;
			if (t1 == '(' && t2 == ')')continue;
			else {
				int len = st.size();
				bool br = 0;
				while (st.size() > 0) {
					char t3 = st.top();
					st.pop();
					if (t3 == t1) {
						br = 1;
						break;
					}
				}
				if (!br) {
					length = len + 2;
					ans--;
					ok = 0;
				}
			}
		}
		if (length == -1)length = st.size();
		cout << ans << ' ' << length << '\n';
	}
	return 0;
}