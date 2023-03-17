#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 2000010;

vector<int> smol(N);
vector<vector<int>> all;

vector<int> fac(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {

		}
	}
}


void sieve() {
	smol[1] = 1;
	for (int i = 2; i < N; i++) {
		smol[i] = i;
		if (i % 2 == 0)smol[i] = 2;
	}

	for (int i = 3; i * i < N; i++) {
		if (smol[i] == i) {
			for (int j = i * i; j < N; j += i) {
				if (smol[j] == j) smol[j] = i;
			}
		}
	}
}

vector<int> factorize(int k) {
	vector<int> ans;
	while (k != 1) {
		ans.push_back(smol[k]);
		k = k / smol[k];
	}
	return ans;
}

int main() {
	sieve();
	fast_io();
	while (1) {
		int n;
		cin >> n;
		if (n == 0)break;
		vector<int> pd;
		pd = factorize(n);
		if (pd.size() == 1) {
			cout << "0\n";
			continue;
		}
		int mask = 0;
		vector<vector<int>> ans;
		int all = pd.size() + 1;

		// cout << (1 << 3) << "\n";
		for (int i = 1; i <= (1 << all); i++) {
			vector<int> tmp;
			int mul = 1;
			if (__builtin_popcount(i) == 1)continue;
			for (int j = 0; j < 25; j++) {
				if (((1 << j) & i) != 0 && j < pd.size())mul *= pd[j];
				else if (((1 << j) & i) == 0 && j < pd.size())tmp.push_back(pd[j]);

			}
			if (i == 28) {
				cout << mul << '\n';
			}
			tmp.push_back(mul);
			sort(tmp.begin(), tmp.end());
			if (tmp.size() > 1)ans.push_back(tmp);
		}
		sort(ans.begin(), ans.end());
		vector<vector<int>> final;
		for (int i = 0; i < ans.size(); i++) {
			if (i && ans[i] == ans[i - 1])continue;
			final.push_back(ans[i]);
		}
		cout << final.size() << '\n';
		for (int i = 0; i < final.size(); i++) {
			for (int j = 0; j < final[i].size(); j++)cout << final[i][j] << ' ';
			cout << "\n";
		}
	}
	return 0;
}