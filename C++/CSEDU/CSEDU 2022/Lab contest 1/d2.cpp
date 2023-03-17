#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<vector<int>> facts;
vector<int> all;

void fact_gen(int cur, int n, int mul, vector<int> temp) {
	if (cur >= all.size() || mul > n) {
		return;
	}

	if (mul == n) {
		facts.push_back(temp);
		return;
	}
	temp.push_back(all[cur]);

	temp.pop_back();
	fact_gen(cur + 1, n, mul, temp);
}

int main() {
	fast_io();
	while (1) {
		int n;
		cin >> n;
		facts.clear();
		all.clear();
		if (n == 0)break;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				all.push_back(i);
				all.push_back(n / i);
				cout << i << ' ' << n / i << '\n';
			}
		}
		vector<int> temp;
		fact_gen(0, n, 1, temp);
		cout << facts.size() << '\n';
		for (int i = 0; i < facts.size(); i++) {
			for (int j = 0; j < facts[i].size(); j++)
				cout << facts[i][j] << " ";
			cout << "\n";
		}
	}
	return 0;
}
