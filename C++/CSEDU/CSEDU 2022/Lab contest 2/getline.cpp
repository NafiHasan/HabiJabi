#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	string s;
	while (1) {
		getline(cin, s);
		cout << s << '\n';
		if (s == "END")break;
	}
	return 0;
}