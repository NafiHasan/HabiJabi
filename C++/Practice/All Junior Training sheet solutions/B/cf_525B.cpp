#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	string s;
	cin >> s;
	int n = s.size(), m;
	cin >> m;
	vector<int> a(m), ans;
	for (int i = 0; i < m; i++)cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 0; i < m; i += 2) {
		int last;
		if (i < m - 1)last = a[i + 1];
		else last = n / 2 + 1;
		for (int j = a[i]; j < last; j++) {
			ans.push_back(j);
		}
	}
	// for (int i = 0; i < ans.size(); i++)cout << ans[i] << ' ';
	for (int i = 0; i < ans.size(); i++) {
		swap(s[ans[i] - 1], s[n - ans[i]]);
	}
	cout << s << '\n';
	return 0;
}