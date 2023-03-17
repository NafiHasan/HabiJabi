#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(5);
	s.erase(2);
	cout << *s.lower_bound(10) << '\n';
	return 0;
}