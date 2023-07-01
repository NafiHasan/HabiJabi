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
		int cntt = 0;
		bool brk = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'T') {
				cntt++;
				if (cntt > (n / 3))brk = 1;
			} else if (s[i] == 'M') {
				cntt--;
				if (cntt < 0)brk = 1;
			}
		}
		if (cntt == (n / 3) && brk == 0)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}