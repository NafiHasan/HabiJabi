#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	string s;
	vector<string> t;
	// while (1) {
	// 	char c;
	// 	cin >> c;
	// 	if (feof(stdin) || c == '\0' || c == '\n')break;
	// 	s += c;
	// }
	cin >> s;
	stack<string> st;
	for (int i = 0; i < s.size(); i++) {
		// if (st.size())cout << st.top() << '\n';
		string tmp = "";
		tmp += s[i];
		if (s[i] == ' ')continue;
		if (s[i] == '(') {
			st.push("(");
			continue;
		}
		if (s[i] >= '0' && s[i] <= '9')t.push_back(tmp);
		else if (s[i] == '*' || s[i] == '/') {
			while (!st.empty() && (st.top() == "*" || st.top() == "/")) {
				t.push_back(st.top());
				st.pop();
			}
			st.push(tmp);
		} else if (s[i] == ')') {
			while (!st.empty() && st.top() != "(") {
				t.push_back(st.top());
				st.pop();
			}
			st.pop();
		} else {
			while (!st.empty() && (st.top() == "+" || st.top() == "-" || st.top() == "*" || st.top() == "/")) {
				t.push_back(st.top());
				st.pop();
			}
			st.push(tmp);
		}
	}
	while (!st.empty()) {
		t.push_back(st.top());
		st.pop();
	}
	stack<string> ans;
	for (int i = 0; i < t.size(); i++) {
		// cout << t[i] << '\n';
		if (t[i] == "+" || t[i] == "-" || t[i] == "/" || t[i] == "*") {
			long long tmp = stoll(ans.top());
			ans.pop();
			long long tmp2 = stoll(ans.top());
			ans.pop();
			if (t[i] == "+")tmp = tmp2 + tmp;
			else if (t[i] == "-")tmp = tmp2 - tmp;
			else if (t[i] == "*")tmp = tmp2 * tmp;
			else tmp = tmp2 / tmp;
			ans.push(to_string(tmp));
		} else ans.push(t[i]);
	}
	long long res = stoll(ans.top());
	cout << res << '\n';
	return 0;
}