#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n ;
		stack<pair<char, int>> st;
		string s;
		cin >> s;
		int cnt = 1;
		for (int i = 0; i < 2 * n; i++) {
			if (s[i] == '(') {
				st.push({s[i], i});
			} else {
				if ((i - 1) != st.top().second) {
					cnt++;
					st.pop();
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}