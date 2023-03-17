#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	string ans = "";
	string s;
	int cnt = 0;
	vector<string> tok;
	while (1) {
		getline(cin , s);
		ans += s;
		string tmp = "";
		for (int i = 0; i < s.size(); i++) {
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))tmp += s[i];
			else {
				if (tmp != "")tok.push_back(tmp);
				tmp = "";
			}
		}
		if (tmp != "")tok.push_back(tmp);
		ans += ' ';
		if (s.substr(0, 7) == ".......") {
			ans.pop_back();
			break;
		}
	}
	for (int i = 0; i < tok.size(); i++)cout << tok[i] << '\n';
	return 0;
}