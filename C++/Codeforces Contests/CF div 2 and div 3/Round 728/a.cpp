#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		if (n == 2) {
			cout << 2 << " " << 1 << "\n";
			continue;
		}
		if (n % 2 == 0) {
			for (int i = 0; i < n ; i += 2) {
				cout << i + 2 << " " << i + 1 << " ";
			}
			cout << "\n";
			continue;
		}
		for (int i = 0; i < (n - 3); i += 2) {
			cout << i + 2 << " " << i + 1 << " ";
		}
		cout << n - 1 << " " << n << " " << n - 2 << "\n";
	}

	return 0;
}