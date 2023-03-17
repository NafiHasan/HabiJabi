#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 1000005;
string s, p;
int n, m;
vector<int> b(N, 0);
int cnt = 0;

void kmpProcess() {
	int i = 0, j = -1;
	b[0] = -1;
	while (i < m) {
		while (j >= 0 && p[i] != p[j])j = b[j];
		i++; j++;
		b[i] = j;
	}
}

vector<int> kmpSearch() {
	vector<int> ind;
	cnt = 0;
	int i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && s[i] != p[j])j = b[j];
		i++, j++;
		if (j == m) {
			ind.push_back(i - j);
			j = b[j];
		}
	}
	return ind;
}


int main() {
	FastIO;
	for (int cs = 1; ; cs++) {
		// if (cs > 1 && cs <= tc)cout << "\n";
		cin >> s;
		if (s == ".")break;
		n = s.size();
		kmpProcess();
		int ans = 1;
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				p = s.substr(0, i);
				m = p.size();
				kmpProcess();
				vector<int> ind = kmpSearch();
				bool ok = 1;
				for (int j = 0, k = 0; j < ind.size(); j++, k += i) {
					if (ind[j] != k) {
						ok = 0;
						break;
					}
				}
				if (ok && (int)ind.size() == n / i)ans = max(ans, n / i);
				if (i != n / i) {
					p = s.substr(0, n / i);
					m = p.size();
					kmpProcess();
					vector<int> ind = kmpSearch();
					bool ok = 1;
					for (int j = 0, k = 0; j < ind.size(); j++, k += n / i) {
						if (ind[j] != k) {
							ok = 0;
							break;
						}
					}
					if (ok && (int)ind.size() == i)ans = max(ans, i);
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}