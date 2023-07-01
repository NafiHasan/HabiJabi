#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		string a, b;
		cin >> a >> b;
		if (a == b) {
			cout << "=\n";
			continue;
		}
		if (a == "M") {
			if (b.back() == 'L') {
				cout << "<\n";
			} else {
				cout << ">\n";
			}
			continue;
		}
		if (a.back() != b.back()) {
			if (a.back() == 'S') {
				cout << "<\n";
			} else cout << ">\n";
			continue;
		}
		if (a.back() == 'S') {
			if (a.size() < b.size()) {
				cout << ">\n";
			} else cout << "<\n";
		} else {
			if (a.size() > b.size()) {
				cout << ">\n";
			} else cout << "<\n";
		}
	}
	return 0;
}