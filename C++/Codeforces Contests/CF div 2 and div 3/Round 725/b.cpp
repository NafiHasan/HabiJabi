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
		string s, cop = "a";
		cin >> s;
		int last = 0, sz = 1;
		bool run  = 1;
		int cnt = 0;
		while (run) {
			cnt ++;
			// if (cnt > 10000)break;
			if (cnt != 1) {
				bool done = 0;
				for (int i = cop.size() - 1; i >= 0; i--) {
					if (cop[i] < 'z') {
						cop[i]++;
						for (int j = i + 1; j < cop.size(); j++)cop[j] = 'a';
						done = 1;
						break;
					}
				}
				if (done == 0) {
					int sss = cop.size();
					cop.clear();
					for (int i = 0; i <= sss; i++)cop += 'a';
				}

				// char c = cop[last];
				// cop.pop_back();
				// cop += (c + 1);
			}
			bool found = 0;
			for (int i = 0; i < n; i++) {
				if (s.substr(i, (int)cop.size()) == cop) {
					found = 1;
					break;
				}
			}
			if (found == 0) {
				cout << cop << en;
				run = 0;
				break;
			}
			// if (cop[last] == 'z') {
			// 	last++;
			// 	sz++;
			// 	cop.clear();
			// 	for (int j = 0; j <= last; j++)cop += 'a';
			// }
			// cout << cop << en;
		}
	}
	return 0;
}