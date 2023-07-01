#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	w(t) {
		int k, n , m;
		cin >> k >> n >> m;
		int a[n], b[m];
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < m; i++)cin >> b[i];
		vector<int>final;
		int now = k;
		for (int i = 0, j = 0; ; ) {
			if (i >= n && j >= m)break;
			if (i < n && a[i] == 0) {
				final.push_back(a[i]);
				i++;
			} else if (j < m && b[j] == 0)final.push_back(b[j++]);
			else if (i < n && j < m && a[i] == min(a[i], b[j]))final.push_back(a[i++]);
			else if (j < m && i < n && b[j] == min(a[i], b[j]))final.push_back(b[j++]);
			else {
				if (i < n)final.push_back(a[i++]);
				else if (j < m)final.push_back(b[j++]);
			}
		}
		bool ans = 1;
		for (int i = 0; i < final.size() ; i++) {
			if (final[i] != 0 && final[i] > now) {
				ans = 0;
				false;
			} else if (final[i] == 0)now++;
		}
		if (ans) {
			for (int i = 0; i < final.size(); i++)cout << final[i] << " ";
			cout << "\n";
		} else cout << "-1\n";
	}
	return 0;
}