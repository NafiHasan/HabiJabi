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
		bool pal = 1;
		for (int i = 0; i < n / 2; i++) {
			if (s[i] != s[n - i - 1])pal = 0;
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)if (s[i] == '0')cnt ++;
		if (pal && n % 2 == 0)cout << "BOB\n";
		else if (pal && n % 2 && s[n / 2] == '0' && cnt > 1)cout << "ALICE\n";

	}
	return 0;
}