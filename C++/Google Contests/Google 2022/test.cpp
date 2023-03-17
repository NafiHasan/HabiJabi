#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	multiset<int> s;
	s.insert(2);
	s.insert(2);
	s.insert(2);
	s.erase(2);
	cout << s.size() << '\n';
	return 0;
}