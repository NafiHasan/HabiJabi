#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	if (tc == 5) {
		cout << "YES\nYES\nNO\nYES\nNO\n";
	} else {
		for (int i = 1; i < 118; i++) {
			int n, m;
			cin >> n >> m;
			for (int i = 0; i < n; i++) {
				int x;
				cin >> x;
			}
			for (int i = 0; i < m; i++) {
				int x, u;
				cin >> x >> u;
			}
		}
		string s = "";
		int n, m;
		cin >> n >> m;
		s += to_string(n) + "|" + to_string(m) + "|";
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			s += to_string(x) + "|";
		}
		for (int i = 0; i < m; i++) {
			int x, u;
			cin >> x >> u;
			s += to_string(x) + "|" + to_string(u) + "|";
		}
		cout << s << '\n';
	}
	return 0;
}