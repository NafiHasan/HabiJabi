#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long n, k;
		cin >> n >> k;
		vector<char> av(2);
		string s = to_string(n);
		// cout << s << "\n";
		av[0] = av[1] = s[0];
		int got = 1, cnt0 = 0, cnt1 = 0, start = 0;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] != av[0] && k == 1) {
				if (s[i] > av[0])cnt0++;
				start = i;
				break;
			} else if (s[i] != av[0] && got < k) {
				got++;
				av[1] = s[i];
			} else if (s[i] != av[0] && s[i] != av[1] && got >= k) {
				if (s[i] > av[1])cnt1++;
				start = i;
				break;
			}
			start = i;
		}
		sort(av.begin(), av.end());
		for (int i = start; i < s.size(); i++) {
			s[i] = av[1] ;
		}
		// string t = s.substr(0, start);
		// // cout << t << "\n";
		// for (int i = start - 1 ; i >= 0; i--) {
		// 	if (t[i] == av[1]) {
		// 		t[i]++;
		// 	}
		// }
		// string t2 = s.substr(0, start);
		// for (int i = start - 1; i >= 0; i--) {
		// 	if (t2[i] == av[0]) {
		// 		t2[i] = av[1];
		// 		break;
		// 	}
		// }
		// if (t > t2) {
		// 	t = t2;
		// }
		// for (int i = 0; i <= start; i++) {
		// 	s[i] = t[i];
		// }
		if (cnt1 > 0 || cnt0 > 0) {
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == av[1] && s[i] < '9')s[i]++;
			}
			if (av[1] < '9')av[1]++;
			if (cnt0 > 0 && av[0] < '9')av[0]++;
		}
		string t3 = s;
		for (int i = t3.size() - 1; i >= 0; i--) {
			if (t3[i] == av[1]) {
				t3[i] = av[0];
				long long num = stoll(t3);
				// cout << num << "\n";
				if (num >= n) {
					s = t3;
				} else t3[i] = av[1];
			}
		}
		long long ans = stoll(s);
		cout << ans << '\n';
	}
	return 0;
}