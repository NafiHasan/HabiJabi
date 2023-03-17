#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	vector<bool> marked(20000000, 1);
	// marked[2] = 0;
	for (int i = 2; i * i <= 20000000; i++) {
		if (marked[i]) {
			for (int j = i + i; j < 20000000; j += i)marked[j] = 0;
		}
	}
	return 0;
}