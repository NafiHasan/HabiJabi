#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

long long div(long long l, long long r, long long d) {
	return (r / d - (l - 1LL) / d);
}


long long cnt(long long num) {
	if (num == 0)return 0;
	long long rt = sqrtl(num);
	long long ans = (rt - 1) * 3;
	ans += div(rt * rt, num, rt);
	return ans;
}



int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		long long a, b;
		cin >> a >> b;
		long long ans = cnt(b) - cnt(a - 1);
		cout << ans << '\n';
	}
	return 0;
}