#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		map<char, int> mp;
		for (int i = 0; i < n; i++) {
			mp[s[i]]++;
		}
		int div = n / k;
		string ans = "";
		while (ans.size() < k) {
			char c = '@', last = 'a';
			for (int i = 0; i < div; i++) {
				last = i + 'a';
				if (mp[i + 'a'] > 0) {
					mp[i + 'a']--;
				} else if (c == '@') {
					c = i + 'a';
				}
			}
			if (c == '@' && last == 'z')c = 'z';
			else if (c == '@' && last != 'z')c = last + 1;
			ans += c;
		}
		cout << ans << '\n';
	}
	return 0;
}