#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n;
	cin >> n;
	while (n--) {
		string s1, s2;
		cin >> s1 >> s2;
		for (int i = s1.size() - 1; i >= 0 && s1[i] == '0'; i--) s1.pop_back();
		for (int i = s2.size() - 1; i >= 0 && s2[i] == '0'; i--) s2.pop_back();
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		string ans = "";
		int rem = 0;
		int i, j;
		for (i = s1.size() - 1, j = s2.size() - 1; i >= 0 && j >= 0; i--, j--) {
			int num = (s1[i] - '0') + (s2[j] - '0') + rem;
			rem = 0;
			if (num > 9) {
				rem = num / 10;
				num %= 10;
			}
			ans += num + '0';
		}
		// cout << i << ' '  << j << '\n';
		for (; i >= 0; i--) {
			int num = s1[i] - '0' + rem;
			rem = 0;
			if (num > 9) {
				rem = num / 10;
				num %= 10;
			}
			ans += num + '0';
		}
		for (; j >= 0; j--) {
			int num = s2[j] - '0' + rem;
			rem = 0;
			if (num > 9) {
				rem = num / 10;
				num %= 10;
			}
			ans += num + '0';
		}
		if (rem > 0)ans += to_string(rem);
		// i = max(s1.size(), s2.size())-1;
		// for (; i >= min(s1.size(), s2.size()); i--){
		// 	if(s1.size() > s2.size())ans += s1[i];
		// else ans += s2[i];
		// }
		reverse(ans.begin(), ans.end());
		for (int i = ans.size() - 1; i >= 0 && ans[i] == '0'; i--) ans.pop_back();
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
	return 0;
}