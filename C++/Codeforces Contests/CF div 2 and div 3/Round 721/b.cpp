#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	w(t) {
		int n;
		string s;
		cin >> n >> s;
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0')cnt ++;
		}
		if (cnt == 0)cout << "DRAW\n";
		else if (n % 2 && s[n / 2] == '0' && cnt > 1)cout << "ALICE\n";
		else cout << "BOB\n";
	}
	return 0;
}