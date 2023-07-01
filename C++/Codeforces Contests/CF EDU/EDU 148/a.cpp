#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		int n = s.size();
		vector<int> cnt(30, 0);
		for (int i = 0; i < n; i++)cnt[s[i] - 'a']++;
		int ans = 0;
		for (int i = 0; i < 30; i++) {
			if (cnt[i] > 1)ans++;
		}
		if (ans > 1)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}