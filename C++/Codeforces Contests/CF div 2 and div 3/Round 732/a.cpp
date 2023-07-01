#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int a[n], b[n], suma = 0, sumb = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			suma += a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			sumb += b[i];
		}
		if (suma != sumb) {
			cout << "-1\n";
			continue;
		}
		vector<int>inc, dec;
		for (int i = 0; i < n; i++) {
			if (a[i] < b[i]) {
				for (int j = 1; j <= b[i] - a[i]; j++)inc.push_back(i + 1);
			} else if (a[i] > b[i]) {
				for (int j = 1; j <= a[i] - b[i]; j++)dec.push_back(i + 1);
			}
		}
		if ((int)dec.size() != (int)inc.size()) {
			cout << "-1\n";
			continue;
		}
		cout << (int)inc.size() << "\n";
		for (int i = 0; i < inc.size(); i++) {
			cout << dec[i] << " " << inc[i] << "\n";
		}
	}
	return 0;
}