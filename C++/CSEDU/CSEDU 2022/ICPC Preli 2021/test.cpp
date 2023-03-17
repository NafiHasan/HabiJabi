#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int n;
	n = 1000000000;
	int cnt = 0;
	for (int i = 1; i <= n; i++)cnt++;
	cout << cnt << '\n';
	return 0;
}