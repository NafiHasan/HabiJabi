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
		string s;
		cin >> n >> s;
		int mid = 0, cnt = 0;
		for (int i = 0; i < n; i++)if (s[i] == '*') cnt++;
		if (cnt % 2) {
			int pos = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == '*')mid++;
				if (mid == (cnt + 1) / 2) {
					pos = i;
					break;
				}
			}
			vector<int>left, right;
			for (int i = 0; i < n; i++) {
				if (i < pos && s[i] == '*')left.push_back(i);
				else if (i > pos && s[i] == '*')right.push_back(i);
			}
			long long cost = 0;
			for (int i = 0; i < left.size(); i++) {
				cost += (pos - (i + 1)) - left[i];
			}
			for (int i = 0; i < right.size(); i++) {
				cost += right[i] - (pos + (i + 1));
			}
			cout << cost << en;
		} else {
			int pos = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == '*')mid++;
				if (mid == (cnt + 1) / 2) {
					pos = i;
					break;
				}
			}
			vector<int>left, right;
			for (int i = 0; i < n; i++) {
				if (i < pos && s[i] == '*')left.push_back(i);
				else if (i > pos && s[i] == '*')right.push_back(i);
			}
			long long cost = 0;
			for (int i = 0; i < left.size(); i++) {
				cost += (pos - (i + 1)) - left[i];
			}
			for (int i = 0; i < right.size(); i++) {
				cost += right[i] - (pos + (i + 1));
			}


			int mid2 = 0;
			int pos2 = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == '*')mid2++;
				if (mid2 + 1 == (cnt + 1) / 2) {
					pos = i;
					break;
				}
			}
			vector<int>left2, right2;
			for (int i = 0; i < n; i++) {
				if (i < pos2 && s[i] == '*')left2.push_back(i);
				else if (i > pos2 && s[i] == '*')right2.push_back(i);
			}
			long long cost2 = 0;
			for (int i = 0; i < left2.size(); i++) {
				cost2 += (pos2 - (i + 1)) - left2[i];
			}
			for (int i = 0; i < right2.size(); i++) {
				cost2 += right2[i] - (pos2 + (i + 1));
			}
			cout << min(cost, cost2) << en;
		}
	}
	return 0;
}