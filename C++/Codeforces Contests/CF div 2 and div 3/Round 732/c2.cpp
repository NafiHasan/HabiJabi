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
		vector<int>odd(100005, 0), even(100005, 0), v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if (i % 2)odd[v[i]]++;
			else even[v[i]]++;
		}
		sort(v.begin(), v.end());
		bool ans = 1;
		for (int i = 0; i < n; i++) {
			if (i % 2) {
				if (odd[v[i]] == 0) {
					ans = 0;
					break;
				}
				odd[v[i]]--;
			} else {
				if (even[v[i]] == 0) {
					ans = 0;
					break;
				}
				even[v[i]]--;
			}
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}