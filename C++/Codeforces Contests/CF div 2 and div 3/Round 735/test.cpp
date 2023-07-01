#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int a[] = {5 , 2, 1 , 4 , 3, 6};
	sort(a, a + 6);
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++)if (i != j)cout << a[i] << " " << a[j] << " " << (a[i] | a[j]) << "\n";
	}
	return 0;
}