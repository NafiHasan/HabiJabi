#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n;
	cin >> n;
	queue<string> q;
	vector<long long> a;
	q.push("4");
	q.push("7");
	while (1) {
		string t = q.front();
		q.pop();
		if (t.size() > n)break;
		a.push_back(stoll(t));
		q.push(t + "4");
		q.push(t + "7");
	}
	for (int i = 0; i < a.size(); i++)cout << a[i] << '\n';
	return 0;
}