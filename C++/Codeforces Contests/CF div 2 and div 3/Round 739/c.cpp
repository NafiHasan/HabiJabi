#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long k;
		cin >> k;
		long long box = sqrt(k);
		if (box * box == k) {
			cout << box << " 1\n";
			continue;
		}
		long long start = box * box + 1;
		if (box * box < k)box++;
		long long end = box * box;
		long long row = 1, col = box;
		if (k > start + box - 1) {
			row = box;
			col = end - k + 1;
		} else {
			row = k - start + 1;
		}
		cout << row << " " << col << '\n';
	}
	return 0;
}