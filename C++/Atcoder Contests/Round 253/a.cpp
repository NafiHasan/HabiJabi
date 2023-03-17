#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	vector<int> a(3), b(3);
	for (int i = 0 ; i < 3; i++)cin >> a[i];
	b = a;
	sort(a.begin(), a.end());
	if (a[1] == b[1])cout << "Yes\n";
	else cout << "No\n";
	return 0;
}