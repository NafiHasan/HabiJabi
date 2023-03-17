#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ind = n + 1;
	// for (int i = 1; i < n; i++) {
	// 	if (s[i] > s[0]) {
	// 		ind = i + 1;
	// 		break;
	// 	}
	// }
	// if (ind > n) {
	// for (int i = 1; i < n; i++) {
	// 	string tmp = s.substr(i, n - i);
	// 	// cout << tmp << '\n';
	// 	if (tmp > s) {
	// 		ind = i + 1;
	// 		// cout << ind << '\n';
	// 		break;
	// 	}
	// }
	// }
	while (s.size() >= ind)s.pop_back();
	while (s.size() < k)s += s;
	while (s.size() > k)s.pop_back();
	for (int i = 1; i < s.size(); i++) {
		string tmp = s.substr(i, s.size() - i);
		// cout << tmp << '\n';
		if (tmp > s) {
			ind = i + 1;
			// cout << ind << '\n';
			break;
		}
	}
	while (s.size() >= ind)s.pop_back();
	while (s.size() < k)s += s;
	while (s.size() > k)s.pop_back();
	cout << s << "\n";
	return 0;
}