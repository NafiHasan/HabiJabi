#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		int all = 0; int no = 0; int pro = 0; int eng = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0' && s[i] == t[i]) no++;
			else if (s[i] == '1' && s[i] == t[i])all++;
			else if (s[i] == '1' && s[i] != t[i])pro++;
			else if (t[i] == '1' && s[i] != t[i])eng++;
		}
		int ans = 0;
		// no with all
		int tmp = min(no, all);
		ans += tmp;
		no -= tmp; all -= tmp;

		// prog with engl
		tmp = min(eng, pro);
		ans += tmp;
		eng -= tmp; pro -= tmp;
		// rem pro and eng with all
		tmp = min(max(eng, pro), all);
		ans += tmp;
		all -= tmp;

		ans += all / 2;
		cout << ans << '\n';
	}
	return 0;
}