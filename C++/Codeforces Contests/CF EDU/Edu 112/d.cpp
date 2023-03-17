#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<string>v;
	v.push_back("abc");
	v.push_back("acb");
	v.push_back("bac");
	v.push_back("bca");
	v.push_back("cab");
	v.push_back("cba");

	vector<vector<int>>presum(6, vector<int>(n + 1, 0));
	for (int i = 0; i < 6; i++) {
		string temp = "";
		while (temp.size() < n) temp += v[i];
		while (temp.size() > n) temp.pop_back();
		vector<int>tara(n, 0);
		for (int j = 0 ; j < n; j++) if (s[j] != temp[j])tara[j]++;
		presum[i][0] = 0;
		for (int j = 0; j < n; j++) presum[i][j + 1] = presum[i][j] + tara[j];
	}
	while (m--) {
		int l, r;
		cin >> l >> r;
		int ans = n;
		for (int i = 0; i < 6; i++) ans = min(ans, presum[i][r] - presum[i][l - 1]);
		cout << ans << "\n";
	}
	return 0;
}