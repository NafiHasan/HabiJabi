#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main() {
	fast_io();
	w(t) {
		int n, m;
		cin >> n >> m;
		map<int, char>mp;
		map<int, int>pos;
		vector<int>v(n), cop(n);
		deque<int>left_odd, left_even, right_odd, right_even;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			pos[v[i]] = i;
		}
		cop = v;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			mp[v[i]] = c;
			if (c == 'L') {
				if (v[i] % 2)left_odd.push_back(v[i]);
				else left_even.push_back(v[i]);
			} else {
				if (v[i] % 2)right_odd.push_back(v[i]);
				else right_even.push_back(v[i]);
			}
		}
		map<int, int>ans;
		sort(v.begin(), v.end());
		sort(left_odd.begin(), left_odd.end());
		sort(left_even.begin(), left_even.end());
		sort(right_even.begin(), right_even.end());
		sort(right_odd.begin(), right_odd.end());
		for (int i = 0; i < v.size() ; i++) {
			int an = INT_MAX;
			if (mp[v[i]] == 'L') {
				if (v[i] % 2) {
					left_odd.pop_front();
					if (!left_odd.empty()) {
						int tmp1 = left_odd[0];
						an = min(an, ((tmp1 + v[i]) / 2));
						// cout << an << en << ans[v[i]] << en << ans[tmp1] << en;
						if (ans[tmp1] == 0)ans[tmp1] = an;
						else ans[tmp1] = min(ans[tmp1], an);
						if (ans[v[i]] == 0)ans[v[i]] = an;
						else ans[v[i]] = min(ans[v[i]], an);
						// cout << v[i] << " " << tmp1 << en;
					}
					if (!right_odd.empty()) {
						int tmp2 = right_odd.back();
						int tm = m - tmp2 + v[i] + ((tmp2 - v[i]) / 2);
						// cout << tm << en;
						an = min(an, tm);
						if (ans[tmp2] == 0)ans[tmp2] = an;
						else ans[tmp2] = min(ans[tmp2], an);
						if (ans[v[i]] == 0)ans[v[i]] = an;
						else ans[v[i]] = min(ans[v[i]], an);
					}

				} else {
					if (!left_even.empty()) {
						int tmp1 = left_even[0];
						an = min(an, ((tmp1 + v[i]) / 2));
						if (ans[tmp1] == 0)ans[tmp1] = an;
						else ans[tmp1] = min(ans[tmp1], an);
						if (ans[v[i]] == 0)ans[v[i]] = an;
						else ans[v[i]] = min(ans[v[i]], an);
					}
					if (!right_even.empty()) {
						int tmp2 = right_even.back();
						int tm = m - tmp2 + v[i] + ((tmp2 - v[i]) / 2);
						an = min(an, tm);
						if (ans[tmp2] == 0)ans[tmp2] = an;
						else ans[tmp2] = min(ans[tmp2], an);
						if (ans[v[i]] == 0)ans[v[i]] = an;
						else ans[v[i]] = min(ans[v[i]], an);
					}
				}
			} else {
				if (v[i] % 2) {
					right_odd.pop_front();
					if (!left_odd.empty()) {
						int tmp1 = left_odd[0];
						an = min(an, ((abs(tmp1 - v[i])) / 2));
						if (ans[tmp1] == 0)ans[tmp1] = an;
						else ans[tmp1] = min(ans[tmp1], an);
					}
					if (!right_odd.empty()) {
						int tmp2 = right_odd.back();
						int tm = m - tmp2 + v[i] + ((tmp2 - v[i]) / 2);
						an = min(an, tm);
						if (ans[tmp2] == 0)ans[tmp2] = an;
						else ans[tmp2] = min(ans[tmp2], an);
					}
					if (ans[v[i]] == 0)ans[v[i]] = an;
					else ans[v[i]] = min(ans[v[i]], an);
				} else {
					right_even.pop_front();
					if (!left_even.empty()) {
						int tmp1 = left_even[0];
						an = min(an, ((abs(tmp1 - v[i])) / 2));
						if (ans[tmp1] == 0)ans[tmp1] = an;
						else ans[tmp1] = min(ans[tmp1], an);
					}
					if (!right_even.empty()) {
						int tmp2 = right_even.back();
						int tm = m - tmp2 + v[i] + ((tmp2 - v[i]) / 2);
						an = min(an, tm);
						if (ans[tmp2] == 0)ans[tmp2] = an;
						else ans[tmp2] = min(ans[tmp2], an);
					}
					if (ans[v[i]] == 0)ans[v[i]] = an;
					else ans[v[i]] = min(ans[v[i]], an);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (ans[v[pos[cop[i]]]] == 0 || ans[v[pos[cop[i]]]] == INT_MAX)cout << "-1 ";
			else cout << ans[v[pos[cop[i]]]] << " ";
		}
		cout << en;
	}
	return 0;
}