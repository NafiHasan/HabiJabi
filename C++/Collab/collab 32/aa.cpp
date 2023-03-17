#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	char c;
	string s = "Samsung";
	int ind = 0;
	bool ans = 0;
	while (1) {
		cin >> c;
		if (cin.eof())break;
		if (ind < 7 && c == s[ind]) {
			ind++;
		}
		if (ind >= 7 )ans = 1;
	}
	if (ans)cout << "SRBD\n";
	else cout << "GHOST\n";
	return 0;
}