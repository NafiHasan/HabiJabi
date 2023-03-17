#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int n;
	cin >> n;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	cout << s << '\n';
	return 0;
}