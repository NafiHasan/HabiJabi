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
		vector<long long> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		int cnt = 0;
		// long long sum = 0, x = 0;
		for (int i = 0 ; i < n - 1; i++) {
			if (a[i] % 2 == 1)cnt++;
		}
		// if (sum % 2 == 0 && ok )cout << "Chef\n";
		// else if (!ok && sum % 2 == 1)cout << "Chef\n";
		// else cout << "Cook\n";
		if (cnt == 1)cout << "Chef\n";
		else if (cnt % 2 == 0 && cnt != 0)cout << "Chef\n";
		else cout << "Cook\n";
	}
	return 0;
}