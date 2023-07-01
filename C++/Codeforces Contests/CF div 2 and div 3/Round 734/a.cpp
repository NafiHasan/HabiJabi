#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long n;
		cin >> n;
		long long one = n / 3, two = n / 3;
		if (n % 3 == 1)one++;
		else if (n % 3 == 2)two++;
		cout << one << " " << two << "\n";
	}
	return 0;
}