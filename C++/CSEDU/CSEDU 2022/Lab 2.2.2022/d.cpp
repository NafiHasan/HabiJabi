#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)



bool comp(vector<vector<string>> v0, vector<vector<string>> v1) {
	if (v0[1] < v1[1])return true;
	else if (v0[1] > v1[1])return false;
	else {
		if (v0[0] < v0[0])return true;
		else if (v0[0] > v0[0])return false;
		else {
			return v0[2] < v1[2];
		}
	}
}


int main() {
	fast_io();
	int n;
	cin >> n;
	vector<vector<string>> v(n, vector<string>(3));
	for (int i = 0; i < n; i++) {
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; i++) {
		cout << v[i][0] << ' ' << v[i][1] << ' ' << v[i][2] << '\n';
	}
	return 0;
}