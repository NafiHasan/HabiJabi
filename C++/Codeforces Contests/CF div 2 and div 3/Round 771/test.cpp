#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.erase(s.find(3));
	s.erase(s.find(2));
	auto it = s.end();
	it--;
	cout << *it << ' ';
	return 0;
}