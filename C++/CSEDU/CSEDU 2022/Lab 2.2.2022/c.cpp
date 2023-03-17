#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	string s;
	cin >> s;
	stack<char> st;
	int ans = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			st.push(s[i]);
			ans = max(ans, (int)st.size());
			continue;
		}
		if (s[i] == ')' && st.top() != '(') {
			ans = -1;
			break;
		} else if (s[i] == '}' && st.top() != '{') {
			ans = -1;
			break;
		} else if (s[i] == ']' && st.top() != '[') {
			ans = -1;
			break;
		} else st.pop();
	}
	if (!st.empty() && ans == -1)cout << "0\n";
	else cout << ans << '\n';
	return 0;
}