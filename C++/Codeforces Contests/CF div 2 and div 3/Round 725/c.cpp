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
		cin >> n;
		string s;
		cin >> s;
		map<pair<int, int>, int>m;
		int d = 0, k = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'D')d++;
			if (s[i] == 'K')k++;
			int g = __gcd(d, k);
			m[ {d / g, k / g}]++;
			cout << m[ {d / g, k / g}] << " ";
		}
		cout << en;
	}
	return 0;
}