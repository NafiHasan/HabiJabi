#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// bool check(deque<int> d) {
// 	for (int i = 0; i + (int)d.size() < )
// 	}
int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i  < n; i++)cin >> a[i];
		long long ans = 0;
		deque<int>seq;
		for (int k = 1; k <= 4; k++) {
			for (int i = 0; i + k <= n; i++) {
				seq.clear();
				int inc = 0, dec = 0;
				for (int j = i; j < i + k; j++) seq.push_back(a[j]);

				if (seq.size() == 3) {
					if (seq[1] >= seq[0] && seq[2] >= seq[1])inc++;
					if (seq[1] <= seq[0] && seq[2] <= seq[1])dec++;
				} else if (seq.size() > 3) {
					if (seq[1] >= seq[0] && seq[3] >= seq[1])inc++;
					else if (seq[2] >= seq[0] && seq[3] >= seq[2])inc++;
					else if (seq[1] >= seq[0] && seq[2] >= seq[1])inc++;
					if (seq[2] >= seq[3] && seq[1] >= seq[2]) dec++;
					else if (seq[2] >= seq[3] && seq[0] >= seq[2]) dec++;
					else if (seq[1] >= seq[3] && seq[0] >= seq[1]) dec++;
				}

				if (seq.size() < 3)ans++;
				else {
					if (dec == 0 && inc == 0)ans++;
					else {
						for (int s = 0; s < seq.size(); s++)cout << seq[s] << " ";
						cout << "\n";
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}