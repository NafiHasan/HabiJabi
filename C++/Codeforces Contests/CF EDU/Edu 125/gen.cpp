#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	cout << "1\n";
	int n = 400000;
	cout << n << '\n';
	for (int i = 0; i < 100000; i++) {
		cout << "(";
	}
	for (int i = 0; i < 100000; i++) {
		cout << ")";
	}
	cout << ")";
	for (int i = 0; i < 100000 - 1; i++) {
		cout << "(";
	}
	// cout << ")";
	for (int i = 0; i < 100000; i++) {
		cout << "(";
	}
	cout << "\n";
	return 0;
}