#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	string s;
	cin >> s;
	long long cntb = 0, cnts = 0, cntc = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'B')cntb++;
		else if (s[i] == 'C')cntc++;
		else cnts++;
	}
	long long nb , ns, nc, pb, ps, pc;
	cin >> nb >> ns >> nc >> pb >> ps >> pc;
	long long ans = 0, p;
	cin >> p;
	long long lo = 0, hi = 1e15, mid;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		long long needb = max(0LL, mid * cntb - nb), needs = max(0LL, mid * cnts - ns), needc = max(0LL, mid * cntc - nc);
		long long total = needb * pb + needs * ps + needc * pc;
		if (total <= p) {
			ans = mid;
			lo = mid + 1;
		} else hi = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}