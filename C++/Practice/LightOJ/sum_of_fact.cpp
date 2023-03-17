#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	vector<long long> fact(25, 1);
	for (long long i = 1; i < 21; i++) {
		fact[i] = fact[i - 1] * i;
	}
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";
		long long n;
		cin >> n;
		vector<long long> ans;
		for (long long i = 20; i >= 0; i--) {
			if (fact[i] <= n) {
				n -= fact[i];
				ans.push_back(i);
			}
		}
		sort(ans.begin(), ans.end());
		if (n != 0) {
			cout << "impossible\n";
			continue;
		}
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "!";
			if (i < ans.size() - 1)cout << "+";
		}
		cout << "\n";
	}
	return 0;
}