#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	string s; cin >> s;
	int w;
	cin >> w;
	for (int i = 0; i < s.size(); i += w) {
		cout << s[i] ;
	}
	cout << "\n";
	return 0;
}
