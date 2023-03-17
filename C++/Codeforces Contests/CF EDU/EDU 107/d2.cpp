#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int n, k;
	cin >> n >> k;
	string s;
	for (int i = 0 ; i < k; i++) {
		s += i + 'a';
		for (int j = i + 1; j < k; j++) {
			s += i + 'a';
			s += j + 'a';
		}
	}
	while ((int)s.size() < n)s += s;
	while ((int)s.size() > n) s.pop_back();
	cout << s << "\n";
	return 0;
}