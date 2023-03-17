#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	priority_queue<int, vector<int>> p;
	p.push(4);
	p.push(6);
	cout << p.top() << '\n';
	return 0;
}