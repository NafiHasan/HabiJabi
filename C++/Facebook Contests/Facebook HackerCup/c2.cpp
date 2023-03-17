#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case #" << cs << ":\n";
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<string> a;
		for (int i = 0; i <= 1024; i++) {
			string temp = "..........";
			for (int j = 0; j < 10; j++) {
				if (((1 << j) & i) != 0) {
					temp[j] = '-';
				}
			}
			// cout << temp << '\n';
			if (s.size() <= 10) {
				if (s != temp.substr(0, (int)s.size())) {
					// cout << s << ' ' << temp << '\n';
					a.push_back(temp);
				}
			} else {
				if (s.substr(0, 10) != temp) {
					a.push_back(temp);
				}
			}
		}
		for (int i = 0; i < n - 1; i++) {
			cout << a[i] << '\n';
		}
	}
	return 0;
}