#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	multiset<int> a;
	a.insert(1);
	a.insert(1);
	a.insert(1);
	a.insert(2);
	a.erase(a.find(1));
	cout << *a.begin()  << ' ' << *a.end() << "\n";
	return 0;
}