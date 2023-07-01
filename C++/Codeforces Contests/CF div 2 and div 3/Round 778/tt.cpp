#include <bits/stdc++.h>
using namespace std;

int main() {
	double N;
	cin >> N;
	double sum = 0;
	double num = 3, denom = 6;
	double increase = 5;
	for (int i = 1; i <= N; i++) {
		if (i > 1) cout << " + ";
		cout << num << "/" << denom;
		sum = sum + (num / denom);
		num = num + increase;
		denom = denom + increase;
		increase = increase + 2;
	}

	cout << " = " << sum << '\n';
	return 0;
}