#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void f(int a[], int n) {
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i < n; i++)a[i] = a[i - 1] + a[i - 2];
}


int main() {
	fast_io();
	int n ;
	n = 10;
	int dp[n];
	// int ara[4];
	memset(dp, 0 , sizeof(dp));
	f(dp, n);
	for (int i = 0 ; i < n; i++)cout << dp[i] << '\n';
	bool a = false;
	cout << a << '\n';

	return 0;
}