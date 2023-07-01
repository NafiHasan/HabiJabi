#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		long long n;
		cin >> n;
		n--;
		cout << (1LL << n) << '\n';
	}
	return 0;
}