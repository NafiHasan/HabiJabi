#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

long long fun(string s, int n) {
	int sz = s.size();
	string rep = s.substr(0, n);
	string tmp = "";
	while ((int)tmp.size() < sz)tmp += rep;
	long long tm = stoll(tmp);
	if (tm > stoll(s)) {
		bool done = 0;
		for (int i = rep.size() - 1; i >= 0; i--) {
			if (rep[i] != '0') {
				rep[i]--;
				for (int j = i + 1; j < rep.size() ; j++) {
					rep[j] = '9';
				}
				done = 1;
				break;
			}
		}
		tmp = "";
		while ((int)tmp.size() < sz)tmp += rep;
		if (done) tm = stoll(tmp);
	}
	if (tm > stoll(s) || to_string(tm).size() != s.size())return 0;
	return tm;
}



int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		int n = s.size();
		long long ans = 0;
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				long long ret = fun(s, i);
				ans = max(ans, ret);
				if (i != 1)ret = fun(s, n / i);
				ans = max(ans, ret);
			}
		}
		if (ans == 0) {
			n--;
			string tmp = "";
			while ((int)tmp.size() < n)tmp += '9';
			ans = stoll(tmp);
		}
		ans = max(ans, 11LL);
		cout << ans << '\n';
	}
	return 0;
}