#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool pal(long long n) {
	string s = to_string(n);
	string t = s;
	reverse(t.begin(), t.end());
	if (s == t)return 1;
	else return 0;
}



int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		long long n;
		cin >> n;
		int cnt = 0;
		for (long long i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				long long a = n / i;
				if (pal(a))cnt++;
				if (a != i && pal(i))cnt++;
			}
		}
		cout << "Case #" << cs << ": " << cnt << "\n";
	}
	return 0;
}