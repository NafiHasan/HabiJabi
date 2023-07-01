#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		string s; cin >> s;
		int n = s.size();
		vector<int> last(10, -1);
		for (int i = 0; i < n; i++) {
			last[s[i] - '0'] = i;
		}
		for (int i = 0; i < n; i++) {
			int num = s[i] - '0';
			for (int j = 0; j < num; j++) {
				if (last[j] > i) {
					if (s[i] != '9') {
						s[i]++;
					}
					break;
				}
			}
		}
		sort(s.begin(), s.end());
		cout << s << '\n';
	}
	return 0;
}