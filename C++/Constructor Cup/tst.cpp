#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int num = 5;
	cout << __builtin_popcount(~num) << '\n';
	return 0;
}